/* debugready.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-04-30
 */

#include <stdio.h>

#define DEBUG

int main(){

    printf("This always prints.\n");

    #ifdef DEBUG

        printf("This only prints when DEBUG is set\n");

    #endif

    #undef DEBUG

    #ifndef DEBUG

        printf("DEBUGGING turned off\n");

    #endif

    return 0;
}


