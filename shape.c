/* shape.c
 *
 * expects: a type of shape, a size of shape
 * output : shape or error (1)
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-05-12
 */

/* 
    1) read in and parse command line [done]
    2) ensure the commandline arguments are reasonable [done]
    3) set the size as a numeric value [done]
    4) create print function that take 
       a character and number to print (this combines the three 
       print functions needed)
    5) print shape of specified size (triangle, 
       square, diamond)     
*/

#include <stdio.h>
#include <string.h>

void printcharacter(int number, char toprintcharacter){

    int i = 0;

    for ( ; i < number; i++) printf("%c", toprintcharacter);

    return;

}

#define numberOfShapes  3
#define numberOfSizes   5

#define STAR            '*'
#define SPACE           ' '
#define NEWLINE         '\n'

#define FALSE           0

int main(int argc, char *argv[]){

    char error = FALSE;
    int i;
    char shapeFound = FALSE, sizeFound = FALSE;
    char *shapes[] = { "triangle", "square", "diamond"};
    char *sizes[] = { "smaller", "small", "normal", "big" , "bigger"};
    const int  sizeValues[] = { 3, 5, 8, 10, 15 };

/*      make sure that the command line holds legitimate values. */
        
    if ( argc != 3 ) error = 1;
    else {
            for (i = 0; i < numberOfShapes; i++ ){
                
                if (!strcmp(argv[1], shapes[i])) 
                    shapeFound = 1;

            }
            
            if (shapeFound == 0) error = 1;

            for (i = 0; i < numberOfSizes; i++){

/*      set the size as a numeric value (added into checking function so that we do not need 
        to create another loop.) */

                if (!strcmp(argv[2], sizes[i])) 
                    sizeFound = sizeValues[i];
            }

            if (sizeFound == 0) error = 1;

    }

    if (error){

        printf("shape: invalid option(s)\n");
        printf("Try 'shape [SHAPE] [SIZE]\n");

    }

    /* test the print */

    printcharacter(14, STAR);
    printcharacter(3, NEWLINE);

    return error;
}


