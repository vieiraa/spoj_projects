#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node_t;

typedef struct node note_t;

typedef struct {
    note_t *back;
    node_t *front;
    int size;
} queue_t;

void create(queue_t *);
int insert(queue_t *, int, int);
int del(queue_t *, int);
void print(queue_t);
void printDel(queue_t *, int);
void printBackwards(queue_t);
queue_t reverse(queue_t);
void destroy(queue_t *);

int main() {
    queue_t queue;
    char op[20];
    int n, t;

    create(&queue);

    scanf(" %d", &t);

    while (t--) {
        strcpy(op, "");
        scanf("%s", op);

        if (!strcmp(op, "back"))
            printDel(&queue, queue.size - 1);

        else if (!strcmp(op, "front"))
            printDel(&queue, 0);

        else if (!strcmp(op, "reverse"))
            queue = reverse(queue);

        else if (!strcmp(op, "push_back")) {
            scanf(" %d", &n);
            insert(&queue, queue.size, n);
        }

        else if (!strcmp(op, "toFront")) {
            scanf(" %d", &n);
            insert(&queue, 0, n);
        }
    }

    destroy(&queue);

    return 0;
}

void create(queue_t *queue) {
    queue->front = NULL;
    queue->back = NULL;
    queue->size = 0;
}

int insert(queue_t *queue, int pos, int data) {
    node_t *new, *aux = queue->front;

    new = (node_t *) malloc(sizeof(node_t));

    if (!new)
        return 0;

    new->data = data;

    if (!aux && !pos) {
        new->prev = NULL;
        new->next = NULL;
        queue->front = new;
        queue->back = new;
    }

    else if (aux && !pos) {
        new->prev = NULL;
        new->next = aux;
        aux->prev = new;
        queue->front = new;

        aux = queue->front;

        for (int i = 0; i < queue->size; i++) {
            aux = aux->next;
        }

        queue->back = aux;
    }

    else if (pos >= queue->size) {
        aux = queue->back;

        new->prev = aux;
        new->next = NULL;
        aux->next = new;
        queue->back = new;
    }


/*     else if (pos > (queue->size / 2) + 1) { */
/*         aux = queue->back; */

/*          for(int i = queue->size; i > pos - 1; i--) { */
/*             aux = aux->prev; */
/*         } */

/*         new->prev = aux->prev; */
/*         aux->prev->next = new; */
/*         aux->next = new; */
/*         new->next = aux; */
/*     } */

/*     else { */
/*         for(int i = 0; i < pos - 1; i++) */
/*             aux = aux->next; */

/*         new->next = aux->next; */
/*         aux->next->prev = new; */
/*         aux->next = new; */
/*         new->prev = aux; */
/*     } */

    queue->size++;

    return 1;
}

int del(queue_t *queue, int pos) {
    node_t *p = queue->front, *aux;

    if (pos > (queue->size - 1) || p == NULL)
        return 0;

    else {
        if (!pos) {
            queue->front = p->next;
        }

        else if (queue->size == 1 && !pos) {
            queue->front = NULL;
            queue->back = NULL;
        }

        else if (pos == queue->size - 1){
            p = queue->back;
            queue->back = p->prev;
        }

        /* else if (pos >= ((queue->size) / 2) + 1){ */
        /*     p = queue->back; */
        /*     for (int i = queue->size; i > pos; i--) { */
        /*         aux = p; */
        /*         p = p->prev; */
        /*     } */

        /*     aux->prev = p->prev; */
        /* } */

        /* else { */
        /*     for (int i = 0; i < pos; i++) { */
        /*         aux = p; */
        /*         p = p->next; */
        /*     } */

        /*     aux->next = p->next; */
        /* } */
    }

    queue->size--;
    free(p);

    return 1;
}

void print(queue_t queue) {
    node_t *p = queue.front;

    if (!p) {
        printf("empty\n");
        return;
    }

    for (int i = 0; i < queue.size; i++) {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}

void printDel(queue_t *queue, int pos) {
    node_t *p;

    if (!(queue->size)) {
        printf("No job for Ada?\n");
        return;
    }

    if (!pos)
        p = queue->front;
    else
        p = queue->back;

    printf("%d\n", p->data);

    del(queue, pos);
}

void printBackwards(queue_t queue) {
    node_t *p = queue.back;

    if (!p) {
        printf("empty!");
        return;
    }

    for (int i = queue.size; i > 0; i--) {
        printf("%d ", p->data);
        p = p->prev;
    }

    printf("\n");
}

queue_t reverse(queue_t queue) {
    queue_t rev;
    node_t *aux = queue.back;

    create(&rev);

    for (int i = queue.size, j = 0; i > 0; i--, j++) {
        insert(&rev, j, aux->data);
        aux = aux->prev;
    }

    destroy(&queue);
    return rev;
}

void destroy(queue_t *queue) {
    node_t *p1 = queue->front, *p2;

    if (!p1)
        return;

    for (int i = 0; i < queue->size; i++) {
        p2 = p1;
        p1 = p1->next;
        free(p2);
    }
}

