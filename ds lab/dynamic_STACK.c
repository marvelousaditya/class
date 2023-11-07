#include <stdio.h> 
#include <stdlib.h>
typedef struct stack {
	int INFO;
	struct stack *NEXT;
}NODE;
void PUSH(NODE **TOP,int value) {
	NODE *ptr;
	ptr = malloc(sizeof(NODE));
	ptr->INFO = value;
	ptr->NEXT = NULL;
	if(*TOP == NULL) {
		*TOP = ptr;
	}
	else {
		ptr->NEXT = *TOP;
		*TOP = ptr;
	}
}
int POP(NODE **TOP) {
	NODE *ptr,*temp;
	int y;
	if(*TOP == NULL) {
		printf("\n\nSTACK is empty.");
		return -1;
	}
	y = (*TOP)->INFO;
	temp = *TOP;
	*TOP = (*TOP)->NEXT;
	free(temp);
	return y;
}
void display(NODE **TOP) {
	NODE *ptr;
	ptr = *TOP;
	if(ptr == NULL) {
		printf("\n\nSTACK is empty.");
		return;
	}
	printf("\n\nSTACK is : ");
	while(ptr != NULL) {
		printf("%d->",ptr->INFO);
		ptr = ptr->NEXT;
	}
}

void main() {
	NODE *TOP;
	int ch,value,del;
	TOP = NULL;
	while(1) {
		printf("\n\n1.Insert in STACK.");
		printf("\n2.Delete from STACK.");
		printf("\n3.Display STACK.");
		printf("\n4.Exit.");
		printf("\n\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch) {
			case 1 : printf("\nenter value to add : ");
				scanf("%d",&value);
				PUSH(&TOP,value);
				break;
			case 2 : del = POP(&TOP);
				if(del != -1)
					printf("Deleted Item is is : %d",del);
				break;
			case 3 : display(&TOP);
				break;
			case 4 : exit(0);
				
		}
	}
}
