#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int val;
	struct node * next;	
};
typedef struct node * NodeAddress;

/* ================================================== */
//Selection Sort on Array
int findIndexOfMax(int *a, int n){
	int imax;
	//incase there are no elements in the list 
	if (n<1){
		return -1;} //cannot be zero because 0 can be answer for second case also
	else {
		imax=0;//assuming that position of max element is 0th element of array
		for(int i=0; i<n; i++){
			if (a[i]>a[imax]){ //if any element while traversing in the list is found to be greater than imax,
			//replace imax witht the position of that element
				imax=i;
			}
		} 
		return imax;
	}
}


void selectionSort(int *a, int n) {
	int i, imax, t;

	for(i=n; i>1; i=i-1) {
		imax = findIndexOfMax(a, i);
		t = a[imax]; a[imax] = a[i-1]; a[i-1] = t;
	}
}

//Selection Sort on Linked List
int findAddressOfMax(int *a, int n){
	int* amax= NULL; 
	if (n<1){//checking if n is greater than 1 or not i.e. if list elements exist
		return -1;
	}
	else{
		amax = a;
		for(int i=1; i<n; i++){
			if(*(a+i)>*(a+max)){
				amax=i;
			}
		return amax;
		}
}

/* ================================================== */
int * generateArray(int n) {
	int * t = malloc( n * sizeof(int) );
	if(t) {
		for(int i=0; i<n; i++) {t[i] = rand()%1000;}
	}
	return t;
}

NodeAddress linkedListFromArray(int * a, int n) {
	int i;
	NodeAddress head = NULL;
	NodeAddress temp = NULL;

	// special case for head
	if(n>0) {
		head = malloc( sizeof(struct node) );
		head->val  = a[0];
		head->next = NULL;
		temp = head;
	}


	for(i=1; i<n; i++) {
		temp->next = malloc( sizeof(struct node) );
		temp = temp->next;
		temp->val = a[i];
		temp->next = NULL;
	}

	return head;
}

void freeLinkedList(NodeAddress head) {
	NodeAddress prev;
	while(head) {
		prev = head;
		head = head->next;
		free(prev);
	}
}

/* ================================================== */
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

void printLinkedList(NodeAddress head) {
	NodeAddress c;
	printf("Linked List = ");
	for(c=head; c!=NULL; c=c->next) {
		printf( c==head?"%d":", %d", c->val);
	}
	printf(".\n");
}

/* ================================================== */
int main(int argc, char **argv) {
	int * a;
	int n = 10;
	NodeAddress list;

	srand(time(NULL));

	a = generateArray(n);
	list = linkedListFromArray(a,n);

	printArray(a,n);

	int listmaxaddr = findAddressOfMax(a,n);
	printf("Address of max element in list = %d, value of max element = %d\n", maxindex, a[maxindex]);
	printLinkedList(list);
	
	
	free(a);
	freeLinkedList(list);

	return 0;
}

