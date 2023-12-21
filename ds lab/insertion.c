//
// Created by aditya on 07-12-2023.
//
#include <stdio.h>
void Insertion_Sort(int a[],int n) {
    int Pass,ptr,temp;
    for(Pass = 1;Pass < n;Pass++) {
        ptr = Pass - 1;
        temp = a[Pass];
        while(ptr >= 0 && temp < a[ptr]) {
            a[ptr+1] = a[ptr];
            ptr = ptr - 1;
        }
        a[ptr+1] = temp;
    }
}
void main() {
    int A[20],n,i;
    printf("enter the size of array : ");
    scanf("%d",&n);
    printf("enter the elements of array\n");
    for(i = 0;i < n;i++) 
        scanf("%d",&A[i]);
    Insertion_Sort(A,n);
    printf("sorted array is : ");
    for(i = 0;i < n;i++) 
        printf("%d ",A[i]);
}

