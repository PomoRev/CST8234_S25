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

    int i, j;

    /* create the matrix */

    int ** array = (int **)malloc(ROWS * sizeof(int *));

    for(i=0; i<ROWS; i++){

        *(array + i) = (int *)malloc(COLS * sizeof(int));

    }

    /* initialize the martix */ 

    for(i=0; i<ROWS; i++){

        for(j=0; j<COLS; j++){
            *(*(array + i) + j) = 14 + j + i;
        }

    }

    /* use the matrix */

    for(i=0; i<ROWS; i++){

        for(j=0; j<COLS; j++){
            printf(" %d ", *(*(array + i) + j));
        }
        printf("\n");
    }

    /* free matrix */



    for(i=0; i<ROWS; i++){

        free(*(array + i)) ;

    }

    free (array);

    return 0;
}


