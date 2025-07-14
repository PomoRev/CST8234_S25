/* bark.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-07-14
 */

#include <stdio.h>

int main( int argc, char ** argv ){

    /* set up the counters */

    char ch;
    int error = 0;
    int lines = 0;
    int words = 0;
    int chars = 0;
    char inword = 0;

    FILE * fptr = NULL;

    if ( argc > 1 ) fptr = fopen(argv[1], "r");

    if (fptr){

        /* guts of the program bark! */

        while((ch = fgetc(fptr)) != EOF){

            if( ch != '\n' ) chars++;
            if( ch == '\n' ) lines++;

            if (!inword)
                if ( ((ch >= 'a') && (ch <= 'z')) 
                    || ((ch >= 'A') && (ch <= 'Z')) ) inword = 1;

            if ( inword && 
                ((ch == ' ') || (ch == '\t') 
                || (ch == '\n'))){

                    words++;
                    inword = 0;
                }

        }



        if ( lines > 0 ) lines++;
        if (inword) words++;

        fclose(fptr);

        printf("%d lines %d words %d characters. woof woof!\n", 
                lines, words, chars );


    } else {

        printf("Woof! I don't see that one.\n");
        error = 1;
    }

    return error;
}


