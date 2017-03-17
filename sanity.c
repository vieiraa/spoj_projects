#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long uint64_t;

typedef struct {
    uint64_t key;
    uint64_t prev;
    uint64_t next;
} list_t;

int search(list_t list[], int size, uint64_t key) {
    int i;

    for (i = 0; i < size; i++)
        if (list[i].key == key)
            return i;

    return 0;
}

int main() {
    list_t *list = (list_t *) malloc(sizeof(list_t));
    uint64_t keyTmp, prevTmp, nextTmp, ptr1, ptr2;
    int size = 0, flag = 1;
    list_t aux1;
    int i = 0;

    while (scanf(" %llx %llx %llx", &keyTmp, &prevTmp, &nextTmp) == 3) {
        size++;
        list = (list_t *) realloc(list, size * sizeof(list_t));

        list[size-1].key = keyTmp;
        list[size-1].prev = prevTmp;
        list[size-1].next = nextTmp;
    }

    ptr1 = list[0].key;
    ptr2 = list[1].key;

    keyTmp = ptr1;

    do {
        aux1 = list[i];

        i = search(list, size, aux1.next);

        if (aux1.next == list[i].key && list[i].prev == aux1.key) {
            keyTmp = aux1.next;
        }
        else {
            flag = 0;
            break;
        }
    } while (keyTmp != ptr2);

    if (flag)
        printf("sana\n");
    else
        printf("insana\n");

    return 0;
}
