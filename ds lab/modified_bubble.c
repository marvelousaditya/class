#include <stdio.h>

void bubble(int A[],int n) {
      int i,pass,temp,flag;
      flag = 1;
      for(pass = 1;pass < n && flag;pass++) {
            flag = 0;
            for(i = 0;i < n-pass;i++) {
                  if(A[i] > A[i+1]) {
                        temp = A[i];
                        A[i] = A[i+1];
                        A[i+1] = temp;
                        flag = 1;
                  }
            }
      }
}
int main() {
      int A[20],n,i;
      printf("enter the size of array\n");
      scanf("%d",&n);
      printf("enter the elements of array\n");
      for(i = 0;i < n;i++) {
            scanf("%d",&A[i]);
      }
      bubble(A,n);
      printf("sorted array is\n");
      for(i = 0;i < n;i++) 
            printf("%d ",A[i]);
}

