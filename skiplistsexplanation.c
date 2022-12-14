//Skip lists are a data structure used to traverse elements by skipping some in the middle. We can understand this through an example:
//For example: if we want to access the 50th floor in a hotel building, we can either take the normal elevator that stops at each floor or-
//Take a new elevator, which stops at every 10th floor.
//Assuming that the stop at each floor takes 5 seconds, in the first case, we will reach our desired floor in 250 seconds.
//However, if we went with the new or 'skipped' elevator, we will reach in 50 seconds.
//Similarly, if we want to search for a number in a linked list, we can either traverse all n elements in the worst case
//There, we will begin with the first node and then use pointers to get to the last/target one, one by one
//However, if we add something like a pointer to two nodes ahead, we can reach our target node much faster, so our time will not be worse than n/2 
//Similarly, skip lists have nodes that have multiple forward pointers, which helps us in reducing the time taken for lookups

//Now let us try implementing this on code:

struct Nodetype { //creating a node structure - for the normal case
  int val;
  struct Nodetype *Next; 
}

//for the skip list/fastened method- node 2:
struct Nodetype {
  int val;
  struct Nodetype **Fast; // or struct Nodetype *Next[]; (address of next) which is an array. a -> Next[0] -> Next[1] .......
}


int *a;
a = (int*) malloc (sizeof(int)*100) // array of size 100 karan doubt **Next pointer to a pointer
  
//Example done in class with professor (used notes given by classmates):
/*
[7][]
[6]
[5]
[4][]
[3]
[2]
[1][]
*/ 
// the lift concept and the numbwe of elevators accisible. 
  /*
// 1 - 2 - 3-4-5-6-7-8-9-10-11-12-13-14-15-16-17=18=19=-20-21-22-23-24-25-26-27-28-29-30 
lift 1: 1 - 2 - 3-4-5-6-7-8-9-10-11-12-13-14-15-16-17=18=19=-20-21-22-23-24-25-26-27-28-29-30 [c = head; c -> next[0] 
lift 2: 1-5-10-15-20-25-30 [c=head; c->next[1] 
lift 3: 1-10-20-30 [c = head; c-> next[2] 
to find where is 26, we go to fastest lift lift 3, 20<26 and 30>26 so we know 26 between 20 and 30 and stop at  20 
now go to lift 2: 25<26<30 
lift 3 25<26<27 you get your floor 
*/
  
//we are here randomising the jumps so that identity is secured and there is no lack of security
//we generate a number, rand, and an array 
x = (0,1)
rand = 1 
if (x<0.2) rand +=1; 1 //every 5th size 2 and every 10th size 3 array if number is 0.15 u get 2 elvators in location (numE = 1+1 ) 
if (x<0.1) rand +=1; //if number is less than 0.1 say 005 numE = 1+1+1 = 3 so u have 3 elevators in that location. 
