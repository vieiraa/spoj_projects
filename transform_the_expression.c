#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char data[MAX];
    int top;
} stack_t;

void create(stack_t *);
void push(stack_t *, char);
char pop(stack_t *);

int main() {
    stack_t stack;
    int t, i;
    char op[MAX], result[MAX], curChar;

    create(&stack);

    scanf(" %d", &t);

    while (t--) {
        scanf(" %s", op);

        int j = 0;

        for (int i = 0; i < strlen(op); i++) {
            curChar = op[i];

            if (curChar == '(')
                continue;

            switch (curChar) {
                case '^':
                case '/':
                case '*':
                case '-':
                case '+':
                    push(&stack, curChar);
                    break;

                case ')':
                    result[j++] = pop(&stack);
                    result[j] = '\0';
                    break;

                default:
                    result[j++] = curChar;
                    break;
            }
        }

        printf("%s\n", result);
    }

    return 0;
}

void create(stack_t *stack) {
    stack->top = -1;
}

void push(stack_t *stack, char c) {
    stack->data[stack->top + 1] = c;
    stack->top++;
}

char pop(stack_t *stack) {
    char c = stack->data[stack->top];
    stack->top--;

    return c;
}
