/* meow.c
 *
 * Version of the cat command for use as an explainer in class.
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-07-13
 */

#include <stdio.h>

int main(int argc, char ** argv){

    int error = 0;
    char ch;
    FILE * fptr = NULL;

    if (argc > 1) fptr = fopen(argv[1], "r");

    if (fptr){

        while ((ch = fgetc(fptr)) != EOF) printf ("%c", ch);

    } else {
        printf("invalid file\n");
        error = 1;
    }

    return error;
}


