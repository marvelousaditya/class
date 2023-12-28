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
void delete(NODE **root, int value)
{
      NODE *p, *q, *rp, *f, *s;
      p = *root;
      q = NULL;
      while (p != NULL && p->INFO != value)
      {
            q = p;
            if (value < p->INFO)
                  p = p->LEFT;
            else
                  p = p->RIGHT;
      }
      if (p == NULL)
            return;
      if (p->LEFT == NULL)
            rp = p->RIGHT;
      else if (p->RIGHT == NULL)
            rp = p->LEFT;
      else
      {
            f = p;
            rp = p->RIGHT;
            s = rp->LEFT;
            while (s != NULL)
            {
                  f = rp;
                  rp = s;
                  s = s->LEFT;
            }
            if (f != p)
            {
                  f->LEFT = rp->RIGHT;
                  rp->RIGHT = p->RIGHT;
            }
            rp->LEFT = p->LEFT;
      }
      if (q == NULL)
            *root = rp;
      else
      {
            if (p == q->RIGHT)
                  q->RIGHT = rp;
            else
                  q->LEFT = rp;
      }
      free(p);
}
int count(NODE *root)
{
      if (root == NULL)
            return 0;
      else
            return (count(root->LEFT) + count(root->RIGHT) + 1);
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
int height(NODE *root)
{
      if (root == NULL)
            return -1; // height of empty tree is -1
      else
      {
            int leftHeight = height(root->LEFT);
            int rightHeight = height(root->RIGHT);
            return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
      }
}
int main()
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
            printf("\n5.Delete a node");
            printf("\n6.Count number of nodes");
            printf("\n7.Height of tree");
            printf("\n8.Exit");
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
                  printf("\nEnter tree value to delete : ");
                  scanf("%d", &value);
                  delete (&root, value);
                  break;
            case 6:
                  printf("\nNumber of nodes in BST : %d", count(root));
                  break;
            case 7:
                  printf("\nHeight of tree : %d", height(root));
                  break;
            case 8:
                  exit(0);
            }
      }
}
