#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t *bst_t;

long counter;

void create(bst_t *);
int insert(bst_t *, int);

int main() {
    int n, data;
    bst_t tree;

    create(&tree);

    scanf(" %d", &n);

    while (n--) {
        scanf(" %d", &data);

        insert(&tree, data);

        printf("%d\n", counter);
    }

    return 0;
}

void create(bst_t *tree) {
    *tree = NULL;
}

int insert(bst_t *tree, int data) {
    bst_t newNode;

    if (!(*tree)) {
        newNode = (bst_t) malloc(sizeof(node_t));
        if (!newNode)
            return 0;

        newNode->data = data;
        //newNode->left = newNode->right = NULL;
        *tree = newNode;

        return 1;
    }

    else if (data > (*tree)->data) {
        counter++;
        return insert(&(*tree)->right, data);
    }

    else if (data < (*tree)->data) {
        counter++;
        return insert(&(*tree)->left, data);
    }
}
