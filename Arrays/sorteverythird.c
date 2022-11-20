//Given a list of length n (random integers), sort every third element. All other elements should remain untouched.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node * NodeAddress; // creating a new data type called NodeAddress which is the address of the node

/* ================================================== */
//used the code from GitHub repo for selection sorting of arrays

void swap(int *x1, int *y1) //creating a function to swap the values of two int pointers 
{
    int t = *x1; //storing value of first pointer in a temporary variable
    *x1 = *y1;//changing value of x1 with y1
    *y1 = t;//assigning y1 the earlier value of x1 to swap
}

int* selectionSort(int *a, int n) //taking a pointer and integer as input in the function
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
    return a;
}
//function to print the array with a pointer
void printArray(int * a, int n) {
	for(int i=0; i<n; i++) {
		printf( i?", %d":"%d", a[i]);
	}
	printf(".\n");
}
//we will form an array to store every third element of the given array and sort that, then append the sorted values into the array
int * sortingArray(int * arr,int n) 
{
    int * a1= malloc( n/3 * sizeof(int) );//creating space for new array with new size
    int k=0; //taking an integer to loop in the new array
    for(int i=2;i<n;i=i+3)//running a for loop starting from the third element of array
    {
        a1[k]=arr[i]; //creating a new array with only every third element from the inputed array
        ++k; //incrementing value of j to go to next element of new array
    }
    a1=selectionSort(a1, n/3);
    //printArray(a1, n/3); testing to see if selection sort is giving the right array
    k=0;
    //appending the original array with the sorted every third elements
    for(int i=2;i<n;i=i+3)
    {
        arr[i]=a1[k];
        ++k;
    }
    return arr;
}

/* ================================================== */
//generating array using the same code as on my github repo
int * generateArray(int n) {
	int * t = malloc( n * sizeof(int) );
	if(t) {
		for(int i=0; i<n; i++) {t[i] = rand()%10;}
	}
	return t;
}

// writing a main function to call all the functions and print the sorted array
int main(){
	int *arr, n;
    printf("Enter array size:\n");
    scanf("%d",&n);
    printf("Elements of the array: \n");
    arr = generateArray(n); //generating array 
    printf("Original Array = ");
	printArray(arr, n);
    //Alternative approach is hard coding the array 

    int *arrsorted=sortingArray(arr,n);   
    printf("\n ");
    printf("Sorted Third Elements Array = ");
    printArray(arrsorted, n);
   
    return 0;
}
