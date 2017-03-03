#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct {
    node_t *head;
    int size;
} list_t;

void create(list_t *);
int insert(list_t *, int, int);
int del(list_t *, int);
void print(list_t);
void destroy(list_t *);

int main() {
    char operation;
    int index, value;
    list_t list;

    create(&list);

    while (1) {
        scanf(" %c", &operation);
        switch (operation) {
            case 'f':
                scanf(" %d", &value);
                insert(&list, 0, value);
                break;

            case 'i':
                scanf(" %d %d", &index, &value);
                insert(&list, index, value);
                break;

            case 'r':
                del(&list, 0);
                break;

            case 'd':
                scanf(" %d", &index);
                del(&list, index);
                break;

            case 'q':
                return 0;
        }

        print(list);
    }


    destroy(&list);

    return 0;
}

void create(list_t *list) {
    list->head = NULL;
    list->size = 0;
}

int insert(list_t *list, int pos, int data) {
    node_t *p, *aux = list->head;

    p = (node_t *) malloc(sizeof(node_t));

    if (!pos || (!aux && pos > list->size)){
        p->data = data;
        p->next = aux;
        list->head = p;
    }

    else if (pos >= list->size) {
        for (int i = 0; i < list->size - 1; i++)
            aux = aux->next;

        p->data = data;
        p->next = NULL;
        aux->next = p;
    }

    else {
        for(int i = 0; i < pos - 1; i++)
            aux = aux->next;

        p->data = data;
        p->next = aux->next;
        aux->next = p;
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

        else {
            for (int i = 0; i < pos; i++) {
                aux = p;
                p = p->next;
            }

            aux->next = p->next;
            //if (!p || !aux)
            //    printf("p ou aux ta nulo\n");
            //else if (!p->next)
            //    printf("p->next ta nulo\n");
        }

    }
    free(p);
    list->size--;

    return 1;
}

void print(list_t list) {
    node_t *p = list.head;

    if (!p) {
        printf("empty\n");
        return;
    }

    while (p) {
        printf("%d ", p->data);
        p = p->next;
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
