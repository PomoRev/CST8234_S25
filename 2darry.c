/* 2darray.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-06-16
 */

#include <stdio.h>
#include <stdlib.h>

#define ROWS     4
#define COLS     6

int main(){

    /* iterators */

    int i, j;

    /* create the matrix in two dimensions, first a list for the pointers, 
       then initialize the list elements as pointers to lists of integers.
     */

    int ** array = (int **)malloc(ROWS * sizeof(int *));

    for(i=0; i<ROWS; i++){

        *(array + i) = (int *)malloc(COLS * sizeof(int));

    }

    /* initialize the martix, using pointer notation is the safest way 
       to traverse the 2 dimensional array. Note that we are using the outer
       * to derefernce the address and is the value of array+i. 
       You could read  *(*(array + i) + j) = as assign to the content of the
       pointer which is the content of the array at i and addressing the jth
       element of that array of integers at that location.
     */ 

    for(i=0; i<ROWS; i++){

        for(j=0; j<COLS; j++){
            *(*(array + i) + j) = 14 + j + i;
        }

    }

    /* use the matrix  */

    for(i=0; i<ROWS; i++){

        for(j=0; j<COLS; j++){
            printf(" %d ", *(*(array + i) + j));
        }
        printf("\n");
    }

    /* free matrix - note the order of operations here. If you free up
       the array first then you have no way to address the allocated integer
       arrays. So you need to do the free in the reverse order as you did 
       the creation.
     */



    for(i=0; i<ROWS; i++){

        free(*(array + i)) ;

    }

    free (array);

    /* Note that a more complete code would include guards against trying
       to use memory that was not actually allocated. Knowing that malloc() 
       will return a NULL pointer if it fails, is what you need to catch. 
     */ 


    return 0;
}


