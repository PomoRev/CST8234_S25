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
       a character and number to print
    5) print shape of specified size (triangle, 
       square, diamond)     
*/

#include <stdio.h>
#include <string.h>

#define numberOfShapes  3
#define numberOfSizes   5

int main(int argc, char *argv[]){

    char error = 0;
    int i;
    char shapeFound = 0, sizeFound = 0;
    char *shapes[] = { "triangle", "square", "diamond"};
    char *sizes[] = { "smaller", "small", "normal", "big" , "bigger"};
    int  sizeValues[] = { 3, 5, 8, 10, 15 };

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

    if (!error){

        /* temporary test code to check that number is assigned properly */

        error = sizeFound;

    }

    return error;
}


