#include <stdio.h> 
#include <stdlib.h>
typedef struct queue {
	int INFO;
	struct queue *NEXT;
}NODE;

void insert_LQ(NODE **head,int value) {
	NODE *ptr1,*ptr2;
	ptr1 = malloc(sizeof(NODE));
	ptr2 = *head;
	ptr1->INFO = value;
	ptr1->NEXT = NULL;
	if(ptr2 == NULL) {
		*head = ptr1;
		return;
	}
	while(ptr2->NEXT != NULL) {
		ptr2 = ptr2->NEXT;
	}
	ptr2->NEXT = ptr1;
}
int DEL_LQ(NODE **head) {
	NODE *ptr,*temp;
	int y;
	if(*head == NULL) {
		printf("\nQUEUE  is empty.");
		return -1;
	}
	y = (*head)->INFO;
	temp = *head;
	*head = (*head)->NEXT;
	free(temp);
	return y;
}
void display(NODE **head) {
	NODE *ptr;
	ptr = *head;
	if(ptr == NULL) {
		printf("\nQUEUE is empty.");
		return;
	}
	printf("\n\nQUEUE is : ");
	while(ptr != NULL) {
		printf("%d ",ptr->INFO);
		ptr = ptr->NEXT;
	}
}

void main() {
	NODE *head;
	int ch,value,del;
	while(1) {
		printf("\n1.Insert in QUEUE.");
		printf("\n2.Delete From QUEUE.");
		printf("\n3.Display.");
		printf("\n4.Exit.");
		printf("\n\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch) {
			case 1 : printf("\nenter value to add in QUEUE : ");
				scanf("%d",&value);
				insert_LQ(&head,value);
				break;
			case 2 : del = DEL_LQ(&head);
				if(del != -1)
					printf("Deleted ITEM is : %d",del);
				break;
			case 3 : display(&head);
				break;
			case 4 : exit(0);
				
		}
	}
}
