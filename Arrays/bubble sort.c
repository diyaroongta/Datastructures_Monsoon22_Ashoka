#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubblesort(int *arr, int n)
  
  int i, j, temp; //number of elements already sorted

    for(i = 0; i<n; i++){  
      for(j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                //swap elements if next element is smaller than the previous
                temp= arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }   //end of inner for loop

    }  //end of outer for loop
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

    bubbleSort(a,n);

    printf("Sorted array: \n");
    printArray(a, n);
    return 0;
}
