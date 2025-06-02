/* lecture4example.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-06-02
 */

#include <stdio.h>
#include <stdlib.h>

int main(){

    char i;
    char * bob = NULL;

    bob = (char *)malloc(sizeof(char) * 16);

    for (i=0;i<16;i++) 
        *(bob + i) = i + 'A';

    printf( "%c and %c\n", (char)*bob, (char)*(bob+3));

    return 0;
}


