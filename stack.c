#include <stdio.h>
#include <stdlib.h>
#include "line.h"
#define MAX 50

struct stack
{
    int top;
    int data[MAX];
};

void init(struct stack *stack)
{
    stack->top = -1;
    line();
    printf("\nStack initialized.\n");
    line();
}
void display(struct stack *stack)
{
    line();
    if (stack->top == -1)
    {
        printf("\nStack is empty !\n");
        line();
    }
    else
    {
        printf("\nStack : \n\n");
        for (int i = stack->top; i >= 0; i--)
        {
            printf("    |  %d  |\n", stack->data[i]);
        }
        line();
    }
}

void push(struct stack *stack, int key)
{
    if (stack->top == MAX - 1)
    {
        printf("\nStack is full! You can't perform PUSH operation. \n");
        display(stack);
    }
    else
    {
        stack->top++;
        stack->data[stack->top] = key;
        line();
        printf("\n%d pushed into the stack.\n", key);
        line();
    }
}
int pop(struct stack *stack)
{
    if (stack->top == -1)
        printf("\nStack is empty! you can't perform POP operation.\n");
    else
    {
        int tmp = stack->data[stack->top];
        stack->top--;
        line();
        printf("\n%d Popped!\n", tmp);
        line();
        return tmp;
    }
}
int peep(struct stack *stack)
{
    if (stack->top == -1)
        printf("\nStack is empty! you can't perform PEEP operation.\n");
    else
    {
        int tmp = stack->data[stack->top];
        line();
        printf("\n%d Peeped!\n", tmp);
        line();
        return tmp;
    }
}
void change(struct stack *stack, int pos, int val)
{
    int i = stack->top - pos + 1;
    if (i >= 0 && i <= stack->top)
    {
        stack->data[i] = val;
        printf("\nValue changed !\n");
        line();
    }
    else
    {
        printf("\nInvalid position.\n");
    }
}

void main()
{
    int choice, data;
    int a, b, c, d;
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    init(stack);
    while (1)
    {
        printf("\n1.Push\n2.Pop\n3.Peep\n4.Change\n5.Display\n6.Exit\n");
        printf("\n\nEnter option : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            line();
            printf("\nEnter the data you want to push : ");
            scanf("%d", &data);
            push(stack, data);
            break;
        case 2:
            a = pop(stack);
            break;
        case 3:
            b = peep(stack);
            break;
        case 4:
            printf("\n");
            line();
            printf("\nEnter the position where you want to change the value : ");
            scanf("%d", &c);
            line();
            printf("\nEnter the value : ");
            scanf("%d", &d);
            line();
            change(stack, c, d);
            break;
        case 5:
            display(stack);
            break;
        case 6:
            line();
            printf("\nThanks for using! Have a great day :)\n");
            line();
            exit(0);
            break;
        default:
            line();
            printf("\nInvalid option.\n");
            line();
            break;
        }
    }
}

/*
#include <stdio.h>
#include <stdlib.h>
#include "line.h"
#define MAX 50

struct stack
{
    int top;
    int data[MAX];
};

void init(struct stack *stack)
{
    stack->top = -1;
    line();
    printf("\nStack initialized.\n");
    line();
}
void display(struct stack *stack)
{
    line();
    if (stack->top == -1)
    {
        printf("\nStack is empty !\n");
        line();
    }
    else
    {
        int i = stack->top;
        printf("\nStack : \n\n");
        for (i = stack->top; i >= 0; i--)
        {
            printf("    |  %d  |\n", stack->data[i]);
        }
        line();
    }
}

void push(struct stack *stack, int key)
{
    if (stack->top == MAX - 1)
    {
        printf("\nStack is full! You can't perform PUSH operation. \n");
        display(stack);
    }
    else
    {
        stack->top++;
        stack->data[stack->top] = key;
        line();
        printf("\n%d pushed into the stack.\n", key);
        line();
    }
}
int pop(struct stack *stack)
{
    if (stack->top == -1)
        printf("\nStack is empty! you can't perform POP operation.\n");
    else
    {
        int tmp = stack->data[stack->top];
        stack->top--;
        line();
        printf("\n%d Popped!\n", tmp);
        line();
        return tmp;
    }
}
int peep(struct stack *stack)
{
    if (stack->top == -1)
        printf("\nStack is empty! you can't perform PEEP operation.\n");
    else
    {
        int tmp = stack->data[stack->top];
        line();
        printf("\n%d Peeped!\n", tmp);
        line();
        return tmp;
    }
}
void change(struct stack *stack, int pos, int val)
{
    int i = stack->top - pos + 1;
    if (i >= 0 && i <= stack->top)
    {
        stack->data[i] = val;
        printf("\nValue changed !\n");
        line();
    }
    else
    {
        printf("\nInvalid position.\n");
    }
}
int priority(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        break;
    }
}
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isOperand(char ch)
{
    if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void main()
{
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    init(stack);
    char *post = "a*b+c";
    int i = 0;
    int k = -1;
    while (post[i] != '\0')
    {
        if (isOperand(post[i]))
        {
            k++;
            post[k] = post[i];
        }
        else if (post[i] == '(')
        {
            push(stack, '(');
        }
        else if (post[i] == ')')
        {
            while (peep(stack) != '(')
            {
                k++;
                post[k] = pop(stack);
            }
        }
    }
    if()
}*/
