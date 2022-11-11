#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *x1, int *y1) //creating a function to swap the values of two int pointers 
{
    int t = *x1; //storing value of first pointer in a temporary variable
    *x1 = *y1;//changing value of x1 with y1
    *y1 = t;//assigning y1 the earlier value of x1 to swap
}

void insertionSort(int *arr, int n) //taking a pointer to the start of an array array as parameter 
//n is an integer denoting size of array
{
    int i,j,t;
    for(i=1;i<n;i++) //first for loop to traverse through array starting from second position to end of array
	{
		t=*(arr+i);//assigning temporary variable with ith position of array by adding i to starting position's pointer arr
		j=i-1; //for previous element
		while(t<*(arr+j)&&j>=0) //running while loop to check if temp variable i.e.  element is lesser than prevuious elemenet (arr+j) and
      //running it last position of j upto 0
		{
			*(arr+(j+1))=*(arr+j); //assigning the next value of arr to j instead
			j--; //decrementing value of j to traverse through all ekements
		}
		*(arr+(j+1))=t; 
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
    insertionSort(a, n);

    printf("Sorted array: \n");
    printArray(a, n);
    return 0;
}
