/* lessmeow.c
 *
 * Version of the cat command for use as an explainer in class.
 * uses fgets()
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-07-13
 */

#include <stdio.h>

int main(int argc, char ** argv){

    char buffer[14];

    int error = 0;

    char * word;

    FILE * fptr = NULL;

    if (argc > 1) fptr = fopen(argv[1], "r");

    if (fptr){

        while ((fscanf(fptr, "%s", buffer) != EOF)) 
            printf ("%s\n", buffer);

    } else {
        printf("invalid file\n");
        error = 1;
    }

    return error;
}


