#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<stdbool.h>

struct node {
    char data;
    struct node* link;
};

struct node* create()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = '-';
    head->link = NULL;
    return head;
}

bool empty(struct node* head)
{
    return head->link == NULL;
}

void insert_head(struct node* head, char item)
{
    struct node* ptr = head;
    struct node* next = head->link;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = next;
    head->link = newnode;
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
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = NULL;
    ptr->link = newnode;
}

void insert_pos(struct node* head, char item, int pos)
{
    struct node* ptr = head;
    int length = 0;
    while(true)
    {
        if(ptr->link==NULL)
            break;
        else
        {
            length++;
            ptr = ptr->link;
        }
    }
    if(pos>length)
    {
        printf("Position out of bounds.");
        exit(0);
    }
    else if(pos == length)
    {
        insert_tail(head, item);
        return;
    }
    else
    {
        ptr = head;
        while(pos > 0)    
        {
            ptr = ptr->link;
            pos--;       
        }
        struct node* next = ptr->link;
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = item;
        ptr->link = newnode;
        newnode->link = next;
    }
}

char delete_head(struct node* head)
{
    if(empty(head))
    {
        printf("No items left to be deleted. List is empty.");
        exit(0);
    }
    struct node* ptr = head;
    struct node* del = head->link;
    struct node* newfirst = del->link;
    ptr->link = newfirst;
    char deleted = del->data;
    free(del);
    return deleted;
}

char delete_tail(struct node* head)
{
    if(empty(head))
    {
        printf("No items left to be deleted. List is empty.");
        exit(0);
    }
    struct node* ptr = head;
    while(true)
    {
        if(ptr->link->link == NULL)
            break;
        else
            ptr = ptr->link;
    }
    struct node* del = ptr->link;
    ptr->link = NULL;
    char deleted = del->data;
    free(del);
    return deleted;
}

char delete_pos(struct node* head, int pos)
{
    if(empty(head))
    {
        printf("No items left to be deleted. List is empty.");
        exit(0);
    }
    struct node* ptr = head;
    int length = 0;
    while(true)
    {
        if(ptr->link==NULL)
            break;
        else
        {
            length++;
            ptr = ptr->link;
        }
    }
    if(pos>length)
    {
        printf("Position out of bounds.");
        exit(0);
    }
    else if(pos==length)
    {
        return delete_tail(head);
    }
    else
    {
        struct node* ptr = head;
        pos--;
        while(pos > 0)
        {
            ptr = ptr->link;
            pos--;        
        }
        struct node* del = ptr->link;
        struct node* next = del->link;
        ptr->link = next;
        char deleted = del->data;
        free(del);
        return deleted;
    }
}

int search(struct node* head, char item)
{
    if(empty(head))
    {
        printf("No items left to be searched from. List is empty.");
        exit(0);
    }
    struct node* ptr = head;    
    int flag = 0;
    int count = 0;
    while(true)
    {
        if(ptr->data == item)
        {
            flag = 1;
            break;
        }
        else
        {
            count++;
            ptr = ptr->link;
        }
        if(ptr==NULL)
            break;
    }
    if(flag)
        return count;
    else
        return -1;
}

void display(struct node* head)
{
    if(empty(head))
    {
        printf("No items left to be displayed. List is empty.");
        exit(0);
    }
    struct node* ptr = head->link;
    printf("The contents of the list are: ");
    while(ptr!=NULL)
    {
        printf("%c",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

char get_item()
{
    char item;
    printf("Enter the item: ");
    scanf(" %c",&item);
    return item;
}

int get_pos()
{
    int pos;
    printf("Enter the position: ");
    scanf("%d",&pos);
    return pos;
}

int main(void)
{
    struct node* head = create();
    int choice;
    printf("1. Insert at tail\n2. Insert at head\n3. Insert after position\n4. Delete at tail\n5. Delete at head\n6. Delete at position\n7. Search an element\n8. Display\n9. Exit\n");
    while(true)
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert_tail(head,get_item());
            break;

            case 2:
            insert_head(head,get_item());
            break;

            case 3:
            insert_pos(head, get_item(), get_pos());
            break;

            case 4:
            printf("Deleted element: %c\n",delete_tail(head));
            break;

            case 5:
            printf("Deleted element: %c\n",delete_head(head));
            break;

            case 6:
            printf("Deleted element: %c\n",delete_pos(head, get_pos()));
            break;

            case 7:
            printf("Element is found at node %d of the list.\n",search(head, get_item()));
            break;

            case 8:
            display(head);
            break;

            case 9:
            exit(0);

            default:
            printf("Invalid choice. Please choose again.");
        }
    }
}