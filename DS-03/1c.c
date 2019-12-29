


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
	q->front = q->rear = -1;
	q->Q = 	(int *)malloc(q->size * (sizeof(int)));
}

void enqueue(struct Queue *q,int x)
{
	if(q->rear == q->size-1)
		printf("Queue is full");
	else
	{
		q->rear++;
		q->Q[q->rear] = x;
	}
}

int dequeue(struct Queue *q)
{
	int x=-1;
	if(q->front == q->rear )
		printf("Queue is Empty");
	else
	{
		q->front++;
		x = q->Q[q->front];
	}
	
	return x;
}

void Display(struct Queue q)
{
	printf("Elemets of Queue are : ");
	int i;
	for(i=q.front+1;i <= q.rear;i++)
	{
		printf("%d ",q.Q[i]);
	}
	printf("\n");
	
}

int main()
{
	struct Queue q;
	create(&q,5);
	
	enqueue(&q,1);
	enqueue(&q,2);
	enqueue(&q,3);
	enqueue(&q,4);
	enqueue(&q,5);
	
	Display(q);
	printf("%d is Dequeued ",dequeue(&q));
 	return 0;
}
