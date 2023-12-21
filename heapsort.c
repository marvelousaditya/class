#include <stdio.h>
void Adjust(int A[],int i,int N) {
      int temp,j;
      temp = A[i];
      j = 2*i;
      while ((j <= N))
      {
            if(j < N && A[j+1] > A[j]) 
                  j = j+1;
            if(temp >= A[j]) 
                  break;
            A[j/2]  = A[j];
            j = 2*j;
      }
      A[j/2] = temp;
}
void H_Sort(int A[],int n) {
      int temp,i;
      for (i = n/2;i >= 1;i--) 
            Adjust(A,i,n);
      for (i = n-1;i >= 1;i--) {
            temp = A[1];
            A[1] = A[i+1];
            A[i+1] = temp;
            Adjust(A,1,i);
      }
}
void main() {
      int A[20],n,i;
      printf("enter the size of array\n");
      scanf("%d",&n);
      printf("enter the elements of array\n");
      for(i = 1;i <= n;i++) 
            scanf("%d",&A[i]);
      H_Sort(A,n-1);
      printf("sorted array is\n");
      for(i = 1;i <= n;i++) 
            printf("%d ",A[i]);
}