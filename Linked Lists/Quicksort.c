#include <stdio.h>
#include <stdlib.h>


int partition(int *a, int leftmost, int rightmost){
  //assign pivot index to thre rightmost element of the array  
  int pivot = a[rightmost];
  int ind = leftmost;
  for (int i = leftmost; i < rightmost; i++){
      if(a[i] <= pivot){
          int temp = a[i];
          a[i] = a[pIndex];
          a[ind] = temp;
          ind++;
      }
  }
  int temp = a[ind];
  a[ind] = a[rightmost];
  a[rightmost] = temp;
  return pIndex;
}

void quickSort(int *a, int start, int end){
    if(a && start < end){
        int pIndex = partition(a, start, end);
        quickSort(a, start, pIndex-1);
        quickSort(a, pIndex+1, end);
    }
}

void main(){
    int a[] = {7, 2, 1, 6, 8, 4, 3, 4};
    int n = sizeof(a)/sizeof(a[0]);
    quickSort(a, 0, n-1);
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
