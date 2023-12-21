#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
      int data;
      struct list *link;
} NODE;

typedef struct Queue
{
      struct list *front, *rear;
} QUEUE;

void enQueue(QUEUE *q, int value)
{
      NODE *temp = (NODE *)malloc(sizeof(NODE));
      temp->data = value;
      if (q->front == NULL)
            q->front = temp;
      else
            q->rear->link = temp;
      q->rear = temp;
      q->rear->link = q->front;
}

int deQueue(QUEUE *q)
{
      NODE *temp;
      int value;
      if (q->front == NULL)
      {
            printf("Queue is empty");
            return -1;
      }
      if (q->front == q->rear)
      {
            value = q->front->data;
            free(q->front);
            q->front = NULL;
            q->rear = NULL;
      }
      else
      {
            temp = q->front;
            value = temp->data;
            q->front = q->front->link;
            q->rear->link = q->front;
            free(temp);
      }
      return value;
}

void displayQueue(struct Queue *q)
{
      NODE *temp = q->front;
      printf("\nElements in Circular Queue are: ");
      while (temp->link != q->front)
      {
            printf("%d ", temp->data);
            temp = temp->link;
      }
      printf("%d", temp->data);
}

int main()
{
      QUEUE *q = (QUEUE *)malloc(sizeof(QUEUE));
      q->front = q->rear = NULL;

      enQueue(q, 14);
      enQueue(q, 22);
      enQueue(q, 6);

      displayQueue(q);

      printf("\nDeleted value = %d", deQueue(q));
      printf("\nDeleted value = %d", deQueue(q));

      displayQueue(q);
      enQueue(q, 9);
      enQueue(q, 20);
      displayQueue(q);
      return 0;
}
