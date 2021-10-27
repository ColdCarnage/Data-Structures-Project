#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int priority;
    char cmd[50];
    struct node *next;
}Node;


void append(Node **head, int priority,char *com){
	    Node * new_node = (Node *)malloc(sizeof(Node));
	    new_node->priority = priority;
        strcpy(new_node->cmd,com);
	    new_node ->next = NULL;
	    Node *temp = *head;
	    if(*head == NULL){
            *head = new_node;
	    }
	    else{
	        while(temp->next!=0){
	            temp = temp->next;
	        }
	        temp->next = new_node;
	    }
}
void executeCommand(Node *head){
	    Node *temp = head;
	    while(temp!=0){
            printf("Executed command at priority [%d]",temp->priority);
	        system(temp->cmd);
	        temp = temp ->next;
            printf("\n-------------------------------------------------------------------------------------------\n");
	    }
}
void swap(Node *a, Node *b)
{
    int temp = a->priority;
    a->priority = b->priority;
    b->priority = temp;
    char t[50];
    strcpy(t,a->cmd);
    strcpy(a->cmd,b->cmd);
    strcpy(b->cmd,t);
}

void Sort(Node *start)
{
    int swapped, i;
    Node *ptr1;
    Node *lptr = NULL;

    if (start == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = start;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->priority < ptr1->next->priority)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

int main(){
    Node *head = NULL;
    int n; 
    char c='y',com[50];

    int priority;
    while(c=='y'){
        printf("Enter the priority and command to be executed(Space-seperated):\n");
        scanf("%d",&priority);
        gets(com);
        append(&head, priority,com);
        printf("Do you want to continue adding commands[y/n]:");
        scanf("%c",&c);
    }
    Sort(head);
    executeCommand(head); 
    return 0;
}