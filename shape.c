/* shape.c
 *
 * expects: a type of shape, a size of shape
 * output : shape or error (1)
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-05-12
 */

/* parse command line 
    1) read it in 
    2) ensure the commandline arguments are reasonable
    3) set the size as a numeric value
    4) create print function that take 
       a character and number to print
    5) print shape of specified size (triangle, 
       square, diamond)     
*/

#include <stdio.h>
#include <string.h>



int main(int argc, char *argv[]){

    char error = 0;
    int i, ii;
    char shapeFound = 0;
    char shapes[3][10];

    strcpy(shapes[0], "triangle");
    strcpy(shapes[1], "square");
    strcpy(shapes[2], "diamond");

    if ( argc > 3 ) error = 1;

    else {
            for (ii = 0; ii < numberShapes; ii++ ){
                if (!strcmp(argv[1], shapes[ii])) 
                    shapeFound = 1;
            }
            
            if (shapeFound == 0) error = 1;



    }

    return error;
}


