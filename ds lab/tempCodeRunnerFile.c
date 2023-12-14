#include <stdio.h>

void bubble(int A[],int n) {
      int i,j,temp;
      for(i = 0;i < n;i++) {
            for(j = 0;j < n-i-1;j++) {
                  if(A[j] > A[j+1]) {
                        temp = A[j];
                        A[j] = A[j+1];
                        A[j+1] = temp;
                  }
            }
      }
      printf("sorted array is\n");
      for(i = 0;i < n;i++) {
            printf("%d\t",A[i]);
      }
}
void main() {
      int A[20],n,i;
      printf("enter the size of array\n");
      scanf("%d",&n);
      printf("enter the elements of array\n");
      for(i = 0;i < n;i++) {
            scanf("%d",&A[i]);
      }
      bubble(A,n);
}

