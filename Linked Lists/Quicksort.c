#include <stdio.h>
#include <stdlib.h>


int partition(int *a, int leftmost, int rightmost){
  //assign pivot index to thre rightmost element of the array  
  int pivot = a[rightmost];
  int ind = leftmost; //integer of index
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

void quickSort(int *a, int leftmost, int rightmost){
    if(a && leftmost < rightmost){
        int pIndex = partition(a, leftmost, rightmost);
        quickSort(a, leftmost, pIndex-1);
        quickSort(a, pIndex+1, rightmost);
    }
}

//function to print the array 
void printArray(int * a, int n) {
	printf("Array = ");
	for(int i=0; i<n; i++) {
		printf( i?", %d":"%d", a[i]);
	}
	printf(".\n");
}

int main(){
    int * a;
	  int n = 10;

	  srand(time(NULL));

	  a = generateArray(n);
    printArray(a,n);
    printf("Sorted array: \n");
    quickSort(a, 0, n-1);
    return 0;
}
