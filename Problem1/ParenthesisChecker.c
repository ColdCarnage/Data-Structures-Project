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
        printf("Stack Overflow(Memory Not Sufficient)\n");
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
        printf("Stack Underflow(Stack is empty)\n");
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

char Top()
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
            if(Top() == '(' && exp[i] == ')')
                pop();
            else if(Top() == '{' && exp[i] == '}')
                pop();
            else if(Top() == '[' && exp[i] == ']')
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


int main(){
    char *exp;
    exp = (char*)malloc(10000*sizeof(char));
    printf("Enter 1 to check a string\nEnter 2 to check a file\n");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter a String:\n");
            scanf("%s",exp);
            break;
        case 2:;
            FILE *fptr;
            char filename[100],c;
            printf("Enter name of file:\n");
            scanf("%s",filename);
             fptr = fopen(filename, "r");
             if (fptr == NULL)
             {
                 printf("Cannot open file \n");
                 exit(0);
             }
             //Read contents from file
             c = fgetc(fptr);
             int len=0;
             while (c != EOF)
             {
                 exp[len]=c;
                 len++;
                 c = fgetc(fptr);
             }
             fclose(fptr);
             break;
             default:
                printf("Invalid Input");
                exit(0);   
    }
        


    if(isBalanced(exp))
        printf("The pairs and the orders of parenthesis in the given input are balanced\n");
    else 
        printf("The pairs and the orders of parenthesis in the given input are not balanced\n");
    free(exp);
    
    return 0;

}