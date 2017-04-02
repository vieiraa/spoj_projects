#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node_t;

typedef struct node note_t;

typedef struct {
    note_t *back;
    node_t *front;
    bool reverse;
    int size;
} queue_t;

void create(queue_t *);
int push(queue_t *, int);
int pushBack(queue_t *, int);
int pop(queue_t *);
int pop_back(queue_t *);
int toFront(queue_t *, int, bool);
int push_back(queue_t *, int, bool);
int front(queue_t *, bool);
int back(queue_t *, bool);
void reverse(queue_t *, bool *);
void destroy(queue_t *);

int main() {
    queue_t queue;
    char op[20];
    int n, t;
    bool rev = false;

    create(&queue);

    scanf(" %d", &t);

    while (t--) {
        scanf(" %s", op);

        if (!strcmp(op, "back"))
            back(&queue, rev);

        else if (!strcmp(op, "front"))
            front(&queue, rev);

        else if (!strcmp(op, "reverse"))
            reverse(&queue, &rev);

        else if (!strcmp(op, "push_back")) {
            scanf(" %d", &n);
            push_back(&queue, n, rev);
        }

        else if (!strcmp(op, "toFront")) {
            scanf(" %d", &n);
            toFront(&queue, n, rev);
        }
    }

    destroy(&queue);

    return 0;
}

void create(queue_t *queue) {
    queue->front = NULL;
    queue->back = NULL;
    queue->reverse = false;
    queue->size = 0;
}

int push(queue_t *queue, int data) {
    node_t *new, *aux = queue->front;

    new = (node_t *) malloc(sizeof(node_t));
    new->data = data;

    if (!(queue->size)) {
        new->next = NULL;
        new->prev = NULL;
        queue->back = new;
        queue->front = new;
        queue->size++;

        return 1;
    }

    new->prev = NULL;
    new->next = aux;
    aux->prev = new;
    queue->front = new;
    (queue->size)++;

    return 1;
}

int pushBack(queue_t *queue, int data) {
    node_t *new, *aux = queue->back;

    new = (node_t *) malloc(sizeof(node_t));
    new->data = data;

    if (!(queue->size)) {
        new->next = NULL;
        new->prev = NULL;
        queue->back = new;
        queue->front = new;
        queue->size++;

        return 1;
    }

    new->prev = aux;
    new->next = NULL;
    aux->next = new;
    queue->back = new;
    (queue->size)++;

    return 1;
}

int toFront(queue_t *queue, int data, bool rev) {
    if (rev)
        return pushBack(queue, data);
    else
        return push(queue, data);
}

int push_back(queue_t *queue, int data, bool rev) {
    if (!rev)
        return pushBack(queue, data);
    else
        return push(queue, data);
}

int pop(queue_t *queue) {
    if (!(queue->size)) {
        printf("No job for Ada?\n");
        return 0;
    }

    node_t *p = queue->front;

    printf("%d\n", p->data);

    if (queue->size == 1) {
        queue->front = queue->back = NULL;
    }

    else
        queue->front = p->next;

    queue->size--;
    free(p);

    return 1;
}

int pop_back(queue_t *queue) {
    if (!(queue->size)) {
        printf("No job for Ada?\n");
        return 0;
    }

    node_t *p = queue->back;

    printf("%d\n", p->data);

    if (queue->size == 1) {
        queue->front = NULL;
        queue->back = NULL;
    }

    else
        queue->back = p->prev;

    queue->size--;
    free(p);

    return 1;
}

int front(queue_t *queue, bool rev) {
    if (rev) {
        return pop_back(queue);
    }

    else {
        return pop(queue);
    }
}

int back(queue_t *queue, bool rev) {
    if (!rev)
        return pop_back(queue);

    else
        return pop(queue);
}

void reverse(queue_t *queue, bool *rev) {
    *rev = !(*rev);

    queue->reverse = *rev;
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

