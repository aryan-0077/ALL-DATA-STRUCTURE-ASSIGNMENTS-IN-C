


// Implement a double Ended Queue 




// Display the elements of the queue

#include<stdio.h>
#include<stdlib.h>

struct Queue 
{
	int size;
	int front;
	int rear;
	int *Q;
};

void create(struct Queue *q,int size)
{
	q->size = size;
	q->front = q->rear = (q->size)/2;
	q->Q = 	(int *)malloc(q->size * (sizeof(int)));
}

void enqueueR(struct Queue *q,int x)
{
	if(q->rear == q->size-1)
		printf("Queue is full at rear end");
	else
	{
		
		q->Q[q->rear] = x;
		q->rear++;
	}
}

void enqueueF(struct Queue *q,int x)
{
	if(q->front == -1)
		printf("Queue is full at front end ");
	else
	{
		q->front--;
		q->Q[q->front] = x;
	}
}

int dequeueF(struct Queue *q)
{
	int x=-1;
	if(q->front == q->rear )
		printf("Queue is Empty");
	else
	{
		
		x = q->Q[q->front];
		q->front++;
	}
	
	return x;
}

int dequeueR(struct Queue *q)
{
	int x=-1;
	if(q->front == q->rear )
		printf("Queue is Empty");
	else
	{
		q->rear--;
		x = q->Q[q->rear];
		
	}
	
	return x;
}

void Display(struct Queue q)
{
	printf("Elemets of Queue are : ");
	int i;
	for(i=q.front;i <= q.rear;i++)
	{
		printf("%d ",q.Q[i]);
	}
	printf("\n");
	
}

int main()
{
	struct Queue q;
	create(&q,10);
	
	enqueueF(&q,1);
	enqueueR(&q,2);
	enqueueF(&q,3);
	enqueueR(&q,4);
	enqueueF(&q,5);
	
	Display(q);
	printf("%d is Dequeued ",dequeueF(&q));
	printf("%d is Dequeued ",dequeueR(&q));
	
	Display(q);
 	return 0;
}
