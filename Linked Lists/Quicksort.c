#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct node {
	int val;
	struct node * next;	
};
typedef struct node * NodeAddress;


int partition(int *a, int leftmost, int rightmost){
  //assign pivot index to thre rightmost element of the array  
  int pivot = a[rightmost];
  int ind = leftmost;
  for (int i = leftmost; i < rightmost; i++){
      if(a[i] <= pivot){
          int temp = a[i];
          a[i] = a[ind];
          a[ind] = temp;
          ind++;
      }
  }
  int temp = a[ind];
  a[ind] = a[rightmost];
  a[rightmost] = temp;
  return ind;
}

void quickSort(int *a, int leftmost, int rightmost){
    if(a && leftmost < rightmost){
        int pIndex = partition(a, leftmost, rightmost);
        quickSort(a, leftmost, pIndex-1);
        quickSort(a, pIndex+1, rightmost);
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
//--------------------------------------------//

//Creating a linked list

int * generateArray(int n) {
	int * t = malloc( n * sizeof(int) );
	if(t) {
		for(int i=0; i<n; i++) {t[i] = rand()%1000;}
	}
	return t;
}


NodeAddress linkedListFromArray(int n){
	int i;
	NodeAddress head = NULL;
	NodeAddress temp = NULL;
	int x=0;

	// special case for head
	if(n>0) {
		head = malloc(sizeof(struct node) );
		printf("Enter the elements \n");
		scanf("%d",&x);
		head->val  = x;
		head->next = NULL;
		temp = head;
	}

	for(i=1; i<n; i++) {
		temp->next = malloc( sizeof(struct node) );// allocating space for the element of the linked list along with the address of the next node
		temp = temp->next; // sorting the address of next node
		scanf("%d",&x);
		temp->val = x; // storing the value of the element 
		temp->next = NULL;
	}
	return head;
}

//-------------------------------------------------//


//To free the space used by the linked list
void freeLinkedList(NodeAddress head) {
	NodeAddress prev;
	while(head) {
		prev = head;
		head = head->next;
		free(prev);
	}
}


int main(){
    int * a;
    int n = 10;
    NodeAddress list;

	srand(time(NULL));

	a = generateArray(n);
	list = linkedListFromArray(n);
    printLinkedList(list);

    printf("Sorted array: \n");
    quickSort(a, 0, n-1);
    printLinkedList(list);

	free(a);
	freeLinkedList(list);

    return 0;
  
    
}
