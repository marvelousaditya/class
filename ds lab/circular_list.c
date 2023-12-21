#include <stdio.h>
#include <stdlib.h>
typedef struct cll
{
	int INFO;
	struct cll *NEXT;
} NODE;

void insert_at_front_CLL(NODE **head, NODE **tail, int value)
{
	NODE *ptr;
	ptr = malloc(sizeof(NODE));
	ptr->INFO = value;
	ptr->NEXT = ptr;
	if (*head == NULL)
	{
		*head = ptr;
		*tail = ptr;
	}
	else
	{
		ptr->NEXT = *head;
		(*tail)->NEXT = ptr;
		*head = ptr;
	}
}
void insert_at_end_CLL(NODE **head, NODE **tail, int value)
{
	NODE *ptr;
	ptr = malloc(sizeof(NODE));
	ptr->INFO = value;
	ptr->NEXT = ptr;
	if (*head == NULL)
	{
		*head = ptr;
		*tail = ptr;
	}
	else
	{
		(*tail)->NEXT = ptr;
		ptr->NEXT = *head;
		*tail = ptr;
	}
}
int del_first_CLL(NODE **head, NODE **tail)
{
	NODE *temp;
	int y;
	if (*head == NULL)
	{
		printf("\nLIST is empty.");
		return -1;
	}
	y = (*head)->INFO;
	temp = *head;
	*head = (*head)->NEXT;
	(*tail)->NEXT = *head;
	free(temp);
	return y;
}
int del_last_CLL(NODE **head, NODE **tail)
{
	NODE *temp, *ptr, *prev;
	int y;
	if (*head == NULL)
	{
		printf("\nLIST is empty.");
		return -1;
	}
	if ((*head)->NEXT == *head)
	{
		y = (*head)->INFO;
		temp = *head;
		*head = NULL;
	}
	else
	{
		temp = *tail;
		ptr = *head;
		while (ptr->NEXT != *head)
		{
			prev = ptr;
			ptr = ptr->NEXT;
		}
		prev->NEXT = ptr->NEXT;
		*tail = prev;
		y = ptr->INFO;
	}
	free(temp);
	return y;
}
void display(NODE **head, NODE **tail)
{
	NODE *ptr;
	if (*head == NULL)
	{
		printf("\nLIST is empty.");
	}
	else
	{
		ptr = *head;
		printf("\nLIST is : ");
		do
		{
			printf("%d->", ptr->INFO);
			ptr = ptr->NEXT;
		} while (ptr != *head);
	}
}
void main()
{
	NODE *head, *tail;
	int ch, value, x;
	while (1)
	{
		printf("\n1.Enter at begining of circular list.");
		printf("\n2.Enter at end of circular list.");
		printf("\n3.TO DELETE first node.");
		printf("\n4.TO DELETE last node.");
		printf("\n5.DISPLAY LIST");
		printf("\n6.exit");
		printf("\nEnter choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\nenter value : ");
			scanf("%d", &value);
			insert_at_front_CLL(&head, &tail, value);
			break;
		case 2:
			printf("\nenter value : ");
			scanf("%d", &value);
			insert_at_end_CLL(&head, &tail, value);
			break;
		case 3:
			x = del_first_CLL(&head, &tail);
			if (x != -1)
				printf("\ndeleted item is : %d", x);
			break;
		case 4:
			x = del_last_CLL(&head, &tail);
			if (x != -1)
				printf("\ndeleted item is : %d", x);
			break;
		case 5:
			display(&head, &tail);
			break;
		case 6:
			exit(0);
		}
	}
}
