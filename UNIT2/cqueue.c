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
}CQ;

CQ* create(int max_size)
{
    CQ* queue = (CQ*)malloc(sizeof(CQ));
    queue->max_size = max_size;
    queue->q = (char*)malloc(queue->max_size*sizeof(char));
    queue->f = queue->r = -1;
    return queue;
}

bool full(CQ* queue)
{
    return ((queue->r+1)%queue->max_size == queue->f);
}

bool empty(CQ* queue)
{
    return (queue->f == -1 && queue->r == -1);
}

void enqueue(CQ* queue, char item)
{
    if(full(queue))
    {
        printf("Queue is full.\n");
        exit(0);
    }
    if(empty(queue))
    {
        queue->f = queue->r = 0;
    }
    else
    {
        queue->r = (queue->r+1)%queue->max_size;
    }
    queue->q[queue->r] = item;
}

char dequeue(CQ* queue)
{
    if(empty(queue))
    {
        printf("Queue is empty.\n");
        exit(0);
    }

    char dequeued = queue->q[queue->f];

    if(queue->f == queue->r)
    {
        queue->f = queue->r = -1;
    }
    else
    {
        queue->f = (queue->f+1)%queue->max_size;
    }
    return dequeued;
}

void display(CQ* queue)
{
    if(empty(queue))
    {
        printf("Queue is empty.\n");
        exit(0);
    }
    int i = queue->f;
    while(i!=((queue->r+1)%queue->max_size))
    {
        printf("%c",queue->q[i]);
        i = (i+1)%queue->max_size;
    }
    printf("\n");
}

void liberate(CQ* queue)
{
    free(queue->q);
    free(queue);
}

int main(void)
{
    CQ* queue = create(5);


    enqueue(queue,'5');
    enqueue(queue,'6');
    enqueue(queue,'5');
    enqueue(queue,'6');
    display(queue);

    dequeue(queue);
    display(queue);
    dequeue(queue);
    display(queue);

    enqueue(queue,'m');
    display(queue);

    liberate(queue);

}