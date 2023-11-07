#include <stdio.h>
#include <stdlib.h>

typedef struct cll {
	int INFO;
	struct cll *NEXT;
}NODE;

void insert_at_front_CLL(NODE **head,NODE **tail,int value) {
	NODE *ptr;
	ptr = malloc(sizeof(NODE));
	ptr->INFO = value;
	ptr->NEXT = ptr;
	if(*head == NULL) {
  		 *head = ptr;
  		 *tail = ptr;
	}
	else {
		ptr->NEXT = *head;
		(*tail)->NEXT = ptr;
		*head = ptr;
	}
}

void insert_at_end_CLL(NODE **head,NODE **tail,int value) {
	NODE *ptr;
	ptr = malloc(sizeof(NODE));
	ptr->INFO = value;
	ptr->NEXT = ptr;
	if(*head == NULL) {
  		 *head = ptr;
  		 *tail = ptr;
	}
	else {
		(*tail)->NEXT = ptr;
		ptr->NEXT = *head;
		*tail = ptr;
	}
}

int del_ALT(NODE **head,NODE **tail) {
	NODE *ptr;
	if(head == NULL) {
		printf("\nLIST is empty.");
		return -1;
	}
	ptr = *head;
	while(*head != *tail) {
		if(ptr->NEXT == *tail) {
			ptr->NEXT = *head;
			*tail = ptr;
		}
		else if(ptr == *tail) {
			ptr->NEXT = (*head)->NEXT;
			*head = (*head)->NEXT;
		}
		else {
			ptr->NEXT = (ptr->NEXT)->NEXT;
		}
		ptr = ptr->NEXT;
	}
	return (*head)->INFO;
}
void display(NODE **head,NODE **tail) {
	NODE *ptr;
	if(*head == NULL) {
		printf("\nLIST is empty.");
	}
	else {
		ptr = *head;
		printf("\nLIST is : ");
		do {
			printf("%d->",ptr->INFO);
			ptr = ptr->NEXT;
		}while(ptr != *head);
	}
}
void main() {
	NODE *head,*tail;
	int ch,value,x;
	while(1) {
		printf("\n1.Enter at begining of circular list.");
		printf("\n2.Enter at end of circular list.");
		printf("\n3.TO DELETE alternate nodes.");
		printf("\n4.DISPLAY LIST");
		printf("\n5.exit");
		printf("\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch) {
			case 1 : printf("\nenter value : ");
				scanf("%d",&value);
				insert_at_front_CLL(&head,&tail,value);
				break;
			case 2 : printf("\nenter value : ");
				scanf("%d",&value);
				insert_at_end_CLL(&head,&tail,value);
				break;
			case 3 : x = del_ALT(&head,&tail);
				if(x != -1) 
					printf("\nlast remaining item is : %d",x);
				break;
			case 4 : display(&head,&tail);
				break;
			case 5 : exit(0);
		}
	}
	
}
