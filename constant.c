#include<stdio.h>
#include<stdlib.h>
int main()
{
    const int var = 10;
      
    int *ptr = &var;
    *ptr=12;
      
    printf("var = %d\n", var);
    printf("*ptr = %d\n", *ptr);
    
    return 0;
}