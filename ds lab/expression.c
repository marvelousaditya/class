#include <stdio.h>
#include <stdlib.h>

typedef struct exp {
	int EXPO;
	int COEF;
	struct exp *NEXT;
}NODE;

void insert(NODE **head,int coef,int exp) {
	NODE *ptr;
	ptr = (NODE *)malloc(sizeof(NODE));
	ptr->EXPO = exp;
	ptr->COEF = coef;
	ptr->NEXT = NULL;
	if(*head == NULL) {
		*head = ptr;
	}
	else {
		ptr->NEXT = *head;
		*head = ptr;
	}
}

void PADD(NODE **A,NODE **B,NODE **C) {
	NODE *p,*q,*c,*d,*temp;
	int x;
	p = *A;
	q = *B;
	c = (NODE *)malloc(sizeof(NODE));
	d = *C;
	while(p != NULL && q != NULL) {
		if(p->EXPO == q->EXPO) {
			x = (p->COEF)+(q->COEF);
			if(x != 0) 
				ATTACH(x,p->EXPO,d);
			p = p->NEXT;
			q = q->NEXT;
		}
		if(p->EXPO < q->EXPO) {
			ATTACH(q->COEF,q->EXPO,d);
			q = q->NEXT;
		if(p->EXPO > q->EXPO) {
			ATTACH(p->EXPO,p->EXPO,d);
			p = p->NEXT;
		}
	}
	while(p != NULL) {
		ATTACH(p->COEF,p->EXPO,d);
		p = p->NEXT;
	}
	while(q != NULL) {
		ATTACH(q->COEF,q->EXPO,d);
		q = q->NEXT;
	}
	d->NEXT = NULL;
	temp = c;
	c = (c)->NEXT;
	free(temp);
}
void ATTACH(int coef,int expo,NODE *tail) {
	NODE *ptr;
	ptr = (NODE *)malloc(sizeof(NODE));
	ptr->COEF = coef;
	ptr->EXPO = expo;
	tail->NEXT = ptr;
	tail = ptr; 
}
void display_exp(NODE **head) {
	NODE *ptr;
	ptr = *head;
	printf("\n");
	if(head == NULL) {
		printf("LIST is empty.");
		return;
	}
	
	while(ptr!= NULL) {
		printf("(%d,%d) ->",ptr->COEF,ptr->EXPO);
		ptr = ptr->NEXT;
	}
}
void display(NODE **head) {
	NODE *ptr;
	ptr = *head;
	printf("\n");
	if(head == NULL) {
		printf("LIST is empty.");
		return;
	}
	
	while(ptr!= NULL) {
		printf("%d->",ptr->COEF);
		ptr = ptr->NEXT;
	}
}
void main() {
	NODE *head1,*head2,*head3;
	head1 = head2 = head3 = NULL;
	insert(&head1,9,0);
	insert(&head1,7,1);
	insert(&head1,2,2);
	insert(&head1,3,4);
	insert(&head1,7,5);
	//
	insert(&head2,1,2);
	insert(&head2,7,5);
	insert(&head2,30,8);
	display_exp(&head1);
	display_exp(&head2);
	PADD(&head1,&head2,&head3);
	display_exp(&head3);
}


