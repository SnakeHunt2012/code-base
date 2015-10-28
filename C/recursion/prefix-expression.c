#include <stdio.h>

static char *expression;
static int index = 0;

int eval(char *expression)
{
    int x = 0;
    while (expression[index] == ' ') ++index;
    
    if (expression[index] == '+') {
        ++index;
        return eval(expression) + eval(expression);
    }
    
    if (expression[index] == '-') {
        ++index;
        return eval(expression) - eval(expression);
    }
    
    while (expression[index] >= '0' && expression[index] <= '9')
        x = 10 * x + (expression[index++] - '0');
    return x;
}

main(int argc, char *argv[])
{
    expression = "- + 1 1 + 2 2";
    printf("%s = %d\n", expression, eval(expression));
}
