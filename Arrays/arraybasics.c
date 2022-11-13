#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//creating struct node to create data type that can store two variables
struct node {
    int val;
    struct node *next;
};
typedef struct node * NodeAddress;

/*====================================================================*/

void bubbleSort(int *a, int n){
    int t;
    for(int done=0; done<n; done++){
        for(int i=0; i<n-1-done; i++){
            // swap the elements because they are in the wrong order
            if(a[i]>a[i+1]){
                t       = a[i];
                a[i]    = a[i+1];
                a[i+1]   = t;
            }
        }
    }
}

NodeAddress bubbleSortLinkedList(NodeAddress head){
    NodeAddress c, lastDone;
	int t;

	for(lastDone = NULL; lastDone!=head; lastDone=c) {

		for(c=head; c->next!=lastDone; c=c->next) {

			if( c->val > c->next->val ) {
				t = c->val;
				c->val = c->next->val;
				c->next->val = t;
			}

		} // end of c loop; the element has been bubbled up to position c

	}
	return head;
}
/*====================================================================*/
//ARRAY
//Generating Array and printing it
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

    //special case for head to check: if n>0, assigning first value of linkedlist to array's first element
	if(n>0) {
		head = malloc( sizeof(struct node) );
		head->val  = a[0];
		head->next = NULL;
		temp = head;
	}

    //storing elements of array in Linked List
	for(i=1; i<n; i++) {
		temp->next = malloc( sizeof(struct node) );
		temp = temp->next;
		temp->val = a[i];
		temp->next = NULL;
	}

	return head;
}


void printArray(int *a, int n) {
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

//printing a Linkedlist
void printLinkedList(NodeAddress head){
    NodeAddress c;
    for(c=head; c!= NULL; c=c->next){ //we start from head i.e. first element, and while we dont reach a point where pointer points to NULL as next element, we continue adding elements 
        printf(c == head?"%d":", %d", c-> val);
    }
    printf(".\n");
}

//freeing up the space taken by Linkedlist to avoid memory loss
void freeLinkedList(NodeAddress head){
    NodeAddress prev;
    while (head){ //while head exists, we will move onto next element through head, and delete the prev element each time 
        prev=head;
        head=head->next;
        free(prev);

    }
}

/*====================================================================*/

int main(int argc, char **argv) {
	int * a;
	int n = 10;
	NodeAddress list;

	srand(time(NULL));

	a = generateArray(n);
	list = linkedListFromArray(a,n);

	printArray(a,n);
	bubbleSort(a,n);
	printArray(a,n);
    printf("Linked List: ");
	printLinkedList(list);
	bubbleSortLinkedList(list);
    printf("Sorted Linked List: ");
	printLinkedList(list);

	free(a);
	freeLinkedList(list);

	return 0;
}
