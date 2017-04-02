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
    char op[MAX], str[MAX], cur;

    create(&stack);

    scanf(" %d", &t);

    while (t--) {
        scanf(" %s", op);

        int j = 0;

        for (int i = 0; i < strlen(op); i++) {
            cur = op[i];

            if (cur == '(')
                continue;

            switch (cur) {
                case '^':
                case '/':
                case '*':
                case '-':
                case '+':
                    push(&stack, cur);
                    break;

                case ')':
                    str[j++] = pop(&stack);
                    str[j] = '\0';
                    break;

                default:
                    str[j++] = cur;
                    break;
            }
        }

        printf("%s\n", str);
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
