#include <stdio.h>
void Radix(int a[],int n) {
    int i,j,k,r,pass;
    int bucket[20][10] , bucketCount[10];
    int largest = a[0],divisor = 1,digitCount = 0;
    for (i = 1;i < n;i++) 
        if (largest < a[i])
            largest = a[i];
    while(largest > 0) {
        digitCount++;
        largest /= 10;
    }
    for (pass = 0;pass < digitCount;pass++) {
        for (i = 0;i < 10;i++) 
            bucketCount[i] = 0;
        for (i = 0;i < n;i++) {
            r = (a[i]/divisor)%10;
            bucket[bucketCount[r]][r] = a[i];
            bucketCount[r]++;
        }
        i = 0;
        for (k = 0;k < 10;k++) {
            for (j = 0;j < bucketCount[k];j++) {
                a[i] = bucket[j][k];
                i++;
            }
        }
        divisor *= 10;
    }
}
void main() {
    int i;
    int a[] = {5,41,42,64,23,34};
    Radix(a,6);
    for (i = 0 ;i < 6;i++)
        printf("%d ",a[i]);
}