#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node_t;

typedef struct node note_t;

typedef struct {
    note_t *tail;
    node_t *head;
    int size;
} list_t;

void create(list_t *);
int insert(list_t *, int, int);
int del(list_t *, int);
void print(list_t);
void printBackwards(list_t);
void destroy(list_t *);

int main() {
    list_t list;

    create(&list);

    insert(&list, 0, 1);
    print(list);
    insert(&list, 0, 2);
    print(list);
    insert(&list, 0, 3);
    print(list);
    insert(&list, 5, 4);
    print(list);
    insert(&list, 1, 5);
    insert(&list, 3, 6);
    print(list);
    del(&list, 4);
    print(list);
    printBackwards(list);

    destroy(&list);

    return 0;
}

void create(list_t *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int insert(list_t *list, int pos, int data) {
    node_t *new, *aux = list->head;

    new = (node_t *) malloc(sizeof(node_t));

    if (!new)
        return 0;

    new->data = data;

    if (!aux && !pos) {
        new->prev = NULL;
        new->next = NULL;
        list->head = new;
        list->tail = new;
    }

    else if (aux && !pos) {
        new->prev = NULL;
        new->next = aux;
        aux->prev = new;
        list->head = new;

        aux = list->head;

        for (int i = 0; i < list->size; i++) {
            aux = aux->next;
        }

        list->tail = aux;
    }

    else if (pos >= list->size) {
        aux = list->tail;

        new->prev = aux;
        new->next = NULL;
        aux->next = new;
        list->tail = new;
    }


    else if (pos > (list->size / 2) + 1) {
        aux = list->tail;

         for(int i = list->size; i > pos - 1; i--) {
            aux = aux->prev;
        }

        new->prev = aux->prev;
        aux->prev->next = new;
        aux->next = new;
        new->next = aux;
    }

    else {
        for(int i = 0; i < pos - 1; i++)
            aux = aux->next;

        new->next = aux->next;
        aux->next->prev = new;
        aux->next = new;
        new->prev = aux;
    }

    list->size++;

    return 1;
}

int del(list_t *list, int pos) {
    node_t *p = list->head, *aux;

    if (pos > (list->size - 1) || p == NULL)
        return 0;

    else {
        if (!pos) {
            list->head = p->next;
        }

        else if (list->size == 1 && !pos) {
            list->head = NULL;
            list->tail = NULL;
        }

        else if (pos == list->size - 1){
            p = list->tail;
            list->tail = p->prev;
        }

        else if (pos >= ((list->size) / 2) + 1){
            p = list->tail;
            for (int i = list->size; i > pos; i--) {
                aux = p;
                p = p->prev;
            }

            aux->prev = p->prev;
        }

        else {
            for (int i = 0; i < pos; i++) {
                aux = p;
                p = p->next;
            }

            aux->next = p->next;
        }
    }

    list->size--;
    free(p);

    return 1;
}

void print(list_t list) {
    node_t *p = list.head;

    if (!p) {
        printf("empty\n");
        return;
    }

    for (int i = 0; i < list.size; i++) {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}

void printBackwards(list_t list) {
    node_t *p = list.tail;

    if (!p) {
        printf("empty!");
        return;
    }

    for (int i = list.size; i > 0; i--) {
        printf("%d ", p->data);
        p = p->prev;
    }

    printf("\n");
}

void destroy(list_t *list) {
    node_t *p1 = list->head, *p2;

    if (!p1)
        return;

    for (int i = 0; i < list->size; i++) {
        p2 = p1;
        p1 = p1->next;
        free(p2);
    }
}
