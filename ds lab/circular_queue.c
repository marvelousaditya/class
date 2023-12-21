#include <stdio.h>
#define MAX 5
#include <stdlib.h>
typedef struct cq
{
	int front;
	int rear;
	int Q[MAX];
} QUEUE;
void Create_CQ(QUEUE *q)
{
	q->front = -1;
	q->rear = -1;
}
void add_CQ(QUEUE *q, int value)
{
	if (q->front == (q->rear + 1) % MAX)
		printf("\nCircualar queue is full.");
	else
	{
		if (q->rear == -1)
			q->rear = q->front = 0;
		else
			q->rear = (q->rear + 1) % MAX;
		q->Q[q->rear] = value;
	}
}
int del_CQ(QUEUE *q)
{
	int y;
	if (q->front == -1)
	{
		printf("CIRCULAR QUEUE is empty.");
		return -1;
	}
	y = q->Q[q->front];
	if (q->front == q->rear)
		q->front = q->rear = -1;
	else
		q->front = (q->front + 1) % MAX;
	return y;
}
void display(QUEUE *q)
{
	int x;
	if (q->rear == -1)
	{
		printf("\nCIRCULAR QUEUE is empty.");
		return;
	}
	printf("\nQUEUE is : ");
	for (x = q->front; x <= (q->rear) % MAX; x++)
		printf("%d ", q->Q[x]);
}
void main()
{
	QUEUE q;
	int y, ch, value;
	Create_CQ(&q);
	while (1)
	{
		printf("\n1 : ADD");
		printf("\n2 : DElETE");
		printf("\n3 : Display");
		printf("\n4 : Exit");
		printf("\n\nenter your choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter value : ");
			scanf("%d", &value);
			add_CQ(&q, value);
			break;
		case 2:
			y = del_CQ(&q);
			if (y != -1)
				printf("Deleted item is %d", y);
			break;
		case 3:
			display(&q);
			break;
		case 4:
			exit(0);
		}
	}
}
