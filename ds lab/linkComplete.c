#include <stdio.h> 
#include <stdlib.h>
typedef struct link_list {
	int INFO;
	struct link_list *NEXT;
}NODE;

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
void insert_after(NODE **head,int after,int value) {
	NODE *ptr,*loc;
	ptr = (NODE *)malloc(sizeof(NODE));
	ptr->INFO = value;
	ptr->NEXT = NULL;
	if(*head == NULL) {
		*head = ptr;
	}
	else {
		loc = *head;
		while(loc->INFO != after) 
			loc = loc->NEXT;
		ptr->NEXT = loc->NEXT;
		loc->NEXT = ptr;
	}
}
int del_first(NODE **head) {
	NODE *ptr,*temp;
	int y;
	if(*head == NULL) {
		return -1;
	}
	y = (*head)->INFO;
	temp = *head;
	*head = (*head)->NEXT;
	free(temp);
	return y;
}
int delete_any(NODE **head,int item) {
	NODE *temp,*loc,*prev;
	if(*head == NULL) {
		printf("\nLinked List is empty.");
		return -1;
	}
	else if((*head)->NEXT != NULL && (*head)->INFO == item) {
		temp = *head;
		*head = (*head)->NEXT;
		free(temp);
	}
	else if( (*head)->NEXT == NULL && (*head)->INFO == item){
		temp = *head;
		*head = NULL;
		free(temp);
	}
	else {
		loc = *head;
		while(loc->INFO != item) {
			prev = loc;
			loc = loc->NEXT;
		}
		temp = loc;
		prev->NEXT = loc->NEXT;
		free(temp);
	}
	
}
void display(NODE **head) {
	NODE *ptr;
	ptr = *head;
	if(ptr == NULL) {
		printf("\nLINKED LIST is empty.");
		return;
	}
	printf("\nLINKED LIST is : ");
	while(ptr != NULL) {
		printf("%d ",ptr->INFO);
		ptr = ptr->NEXT;
	}
}
void main() {
	NODE *head;
	head = NULL;
	int ch,value,del,after,x;
	while(1) {
		printf("\n\n1.Insert a node at front in LINKED LIST.");
		printf("\n2.Insert a node at end of LINKED LIST.");
		printf("\n3.Insert after a given node in LINKED LIST.");
		printf("\n4.Delete first NODE in LINKED LIST.");
		printf("\n5.Delete any given NODE in LINKED LIST.");
		printf("\n6.Display LINKED LIST.");
		printf("\n7.Exit.");
		printf("\n\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch) {
			case 1 : printf("\nenter value to add at begining : ");
				scanf("%d",&value);
				insert_at_beg(&head,value);
				break;
			case 2 : printf("\nenter value to add at begining : ");
				scanf("%d",&value);
				insert_at_end(&head,value);
				break;
			case 3 : printf("\nenter node to enter after : ");
					scanf("%d",&after);
					printf("\nenter value to enter : ");
					scanf("%d",&value);
					insert_after(&head,after,value);
					break;
			case 4 : del = del_first(&head);
				if(del != -1)
					printf("Deleted Item is is : %d",del);
				break;
			case 5 : printf("\nEnter NODE to delete : ");
					scanf("%d",&x);
					del = delete_any(&head,x);
					if(del != -1)
						printf("\ndelete item is : %d",del);
					break;
			case 6 : display(&head);
				break;
			case 7 : exit(0);
				
		}
	}
}
