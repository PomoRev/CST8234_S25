/* NOTE NEEDS SOME DEBUGGING, RAN OUT OF TIME! */



/* hexed.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-07-12
 */

#include <stdio.h>
#include <string.h>

#define BYTEWIDTH    8

void printhexlines(size_t startingpoint, unsigned char * datastream, size_t length){

/*         takes a starting point (offset), a data array, and the number of bytes
        to print. Then prints them formatted padding to the nearest BYTEWIDTH 
        size and numbering the lines. */

        size_t i;
        static int line;
        
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


int main( int argc, char * argv[] ){

    char choice, dump;
    FILE * fp = NULL;
    unsigned char buffer[BYTEWIDTH];
    size_t bytesread;
    size_t offset;

    /* open the binary file for display of stored bytes */

    if( argc > 1 ){
        fp = fopen( argv[1], "rb" );        
    }

    /* if error found, report and bail on programme  */

    if (!fp){
        printf("Unable to open file.\n");
        return 1;
    }

    /* control loop */

    printf("File Ready (l/q): ");

    while (((choice = getchar()) != 'q') && (choice != 'Q')){

        offset = 0;
        while ((bytesread = fread(buffer, 1, BYTEWIDTH, fp)) > 0){

            printhexlines( offset, buffer, bytesread);
            offset += bytesread;
        
        }      

        while (((dump = getchar()) != '\n') && (dump != EOF));
        printf("Ready (l/q): ");

    }

    /* close file before exiting */

    fclose(fp);
    printf("\n");

    return 0;
}


