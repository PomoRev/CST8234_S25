/* utility.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-05-29
 */

#include <stdio.h>

void clearinputbuffer(){

    /* throw away extra characters on the input buffer */

    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    return;

}


