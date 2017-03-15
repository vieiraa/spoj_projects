#include <stdio.h>
#include <stdlib.h>
//#include <stdint.h>

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
    list_t list[20];
    uint64_t key[2], prev[2], next[2], keyTmp, prevTmp, nextTmp;
    int size = 2, flag = 1;

    for (int i = 0; i < 2; i++) {
        scanf(" %llx %llx %llx", &key[i], &prev[i], &next[i]);

        list[i].key = key[i];
        list[i].prev = prev[i];
        list[i].next = next[i];
    }

    while (scanf(" %llx %llx %llx", &keyTmp, &prevTmp, &nextTmp) == 3) {
        list[size].key = keyTmp;
        list[size].prev = prevTmp;
        list[size].next = nextTmp;

        size++;
    }

    keyTmp = key[0];

    do {
        if (!keyTmp) {
            flag = 0;
            break;
        }

        int i = search(list, size, keyTmp);

        list_t aux1 = list[i];

        i = search(list, size, aux1.next);

        list_t aux2 = list[i];

        if (keyTmp == aux2.prev) {
            keyTmp = aux1.next;
        }
        else {
            flag = 0;
            break;
        }
    } while (keyTmp != key[1]);

    if (flag)
        printf("sana\n");
    else
        printf("insana\n");

    return 0;
}
