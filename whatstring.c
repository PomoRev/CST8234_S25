/* whatstring.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-05-12
 */

#include <stdio.h>

int main(int argc, char * argv[]){


    int i = 0;  /* if I want to see the program name. */
    for (;i<argc;i++) printf ( "string %d = %s\n", i, argv[i]);

    return 0;
}


