#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *expression = argv[1];
    int i, N = strlen(expression);
    stack_init(N);
    for (i = 0; i < N; ++i) {
        if (expression[i] == '+')
            stack_push(stack_pop() + stack_pop());
        if (expression[i] == '*')
            stack_push(stack_pop() * stack_pop());
        if (expression[i] >= '0' && expression[i] <= '9')
            stack_push(0);
        while (expression[i] >= '0' && expression[i] <= '9')
            stack_push(10 * stack_pop() + expression[i++] - '0');
    }
    printf("%d \n", stack_pop());
}
