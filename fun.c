// Quick note: meu nick no SPOJ eh 'chavo'

#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) {
    int *aux;

    *aux = *a;
    *a = *b;
    *b = *aux;
}

// para exibir resultado em ordem crescente
void ordenaArray(int *arr, int tam) {
    int flag;

    do {
        for (int i = 0; i < tam; i++) {
            for (int j = i + 1; j < tam; j++) {
                flag = 0;

                if (arr[i] > arr[j]) {
                    troca(&arr[i], &arr[j]);
                    flag = 1;
                }
            }
        }
    } while (flag);
}

int main() {
    int tam1, tam2, flag = 0;
    int *arr1, *arr2;

    scanf(" %d", &tam1); // le numero de elementos do 1 array

    arr1 = (int *) malloc(tam1 * sizeof(int)); // aloca 1 array

    for (int i = 0; i < tam1; i++)
        scanf(" %d", &arr1[i]); // le elementos do 1 array

    ordenaArray(arr1, tam1);

    scanf(" %d", &tam2); // le numero de elementos do 2 array

    arr2 = (int *) malloc(tam2 * sizeof(int)); // aloca 2 array

    for (int i = 0; i < tam2; i++)
        scanf(" %d", &arr2[i]); // le elementos do 2 array

    ordenaArray(arr2, tam2);

    for (int i = 0; i < tam1; i++) { // verifica se elemento do arr1 nao esta contido em arr2
        for (int j = 0; j < tam2; j++) {
            if (arr1[i] != arr2[j])
                flag = 1;
            else {
                flag = 0;
                break;
            }
        }
        if (flag) // se nao estiver, exiba tal elemento
            printf("%d ", arr1[i]);
    }

    // liberando memoria
    free(arr1);
    free(arr2);

    return 0;
}

