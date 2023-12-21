#include <stdio.h>
#define MAX 5 
#include <stdlib.h> 
typedef struct stk {
int top;
int A[MAX];
}
Stack;

void Create_Stack(Stack *s)
{
      s->top = -1;
}

void PUSH(Stack *s, int value)
{
      if (s->top == MAX - 1)
      {
            printf("\nStack is full.");
      }
      else
      {
            s->top += 1;
            s->A[s->top] = value;
      }
}

int POP(Stack *s)
{
      int x;

      if (s->top == -1)
      {
            printf("\nStack is empty");
            return -1;
      }
      x = s->A[s->top];
      s->top -= 1;
      return x;
}

void display(Stack *s)
{
      int i;
      for (i = 0; i <= s->top; i++)
      {
            printf("%d ", s->A[i]);
      }
}

int main()
{
      Stack s;
      int value, y, ch;
      Create_Stack(&s);

      while (1)
      {
            printf("\n1 : PUSH");

            printf("\n2 : POP");
            printf("\n3 : Display");
            printf("\n4 : Exit");
            printf("\n\nenter your choice : ");
            scanf("%d", &ch);
            switch (ch)
            {

            case 1:
                  printf("Enter value : ");
                  scanf("%d", &value);
                  PUSH(&s, value);
                  break;
            case 2:
                  y = POP(&s);
                  if (y != -1)

                        printf("Deleted item is %d", y);
                  break;
            case 3:
                  display(&s);
                  break;
            case 4:
                  exit(0);
            }
      }
}
