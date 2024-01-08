#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>
#include<string.h>

typedef struct {
    int f, r;
    char* q;
    int max_size;
}QUEUE;

QUEUE* create()
{
    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
    queue->f = 0;
    queue->r = -1;
    queue->max_size = 1;
    queue->q = (char*)malloc(queue->max_size*sizeof(char));
    return queue;
}

bool full(QUEUE* queue)
{
    return queue->r == queue->max_size-1;
}

bool empty(QUEUE* queue)
{
    return queue->f > queue->r;
}

void enqueue(QUEUE* queue, char item)
{
    if (full(queue))
    {
        queue->q = (char*)realloc(queue->q, (++queue->max_size)*sizeof(char));
    }
    queue->q[++queue->r] = item;
}

char dequeue(QUEUE* queue)
{
    if (empty(queue))
    {
        printf("Queue is empty. No items left to be deleted.\n");
        exit(0);
    }
    return queue->q[queue->f++];
}

void display(QUEUE* queue)
{
    if(empty(queue))
    {
        printf("Queue is empty. No items left to be displayed.\n");
        exit(0);
    }
    printf("The elements of the queue are: ");
    for(int i = queue->f; i<=queue->r; i++)
    {
        printf("%c",queue->q[i]);
    }
}

void liberate(QUEUE* queue)
{
    free(queue->q);
    free(queue);
}

int main(void)
{
    QUEUE* queue = create();
    char item;
    int choice;
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    while(true)    
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            printf("Enter the character to be inserted into the queue: ");
            scanf(" %c", &item);
            enqueue(queue, item);
            case 2:
            printf("Dequeued element: %c",dequeue(queue));
            case 3:
            display(queue);
            case 4:
            exit(0);
            default:
            printf("Invalid choice. Please choose again.\n");
        }
    }
    liberate(queue);
}