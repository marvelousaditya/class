#include <stdio.h>
#define MAX 5
#include <stdlib.h>
typedef struct que {
    int front;
    int rear;
    int Q[MAX];
} QUEUE;
void Create_Queue(QUEUE *q) {
    q->front = -1;
    q->rear = -1;
}
void ADD_LQ(QUEUE *q, int value) {
    if (q->rear == MAX - 1) {
        printf("\nQueue is full.");
        return;
    }
    else {
        if (q->rear == -1)
        {
            q->front = q->rear = 0;
        }
        else
        {
            q->rear += 1;
        }
    }
    q->Q[q->rear] = value;
}
int DEL_LQ(QUEUE *q) {
    int x;
    if (q->front == -1) {
        printf("\nQueue is empty.");
        return -1;
    }
    x = q->Q[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front += 1;
    return x;
}
void display(QUEUE *q) {
    int i;
    if(q->rear == -1) {
        printf("\nQueue is empty.");
        return;
    }
    printf("\n");
    for (i = q->front; i <= q->rear; i++)
        printf("%d ", q->Q[i]);
}
void main() {
    QUEUE q;
    int value, y, ch;
    Create_Queue(&q);
    while (1) {
        printf("\n1 : ADD");
        printf("\n2 : DELETE");
        printf("\n3 : Display");
        printf("\n4 : Exit");
        printf("\n\nenter your choice : ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter value : ");
            scanf("%d", &value);
            ADD_LQ(&q, value);
            break;
        case 2:
            y = DEL_LQ(&q);
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
