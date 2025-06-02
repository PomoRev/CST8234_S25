/* indirection examples
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-05-28
 */

#include <stdio.h>

int main(){

    /* declare and initialize a variable in this scope */

    int number = 0;
    
    /* declare and initialize an integer pointer with the value of NULL */

    int * pointer = NULL;

    /* get the address of where number is located in memory 
       and put that in the pointer */

    pointer = &number;

    /* use the pointer to change the value at the location it points to */

    *pointer = 12;

    /* demonstrate that the pointer was indeed pointing to the regular variable */

    printf( " number is %d\n", number);

    printf( " pointer points to this location %lx\n", (unsigned long int) pointer );

    printf( " is it the same location as number? %lx\n", (unsigned long int) &number );

    printf( " my 64bit system it uses 6byte number or 48bit addresses.\n");

    return 0;
}


