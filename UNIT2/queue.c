#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<malloc.h>

typedef struct {
    char* q;
    int max_size;
    int f;
    int r;
}QUEUE;

QUEUE* create(int max_size)
{
    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
    queue->max_size = max_size;
    queue->q = (char*)malloc(queue->max_size*sizeof(char));
    queue->f = 0;
    queue->r = -1;
    return queue;
}

bool full(QUEUE* queue)
{
    return (queue->r == (queue->max_size-1));
}

bool empty(QUEUE* queue)
{
    return (queue->r < queue->f);
}

void enqueue(QUEUE* queue, char item)
{
    if(full(queue))
    {
        queue->max_size++;
        queue->q = (char*)realloc(queue->q, queue->max_size*sizeof(char));
    }
    queue->q[++queue->r] = item;
}

char dequeue(QUEUE* queue)
{
    if(empty(queue))
    {
        printf("Queue is empty.\n");
        exit(0);
    }
    return (queue->q[queue->f++]);
}

void display(QUEUE* queue)
{
    if(empty(queue))
    {
        printf("Queue is empty.\n");
        exit(0);
    }
    for(int i = queue->f; i<=queue->r; i++)    
    {
        printf("%c", queue->q[i]);
    }
}

void liberate(QUEUE* queue)
{
    free(queue->q);
    free(queue);
}

int main(void)
{
    QUEUE* queue = create(1);
    printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
    char c, item;
    do
    {
        printf("\nEnter your choice (1,2,3,4): ");
        scanf(" %c", &c);
        switch (c)
        {
            case '1':
                printf("Enter the item to be inserted: "); 
                scanf(" %c", &item);
                enqueue(queue, item);
                break;
            case '2':
                printf("Deleted element: %c",dequeue(queue));
                break;
            case '3':
                display(queue);
                break;
            case '4':
                break;
            default:
                printf("Invalid choice. Enter again.");
        }
    }while(c!=4);
    liberate(queue);
}