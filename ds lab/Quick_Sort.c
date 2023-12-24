#include <stdio.h>
#include <stdlib.h>
typedef struct bst
{
      struct bst *LEFT;
      struct bst *RIGHT;
      int INFO;
} NODE;

void insert(NODE **root, int value)
{
      NODE *ptr, *loc1, *loc2;
      ptr = (NODE *)malloc(sizeof(NODE));
      ptr->INFO = value;
      ptr->RIGHT = NULL;
      ptr->LEFT = NULL;
      if (*root == NULL)
      {
            *root = ptr;
      }
      else
      {
            loc1 = NULL;
            loc2 = *root;
            while (loc2 != NULL)
            {
                  loc1 = loc2;
                  if (value > loc2->INFO)
                  {
                        loc2 = loc2->RIGHT;
                  }
                  else
                  {
                        if (value < loc2->INFO)
                        {
                              loc2 = loc2->LEFT;
                        }
                        else
                        {
                              printf("\nDuplicate Entry");
                              return;
                        }
                  }
            }
            if (value > loc1->INFO)
                  loc1->RIGHT = ptr;
            else
                  loc1->LEFT = ptr;
      }
}

void inorder(NODE *root)
{
      if (root != NULL)
      {
            inorder(root->LEFT);
            printf("%d ", root->INFO);
            inorder(root->RIGHT);
      }
}

void preorder(NODE *root)
{
      if (root != NULL)
      {
            printf("%d ", root->INFO);
            preorder(root->LEFT);
            preorder(root->RIGHT);
      }
}
void postorder(NODE *root)
{
      if (root != NULL)
      {
            postorder(root->RIGHT);
            postorder(root->LEFT);
            printf("%d ", root->INFO);
      }
}
void main()
{
      NODE *root;
      int ch, value;
      root = NULL;
      while (1)
      {
            printf("\n\n1.Insert NODE in BST");
            printf("\n2.Inorder");
            printf("\n3.Preorder");
            printf("\n4.Postorder");
            printf("\n5.Exit");
            printf("\nEnter your choice : ");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                  printf("enter value : ");
                  scanf("%d", &value);
                  insert(&root, value);
                  break;
            case 2:
                  printf("\ninorder traversal of BST : ");
                  inorder(root);
                  break;
            case 3:
                  printf("\npreorder traversal of BST : ");
                  preorder(root);
                  break;
            case 4:
                  printf("\npostorder traversal of BST : ");
                  postorder(root);
                  break;
            case 5:
                  exit(0);
            }
      }
}
