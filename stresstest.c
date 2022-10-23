#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

    float i;
    float increment = 0.000000000001; //At this value, when we try to increment it upto n, it should be 100 times increment but the system gives 101 increments
    float n = 0.0000000001; 
    int count = 1;

    for (i=0.0; i<n; i+=increment) {
        printf("Loop Number: %d\n", count);
        printf("Value: %f\n", i);
        count++;
    }

    return 0;
}

