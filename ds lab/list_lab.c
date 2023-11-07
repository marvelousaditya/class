#include <stdio.h> 
#include <stdlib.h>
typedef struct link_list {
	int INFO;
	struct link_list *NEXT;
}NODE;
//function to add a node at begining of linked list
void insert_at_beg(NODE **head,int value) {
	NODE *ptr;
	ptr = malloc(sizeof(NODE));
	ptr->INFO = value;
	ptr->NEXT = NULL;
	if(*head == NULL) {
		*head = ptr;
	}
	else {
		ptr->NEXT = *head;
		*head = ptr;
	}
}
//function to add a node at last of  linked list
void insert_at_end(NODE **head,int value) {
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
//function to delete first node
int del_first(NODE **head) {
	NODE *ptr,*temp;
	int y;
	if(*head == NULL) {
		printf("\n\nLINKED LIST is empty.");
		return -1;
	}
	y = (*head)->INFO;
	temp = *head;
	*head = (*head)->NEXT;
	free(temp);
	return y;
}
//function to display the linked list.
void display(NODE **head) {
	NODE *ptr;
	ptr = *head;
	if(ptr == NULL) {
		printf("\n\nLINKED LIST is empty.");
		return;
	}
	printf("\n\nLINKED LIST is : ");
	while(ptr != NULL) {
		printf("%d->",ptr->INFO);
		ptr = ptr->NEXT;
	}
}

void main() {
	NODE *head;
	int ch,value,del;
	while(1) {
		printf("\n\n1.Insert At Beginning.");
		printf("\n2.Insert At Last.");
		printf("\n3.Delete First NODE.");
		printf("\n4.Display Linked List.");
		printf("\n5.Exit.");
		printf("\n\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch) {
			case 1 : printf("\nenter value to add at begining : ");
				scanf("%d",&value);
				insert_at_beg(&head,value);
				break;
			case 2 : printf("\nenter value to add at last : ");
				scanf("%d",&value);
				insert_at_end(&head,value);
				break;
			case 3 : del = del_first(&head);
				if(del != -1)
					printf("Deleted NODE is : %d",del);
				break;
			case 4 : display(&head);
				break;
			case 5 : exit(0);
				
		}
	}
}
