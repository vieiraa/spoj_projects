#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned long long uint64_t;

typedef struct node {
    uint64_t key;
    uint64_t prev;
    uint64_t next;
} node_t;

int main() {
    node_t *list = (node_t *) malloc(sizeof(node_t));
    uint64_t key, prev, next;
    node_t ptr1, ptr2, aux;
    int size = 0;
    bool flag;

    while (scanf(" %llx %llx %llx", &key, &prev, &next) == 3) {
        size++;
        list = (node_t *) realloc(list, size * sizeof(node_t));

        list[size - 1].key = key;
        list[size - 1].prev = prev;
        list[size - 1].next = next;
    }

    ptr1 = list[0];
    ptr2 = list[1];

    aux = ptr1;

    do {
        flag = false;

        for (int i = 0; i < size; i++) {
            if (aux.next == list[i].key && list[i].prev == aux.key) {
                flag = true;
                aux = list[i];
            }
        }

        if (!flag)
            break;
    } while (aux.key != ptr2.key);

    if (flag)
        printf("sana\n");
    else
        printf("insana\n");

    free(list);

    return 0;
}
