#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node *next;
}*top = NULL;

void push(char x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL)
        printf("Stack is Overflow\n");
    else
    {
        t->data = x;
        t->next = top;
        top=t;
    }
}

char pop()
{
    char x = -1;
    struct Node *p;
    if(top == NULL)
        printf("Stack is Underflow\n");
    else
    {
        p=top;
        top=top->next;
        x=p->data;
        free(p);
    }
    return x;
}

int isEmpty()
{
    return top?0:1;
}

char stackTop()
{
    if(!isEmpty())
        return top->data;
    return '0';
}

int isBalanced(char *exp)
{
    int i;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(isEmpty())
                return 0;
            if(stackTop() == '(' && exp[i] == ')')
                pop();
            else if(stackTop() == '{' && exp[i] == '}')
                pop();
            else if(stackTop() == '[' && exp[i] == ']')
                pop();
            else
                return 0;
        }
    }
        if(isEmpty())
            return 1;
        else
            return 0;
}


int main()
{
    char *exp;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        exp = (char*)malloc(10000*sizeof(char));
        scanf("%s",exp);
        if(isBalanced(exp))
            printf("YES\n");
        else 
            printf("NO\n");
        free(exp);
        while (!isEmpty()) pop();
    }
    return 0;
}