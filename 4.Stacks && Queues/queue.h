#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    Item elem;
    struct cel* next;
}QueueCel, *TQueue;

typedef struct {TQueue front, rear;} AQ;


AQ* InitQueue()
{
   AQ *queueueue = NULL;
   queueueue = (AQ*)malloc(sizeof(AQ));
   queueueue->front = NULL;
   queueueue->rear  = NULL;
   return queueueue;
}

int IsEmptyQueue(AQ *q)
{
   if( q->front == NULL || q->rear == NULL ) return 1;
   else return 0;
}


void Enqueue(AQ *q, Item el)
{

    if( IsEmptyQueue(q) )
    {
    	q->front = (TQueue)malloc(sizeof(QueueCel));
    	q->front->elem = el;
    	q->front->next = NULL;
    	q->rear  = q->front;
    	return;
    }

    q->rear->next = (TQueue)malloc(sizeof(QueueCel));
    q->rear = q->rear->next;
    q->rear->elem = el;
    q->rear->next = NULL;

    return;
}


Item Dequeue(AQ *q)
{
    if( IsEmptyQueue(q) ) return -1;
    TQueue queueue = q->front;
    Item u_U = queueue->elem;
    q->front = q->front->next;
    free(queueue);
    return u_U;	
}

Item Front(AQ *q)
{
    return q->front->elem;
}

void PrintQueue(AQ *q)
{
	TQueue que = q->front;
	while( que )
	{
		printf("%d ",que->elem);
		que = que->next;
	}
	printf("\n");
}
#endif
