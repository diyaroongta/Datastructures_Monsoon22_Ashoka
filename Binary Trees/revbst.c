#include <stdio.h>
#include <stdlib.h>

//This code is not working on my mac's VSCode but worked on an online C compiler that I used
//I have used alot of the same code as the one uploaded on my github repo under BST, along with what professor had uploaded on classroom
//as part of the bst lecture

//create tree node called NodeAddresss
struct nodeType {
	int val;
	struct nodeType * left;  // larger 
	struct nodeType * right; // smaller 
};
typedef struct nodeType * NodeAddress;

//creating the node with a given integer value
NodeAddress createNode(int value)
{
    NodeAddress Node  = malloc(sizeof(NodeAddress));
    Node->left  = NULL;
    Node->right = NULL;
    Node->val   = value; 
    return Node;   
}

//function to insert an node in the tree with new integer value
NodeAddress insert(NodeAddress root, int val) {
	if(root==NULL) { //incase tree is empty or we have reached the last element for that row
        return createNode(val);
    }
	if      ( val > root->val ) { //checking if value to be added is greater than the root/parent of that position
        root->left  = insert(root->left , val); //inserting the larger value to the left of the node to create a reverse BST
    }
	else if ( val < root->val ) {  //incase value to be added is lesser than the parent of that node through pointer 
        root->right = insert(root->right, val); //adding the smaller value to the right of the root/current parent node to arrange in the desired order
    }
	return root;
}


void prefixPrint(NodeAddress root) // printing tree in the order: root to left to right
{
	
    if (root) {
        printf(" %d ", root->val);
    }

    if(root->left) {
        printf("(");
        prefixPrint(root->left);
        printf(")");
    }

    if (root->right) {
        printf("(");
        prefixPrint(root->right);
        printf(")");
    }
}

//converting an array into a reverse BST
NodeAddress arrayToReverseBST(int *a, int n)
{
    NodeAddress root = NULL;
    for (int i = 0; i < n; i++) //running for loop to traverse along the array
    {
        if (i == 0) {
            root   = createNode(a[0]);  //adding first element of array as root of tree
        }
        else {
            root = insert(root, a[i]); //creating the leaves if i !=0 by calling the insert function
        }
    }
    return root;
}
int main(){
    int a[]={10, 15, 35, 21, 12, 8, 2};
    int n = sizeof(a) / sizeof(a[0]); // finding number of elements by dividing size of total array by size of one integer
    NodeAddress root = arrayToReverseBST(a, n);
    prefixPrint(root);
    return 0;
}
