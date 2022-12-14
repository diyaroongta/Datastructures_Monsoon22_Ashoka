#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Implementation of skip lists with the example I have given above: traversing every node, every 10th node
struct slNode {
    int val;
    struct slNode* array[2];
};
typedef struct slNode NodeAddress; //renaming our node structure to NodeAddress

//initialising the list
NodeAddress* initialising(int val) { //initialising list with an element val
    NodeAddress* NodeAddress = malloc(sizeof(NodeAddress)); //creating space in memory for Node structure
    NodeAddress->val = val; 
    NodeAddress->array[0] = NULL;//creating first pointer to next element
    NodeAddress->array[1] = NULL;//creating second pointer to next to next element
    return NodeAddress;
}

void inserting(NodeAddress* head, int val) {  //method to insert the elements of the list manually or through an array where val represents the element
    NodeAddress* element=head; 
    int i = 0;//integer to store the index number to evaluate which index the pointer will point to (for ex: modding it by 10 for our second pointer)
    NodeAddress* ptr = head;
    while(element->array[0] != NULL) { //while the array's next element exists
        element = element->array[0];
        i++;    
        if(i%10 == 0) { //putting only every 10th element in the pointer, starting from position 0, and storing it till 
            ptr = element;
        }
    }

    NodeAddress* newnode = initialising(val);
    element->array[0] = newnode;

    int oldval = ptr->array[0]->val;

    if((i+1)%10==0) {
        ptr->array[1] = newnode;    }
}

void printListLevels(NodeAddress* head) {
    NodeAddress* element = head;
    element=head;
    while(element != NULL) {
        printf("Pointer's node value: %d \n", element->val);
        element = element->array[1];
    }

}

int main() {
    NodeAddress* head = initialising(1);//initialise first element of list as 1
    for (int i = 2; i<=20; i++) { //run a for loop to insert elements for the skip list upto 20 (example)
    //here, we will expect value of pointer 1 to be 1 (first element)
    //pointer 2's value should be 1+10 = 11 because we point at every 10th element
        inserting(head, i);
    }
    printListLevels(head);   
    return 0;
}
