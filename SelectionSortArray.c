#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x1, int *y1) //creating a function to swap the values of two int pointers 
{
    int t = *x1; //storing value of first pointer in a temporary variable
    *x1 = *y1;//changing value of x1 with y1
    *y1 = t;//assigning y1 the earlier value of x1 to swap
}

void selectionSort(int *a, int n) //taking a pointer and integer as input in the function
{
    int i, j, imin;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {   // Find the minimum element in unsorted array
        imin = i;
        for (j = i+1; j < n; j++){

          if (a[j] < a[imin]){
            imin = j;
          }
        }
        // Swap the found minimum element with the first element
        if(imin != i)
        {
            swap(&a[imin], &a[i]);
        }
    }
}

//function to generate an array of size t with random integers
int * generateArray(int n) {
	int * t = malloc( n * sizeof(int) );
	if(t) {
		for(int i=0; i<n; i++) {t[i] = rand()%1000;}
	}
	return t;
}

//function to print the array 
void printArray(int * a, int n) {
	printf("Array = ");
	for(int i=0; i<n; i++) {
		printf( i?", %d":"%d", a[i]);
	}
	printf(".\n");
}

//main method - to call the functions above 
int main(int argc, char **argv) {
	int * a;
	int n = 10;

	srand(time(NULL));

	a = generateArray(n);
    printArray(a,n);
    selectionSort(a, n);

    printf("Sorted array: \n");
    printArray(a, n);
    return 0;
}
