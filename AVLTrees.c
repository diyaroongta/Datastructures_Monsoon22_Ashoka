#include<stdio.h>
#include<stdlib.h>
 

struct Node
{
    int a;
    struct Node *left;
    struct Node *right;
    int height;
}; typedef struct Node* nodeAddress;  


int compare(int p, int q) //return larger of two numbers
{
    if(p>q)
    return p;
    else
    return q;
}

// finding the height of the tree 
int height(nodeAddress N) 
{
    if (N == NULL)  
        return 0;
    return N->height;
}
 

 
nodeAddress new_node(int a)
{
    nodeAddress node = (nodeAddress)malloc(sizeof(struct Node)); 
    node->a   = a;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  
    
    return(node);
}

int balancing_factor(nodeAddress N)
{
    int n;
    n = height(N->left) - height(N->right); 
    if (N == NULL)
        return 0;
    return n; 
}

nodeAddress right_rotate(nodeAddress q)
{
    nodeAddress p = q->left; 
    nodeAddress t = p->right;
 
    // rotating the tree 
    p->right = q;
    q->left = t;
 
    // heights change 
    q->height = compare(height(q->left),height(q->right)) + 1; 
    p->height = compare(height(p->left),height(p->right)) + 1;
 
  
    return p;
}
 
nodeAddress left_rotate(nodeAddress p)
{
    nodeAddress q = p->right;
    nodeAddress t = q->left;
 

    q->left = p;
    p->right = t;
 

    p->height = compare(height(p->left),  height(p->right)) + 1;
    q->height = compare(height(q->left),height(q->right)) + 1;
    return q;
}
 

 
nodeAddress insert(nodeAddress node, int a) {
    
    if (node == NULL) 
        return(new_node(a)); 
 
    if (a < node->a) 
        node->left  = insert(node->left, a);
    else if (a > node->a)
        node->right = insert(node->right, a);
    else 
        return node;
 
    node->height = 1 + compare(height(node->left),height(node->right));
 
    int n = balancing_factor(node);
 

    if (n < -1 && a > node->right->a) 
        return left_rotate(node);
        
    // Left Left Case
    if (n > 1 && a < node->left->a)
        return right_rotate(node);

    // Left Right Case
    if (n > 1 && a > node->left->a)
    {
        node->left =  left_rotate(node->left);
        return right_rotate(node);
    }
 
    // Right Left Case
    if (n < -1 && a < node->right->a)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    
    return node;
}
 
void print(nodeAddress node)
{
    if(node != NULL)
    {
        printf("%d ", node->a);
        print(node->left);
        print(node->right);
    }
}
 

int main() 
{
  nodeAddress root = NULL;
 

  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 3);
  root = insert(root, 4);
  root = insert(root, 5);
  root = insert(root, 6);
 
  print(root);
 
  return 0;
}
