/* memory.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-06-15
 */

#include <stdio.h>

void wait(){
    while (getchar() != '\n');
    return;
}

#define ROWS        3
#define COLUMNS     3

int main(){

    /* let us make an array */

    int simplearray[] = { 14, 2, 3, 4, 90, 2 };

    /* let us make a simple 2 dimensional array */

    int complexarray[ROWS][COLUMNS] = { { 12, 14, 2 }, { 63, 28, 19 }, { 5, 3, 89 } };
    /* a linear initialization of the exact same array:
        int complexarray[3][3] = { 12, 14, 2, 63, 28, 19 , 5, 3, 89 }; 
       this will make sense when you understand why we need to size it beforehand.
     */

    int * pointer = NULL;

    printf("A simple array can be initialized without sizing.\n");
    printf("And we can access each element using array notion.\n");
    printf("eg. int simplearray[] = { 14, 2, 3, 4, 90, 2 }; \n");
    printf("lets us access each element by an offset from the start.\n");
    printf("Therefore simplearray[3] will resolve to %d\n", simplearray[3]);

    /* the logic here is pointer logic, just with fancy array notation. */

    printf("\nbecause the array name is the location of the \n");
    printf("starting point of the array we can throw it's value in a pointer.\n");

    pointer = simplearray;

    printf("and we can use a pointer to get the exact same value %d\n", *(pointer+3));

    wait();

    printf("\n2 dimensional arrays are a bit different.\n");
    printf("For one thing they require the size of the array\n"); 
    printf("as part of the initialization.\n");

    printf("This allows the multidimensional array to form completely contiguous\n"); 
    printf("memory. Essentially just a big single array with the exception that\n");
    printf("dimension [row] tells it how many rows to skip before finding an element.\n");
    printf("So, complexarray[1][0] will be a %d.\n", complexarray[1][0]);

    wait();

    printf("\nAnd we can work with it quite simply using a bit of pointer math.\n");
    
    pointer = (int *) complexarray;

    printf("Using a pointer to the complexarray, we can say\n");
    printf("*((1 * row size)+(0 * column size)) to accomplish the same thing %d.\n", 
        *(pointer + (1 * ROWS) + (0 * COLUMNS)) );
    
    printf("\nThere are always trade offs when you simplify the structures.\n");
    printf("It is much easier to conceptualize a 2 dimensional array in\n");
    printf("contiguous memory space. But the limitations are the need to dimension\n");
    printf("the two dimensional array when you create it, so it has no flexibility\n");
    printf("to grow with you data.\n");

    printf("\nAdditionally, you are restricted to every row being an identical length.\n");
    printf("Not great for things like arrays of strings.\n");
    printf("This is where pointers to pointers come to the rescue.");

    wait();

    return 0;
}


