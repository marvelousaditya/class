#include <stdio.h>
void bubble(int A[],int n) {
      int i,pass,temp;
      for(pass = 1;pass < n;pass++) {
            for(i = 0;i < n-pass;i++) {
                  if(A[i] > A[i+1]) {
                        temp = A[i];
                        A[i] = A[i+1];
                        A[i+1] = temp;
                  }
            }
      }
}
void main() {
      int A[20],n,i;
      printf("enter the size of array\n");
      scanf("%d",&n);
      printf("enter the elements of array\n");
      for(i = 0;i < n;i++) 
            scanf("%d",&A[i]);
      bubble(A,n);
      printf("sorted array is\n");
      for(i = 0;i < n;i++) 
            printf("%d ",A[i]);
}

