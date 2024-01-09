#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#include<string.h>

struct node {
    char data;
    struct node* link;
};

bool empty(struct node* head)
{
    return (head->link == NULL);
}

struct node* create()
{
    struct node* head = (struct node*)malloc(sizeof(struct node*));
    head->data = '-';
    head->link = NULL;
    return head;
}

void insert_tail(struct node* head, char item)
{
    struct node* ptr = head;
    while(true)
    {
        if(ptr->link == NULL)
            break;
        else
            ptr = ptr->link;
    }
    struct node* newnode = (struct node*)malloc(sizeof(struct node*));
    newnode->data = item;
    ptr->link = newnode;
    newnode->link = NULL;
}

void insert_head(struct node* head, char item)
{
    struct node* ptr = head;
    struct node* right = head->link;
    ptr->link = right;
    struct node* newnode = (struct node*)malloc(sizeof(struct node*));
    newnode->data = item;
    newnode->link = right;
    head->link = newnode;    
}

char delete_head(struct node* head)
{
    if(empty(head))
    {
        printf("List empty. No items left to delete. ");
    }
    struct node* ptr = head;
    struct node* newfirst = ptr->link->link;
    char deleted = ptr->link->data;
    free(ptr->link);
    ptr->link = newfirst;
    return deleted;
}

char delete_tail(struct node* head)
{
    if(empty(head))
    {
        printf("List empty. No items left to delete. ");
    }
    struct node* ptr = head;

    while(ptr->link->link != NULL)
    {
        ptr = ptr->link;
    }
    char deleted = ptr->link->data;
    ptr->link = NULL;
    return deleted;
}

void display(struct node* head)
{
    struct node* ptr = head;
    printf("\nThe contents of the queue are: ");
    while(ptr!=NULL)
    {
        printf("%c",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void liberate(struct node* head)
{
    struct node* ptr = head;
    while(ptr!=NULL)
    {
        free(ptr);
        ptr = ptr->link;
    }
}

int main(void)
{
    struct node* head = create();
    int choice;
    char item;
    printf("1. Insert at tail\n2. Insert at head\n3. Delete at tail\n4. Delete at head\n5. Display\n6. Exit\n");
    while(true)
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            printf("Enter the item to be inserted: ");
            scanf(" %c",&item);
            insert_tail(head,item);
            break;
            case 2:
            printf("Enter the item to be inserted: ");
            scanf(" %c",&item);
            insert_head(head,item);
            break;
            case 3:
            printf("Deleted element: %c\n",delete_tail(head));
            break;
            case 4:
            printf("Deleted element: %c\n",delete_head(head));
            break;
            case 5:
            display(head);
            break;
            case 6:
            exit(0);
            default:
            printf("Invalid choice. Please choose again.");
        }
    }
}