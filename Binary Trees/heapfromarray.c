#include <stdio.h> 
#include <stdlib.h>

void swap(int* p, int* q) //function to swap two inputed integers
{ 
    int temp; 
    temp = *p; 
    *p = *q; 
    *q = temp;
}
// creating a heap from an array, sort it using heapsort and then call the function to find largest elements
//In this code, we will convert an array to a heap and then sort it using heapsort
//Further, we will find heap_max

//heapify converts an array into a heap
void heapify(int array[], int n, int k) //creating heap from an array
{
    //we will compare the three elemenets — left node, right node and temp_large to see which one is larger
    int temp_large = k; 
    int left = 2 * k + 1;  
    int right = 2 * k + 2;
    
    //
    if (left < n && array[left] < array[temp_large]){ //from my min heap code on github, we have simply switched the signs for greater than and 
    //less than in the second condition of this statement as in a max heap, the parent has to be greater than both child nodes
        temp_large = left; 
    } 
    // if the current parent i.e. temp_large or the root is smaller than the right child, we replace it with the child's value
    if (right < n && array[right] < array[temp_large])
        temp_large = right;
    
    if (temp_large != k) {
        swap(&array[k], &array[temp_large]); // since a max heap requires the root/parent nodes to be the largest value, we swap them incase that is not the getting satisifed in the current layout
        heapify(array, n, temp_large); //recursively call this function for the length of the entire array
    }
}

void sorting(int array[], int n)//function to execute heap sort (maxheap) on the array
{
    for (int j = n / 2; j >= 0; j--)//starting from half the array's length, then going on to reduce the iterative loop's index
    //to traverse through the rest till the 0th position
    {
        heapify(array, n, j);
    }
    for (int i = n - 1; i >= 0; i--) { 
    //second loop to start an inner loop that goes from the end of the array to the first element 
        swap(&array[0], &array[i]); //swapping all 
        heapify(array, i, 0); //storing the highest value of the array in the root 
    }
}

// Main function to do heap sort
void heap_sort(int array[], int n)
{
    for (int j = n / 2; j >= 0; j--)// to build a max heap
        //j goes from middle to 0th position of heap
        heapify(array, n, j);//

    for (int i = n - 1; i >= 0; i--) { 
        swap(&array[0], &array[i]); 
    }
}
      
int main()
{
    int array[] = { 13, 27, 41, 22, 86, 56, 94}; //sample array 
    int n = sizeof(array) / sizeof(array[0]); //
    // dividing total space allocation by space allocation of one element 
    heap_sort(array, n);
    printf("Minimum Element of Max Heap:");
    printf(" %d", array[n-1]);
}
