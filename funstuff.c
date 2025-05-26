/* funstuff.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-05-26
 */

#include <stdio.h>

/* returnType functionName ( type name pair(s) ){

    declarations
    
    instructions

    return (value);
} */

int main(){

    int i = 0;

    /* printf(" %d is it also %x and %o. ", 14, 14, 14); */

    for( ; i < 256; i++) 
        if ( i != 27 ) printf ("%d is [%c]\n", i, i );

    return 0;
}


