#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long uint64_t;

typedef struct node {
    uint64_t key;
    uint64_t prev;
    uint64_t next;
} node_t;

int search(node_t list[], int size, uint64_t key) {
    int i;

    for (i = 0; i < size; i++)
        if (list[i].key == key)
            return i;

    return 0;
}

int main() {
    node_t *list = (node_t *) malloc(sizeof(node_t));
    uint64_t key, prev, next;
    node_t ptr1, ptr2;
    int size = 0, flag = 1;

    while (scanf(" %llx %llx %llx", &key, &prev, &next) == 3) {
        size++;
        list = (node_t *) realloc(list, size * sizeof(node_t));

        list[size - 1].key = key;
        list[size - 1].prev = prev;
        list[size - 1].next = next;

        if (size == 1)
            ptr1 = list[size - 1];
        else if (size == 2)
            ptr2 = list[size - 1];
    }

    key = ptr1.key;

    do {
        int i = search(list, size, key);

        node_t aux1 = list[i];

        i = search(list, size, aux1.next);

        node_t aux2 = list[i];

        if (key == aux2.prev) {
            key = aux1.next;
        }
        else {
            flag = 0;
            break;
        }
    } while (key != ptr2.key);

    if (flag)
        printf("sana\n");
    else
        printf("insana\n");

    free(list);

    return 0;
}
