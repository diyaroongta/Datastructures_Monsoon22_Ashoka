#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct node {
	int val;
	struct node * next;	
};
typedef struct node * NodeAddress; //creating a new data typpe called NodeAddress pointing to the structure node that takes in two inputs- val and *next

/* ================================================== */
//Selection Sort on Array using finding min element
int findIndexOfMin(int *a, int n){
	int imin;
	//special case for when there are no elements in the list 
	if (n<1){
		return -1;
	} //note: we cannot return a zero here because 0 can be answer for second case also
	else {
		imin=n;//assuming that position of min element is 0th element of array
		for(int i=0; i<n; i++){ //running a for loop throuhgout the array's elements
			if (a[i]<a[imin]){ //if any element while traversing in the list is found to be lesser than imin,
			//replace imin with the position of that element
				imin=i;
			}
		} 
		return imin; //returning the position of the smallest element
	}
}


void selectionSort(int *a, int n) {
	int i, imin, t;
	for(i=0; i<n; i=i+1) {
		imin = findIndexOfMin(a, n); //we store the value of the position of the minimum element in the array in imax, let it start with i
		if(a[i]<a[imin]){
            t = a[imin]; //store value of element at min position in temporary variable called t 
            a[imin] = a[i+1]; //
            a[i+1] = t;
        }
        
	}
}

int * generateArray(int n) {
	int * t = malloc( n * sizeof(int) );
	if(t) {
		for(int i=0; i<n; i++) {t[i] = rand()%1000;}
	}
	return t;
}
void printArray(int * a, int n) {
	printf("Array = ");
	for(int i=0; i<n; i++) {
		printf( i?", %d":"%d", a[i]);
	}
	printf(".\n");
}

void printArray1(int *a, int n) {
	for(int i=0; i<n; i++) {
		printf(" %d ", a[i]);
	}
}
int main(int argc, char **argv) {
	int * a;
	int n = 10;
	NodeAddress list;

	srand(time(NULL));

	a = generateArray(n);
    printArray(a,n);

    selectionSort(a,n);
    printArray(a,n);
	//list = linkedListFromArray(a,n);

	
	//int listmaxaddr = findAddressOfMax(a,n);
	// printf("Address of max element in list = %d, value of max element = %d\n", maxindex, a[maxindex]);
	// printLinkedList(list);
	
	
	// free(a);
	// freeLinkedList(list);

	return 0;
}
