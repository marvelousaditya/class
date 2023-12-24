#include <stdio.h>
void insertion_sort(int a[], int n)
{

      int i;
      int j;
      int temp;
      for (i = 1; i < n; i++)
      {
            temp = a[i];
            j = i - 1;
            while (j >= 0 && a[j] > temp)
            {
                  a[j + 1] = a[j];

                  j--;
            }
            a[j + 1] = temp;
      }
}

int main(void)
{
      int arr[10];
      int n;
      int i;
      printf("enter the size of array ");
      scanf("%d", &n);
      printf("enter the elements of array ");
      for (i = 0; i < n; i++)
      {

            scanf("%d", &arr[i]);
      }
      printf("before:-");
      for (i = 0; i < n; i++)
      {

            printf("%d ", arr[i]);
      }
      printf("\n");

      insertion_sort(arr, n);
      printf("after:\n");
      for (i = 0; i < n; i++)
      {
            printf("%d ", arr[i]);
      }
      printf("\n");
      return 0;
}
