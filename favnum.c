/* filename.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-06-02
 */

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0

void displaylist( int * thelist){

    /* input: list of ints
       return: void
       function: prints the list until it hits -1
    */

    while( *thelist != -1 )
        printf ("%i ", *(thelist++));
    printf(".\n");

    return;
}

int countlist (int * thelist){

    int count = 1;
    while ( *(thelist++) != -1) count++;
    return count;

}


int * addnumber( int * thelist){

    /* input: list of ints
       return: the updated pointer to an expanded list
       function: get a number and add it to the list, 
        if successful send back a new list pointer.
    */

    int numbertoadd = -1;
    int numberofnumbers = 0;
    int * templist = thelist;

    printf("gimme some number love: ");
    scanf("%d", &numbertoadd );

    if (numbertoadd < 0){

        printf("come on man, are you serious!\n");

    } else {

        numberofnumbers = countlist( thelist );
        thelist = (int *)realloc( thelist, (sizeof(int) * (numberofnumbers + 1)));

        if (thelist != NULL){

            *(thelist + numberofnumbers++) = numbertoadd;
            *(thelist + numberofnumbers) = -1;
            templist = thelist;
        }
    }

    return templist;

}


int main(){

/* create an empty list (empty is -1)*/

    char exit = FALSE;
    int  choice = 0;
    int * numberlist = (int *)malloc( sizeof(int) );

    *numberlist = -1;

    while (!exit){
        /*     show menu */

        printf("hey there choose one of these!\n");
        printf("1 for display list\n");
        printf("2 for add a number\n");
        printf("3 for purge list\n");
        printf("4 for exit!\n");
        printf("your choice: ");
/*     get choice */
        scanf("%d", &choice );
/*     switch on choice */

        switch(choice){
            case 1 : displaylist(numberlist);
                     break;

            case 2 : numberlist = addnumber(numberlist);
                     break;

            case 4 : exit = !FALSE;
                     printf("bye\n");
                     break;

            default : printf( "no clue what that means!/n");

        }

/*         display list */

           
/*         add number to list */
/*         purge list */

           

    }



    return 0;
}


