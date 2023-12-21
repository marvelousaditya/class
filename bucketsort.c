#include <stdio.h>
void bucket_sort(int A[],int n) {
      int bucket[20][10],bucketcount[10];
      int i,j,k,r,digitCount = 0,divisor =1;
      int largest,pass_no;
      largest = A[0];
      for(i=1;i<n;i++) {
            if(A[i] > largest) 
                  largest = A[i];
      }
      while (largest > 0) {
            digitCount++;
            largest = largest/10;
      }
      for(pass_no = 0;pass_no < digitCount;pass_no++) {
            for(k=0;k<10;k++) {
                  bucketcount[k] = 0;
            }
            for(i=0;i<n;i++) {
                  r = (A[i]/divisor) % 10;
                  bucket[bucketcount[r]][r] = A[i];
                  bucketcount[r] += 1;
            }
            i = 0;
            for(k=0;k<10;k++) {
                  for(j=0;j<bucketcount[k];j++) {
                        A[i] = bucket[j][k];
                        i++;
                  }
            }
            divisor *= 10;
      }
}
void main() {
      int A[20],n,i;
      printf("Enter the size of array\n");
      scanf("%d",&n);
      printf("Enter the elements of array\n");
      for(i=0;i<n;i++) {
            scanf("%d",&A[i]);
      }
      bucket_sort(A,n);
      printf("Sorted array is\n");
      for(i=0;i<n;i++) {
            printf("%d ",A[i]);
      }
}