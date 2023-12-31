#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

typedef struct {
    int top;
    char* st;
    int max_size;
}STACK;

STACK* create(int max_size)
{
    STACK* stack = (STACK *)malloc(sizeof(STACK));
    stack->max_size = max_size;
    stack->st = (char*)malloc(stack->max_size*sizeof(char));
    stack->top = -1;
    return stack;
}

bool underflow(STACK* stack)
{
    return (stack->top == -1);
}

bool overflow(STACK* stack)
{
    return (stack->top == (stack->max_size-1));
}

void push(STACK* stack, char item)
{
    if (overflow(stack))
    {
        stack->max_size++;
        stack->st = (char*)realloc(stack->st, (stack->max_size)*sizeof(char));        
    }
    stack->st[++stack->top] = item;
}

char pop(STACK* stack)
{
    if (underflow(stack))
    {
        printf("Stack is empty.\n");
        exit(0);
    }
    return (stack->st[stack->top--]);
}

char peek(STACK* stack)
{
    if (underflow(stack))
    {
        printf("Stack is empty.\n");
        exit(0);
    }
    return (stack->st[stack->top]);
}

void display(STACK* stack)
{
    if (underflow(stack))
    {
        printf("Stack is empty.\n");
        exit(0);
    }
    for(int i = 0; i<=stack->top; i++)  
    {
        printf("%c",stack->st[i]);
    }
}

void liberate(STACK* stack)
{
    free(stack->st);
    free(stack);
}

int prec(char op)
{
    switch(op)
    {
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

bool operand(char op)
{
    return (isalnum(op));
}

bool operator(char op)
{
    return (!operand(op));
}

char* postfix(char* infix)
{
    STACK* ops = create(1);
    char* postfix = (char*)malloc((strlen(infix)+1)*sizeof(char));
    int ind = 0;
    for(int i = 0; infix[i]!='\0'; i++)
    {
        char cur = infix[i];
        if(operand(cur))
        {
            postfix[ind++] = cur;
        }
        else if(cur == '(')
        {
            push(ops, cur);
        }
        else if(cur == ')')
        {
            while(!underflow(ops) && peek(ops)!='(')
            {
                postfix[ind++] = pop(ops);
            }
            char garbage = pop(ops);
        }
        else if(operator(cur))
        {
            while(!underflow(ops) && prec(cur)<=prec(peek(ops)))
            {
                postfix[ind++] = pop(ops);
            }
            push(ops, cur);
        }
    }
    while(!underflow(ops))
    {
        postfix[ind++] = pop(ops);
    }
    postfix[ind] = '\0';
    liberate(ops);
    return postfix;
}

int ctoi(char op)
{
    return (int)(op-48);
}

int itoc(int op)
{
    return (char)(op+48);
}

int eval(char* postfix)
{
    STACK* opers = create(1);
    for(int i = 0; postfix[i]!='\0';i++)
    {
        char cur = postfix[i];
        if(operand(cur))
        {
            push(opers, cur);
        }
        else if(operator(cur))
        {
            int op2 = ctoi(pop(opers));
            int op1 = ctoi(pop(opers));
            switch(cur)
            {
                case '+':
                    push(opers, itoc(op1+op2)); break;
                case '-':
                    push(opers, itoc(op1-op2)); break;
                case '/':
                    push(opers, itoc(op1/op2)); break;
                case '*':
                    push(opers, itoc(op1*op2)); break;
                case '%':
                    push(opers, itoc(op1%op2)); break;
                default:
                    printf("Invalid operator. ");
                    exit(0);                    
            }
        }
    }
    return ctoi(pop(opers));
}

int main(void)
{
    char infix[100];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    printf("The corresponding postfix expression is: %s\n", postfix(infix));
    printf("The result of the expression is %d.\n", eval(postfix(infix)));
}