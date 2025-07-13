/* hexed.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-07-12
 */

#include <stdio.h>
#include <string.h>

#define BYTEWIDTH    8

void printhexline(size_t startingpoint, char * datastream, size_t length){

/*         takes a starting point (offset), a data array, and the number of bytes
        to print. Then prints them formatted padding to the nearest BYTEWIDTH 
        size and numbering the lines. */

        size_t i;
        int line = 0;
        
        for (i=startingpoint; i < (startingpoint + length); i++){

            if ( (i % 8) == 0 ) printf("\nLine %.4d:", line++);
            if ( (i % 2) == 0 ) printf(" ");
            printf("%02X", datastream[i]);

        }

        for (i -= (BYTEWIDTH * --line); i < BYTEWIDTH; i++) {
            if ( (i % 2) == 0 ) printf(" ");
            printf ("--");
        }

        printf("\n");
        return;
}


int main(){

    char array[] = "so this is what a bunch of text looks like to the computer.";

    printhexline( 0, array, strlen(array));

    return 0;
}


