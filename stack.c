#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "line.h"
#define MAX 10

struct stack
{
    int top;
    int data[MAX];
};

struct stack *createStack(int size)
{
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    stack->top = -1;
    printf("\nStack created !\n");
    return stack;
}
void push(struct stack *stack, char ch)
{
    if (stack->top == MAX - 1)
    {
        printf("Stack overflow !\n");
    }
    else
    {
        stack->top++;
        stack->data[stack->top] = ch;
        line();
        printf("\n");
        printf("%d pushed !\n", ch);
    }
}
char pop(struct stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack underflow !\n");
    }
    else
    {
        int tmp = stack->data[stack->top];
        stack->top--;
        printf("%d popped !\n", tmp);
        return tmp;
    }
}
void display(struct stack *stack)
{

    printf("\n");
    for (int i = stack->top; i >= 0; i--)
    {
        printf("    |  %d  |\n", stack->data[i]);
    }
}
/*

0 to 41
42 to 43 cont
44 to 44
45 to 45 cont 
46 to 46
47 to 57 cont
58 to 92
93 to 93 cont
94 to 255

*/
void main()
{
    char post[10] = "";
    int flag = 0;
    line();
    printf("\n");
    printf("Enter a valid postfix expression : ");
    gets(post);
    line();
    struct stack *stack = createStack(strlen(post));
    for (int i = 0; post[i]; i++)
    {
        if (!(post[i] >= '0' && post[i] <= '9' || post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/' || post[i] == '^'))
        {
            line();
            printf("\nInvalid expression.\n");
            line();
            exit(0);
        }
        else
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        for (int i = 0; post[i]; i++)
        {
            if (post[i] >= '0' && post[i] <= '9')
            {
                push(stack, post[i] - '0');
            }
            else
            {
                line();
                printf("\n");
                int op1 = pop(stack);
                line();
                printf("\n");
                int op2 = pop(stack);
                line();
                switch (post[i])
                {
                case '+':
                    printf("\n%d + %d = %d\n", op2, op1, op2 + op1);
                    push(stack, op2 + op1);
                    break;
                case '-':
                    printf("\n%d - %d = %d\n", op2, op1, op2 - op1);
                    push(stack, op2 - op1);
                    break;
                case '*':
                    printf("\n%d * %d = %d\n", op2, op1, op2 * op1);
                    push(stack, op2 * op1);
                    break;
                case '/':
                    printf("\n%d / %d = %d\n", op2, op1, op2 / op1);
                    push(stack, op2 / op1);
                    break;
                case '^':
                    printf("\n%d ^ %d = %.1lf\n", op2, op1, pow(op2, op1));
                    push(stack, pow(op1, op2));
                    break;
                }
            }
        }
        line();
        printf("\n");
        int final = pop(stack);
        line();
        printf("\nANSWER = %d\n", final);
        line();
    }
}
