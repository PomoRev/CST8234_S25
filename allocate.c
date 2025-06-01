/* allocate.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-05-29
 */

#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

#define EXIT   10

char menu();
void displaylist(int * list);
int * addnumber(int * list);
int * purgelist(int * list);

int main(){

    char choice = 0;
    int * list = NULL;
    int * templist = NULL;
    list = purgelist(list);

    while (choice != EXIT){

        choice = menu();

        switch(choice){
            case 1 : displaylist( list );
                     break;
            case 2 : templist = addnumber( list );
                     if (templist != NULL) list = templist;
                     break;
            case 3 : list = purgelist( list );
        }
    }

    return 0;
}

char menu(){

    char choice = 0;
    char lettertocheck = 0;

    /* print out the menu of choices */

    system("clear");

    printf("MENU\n");
    printf("1. Display list of favourite numbers\n");
    printf("2. Add a new favourite number\n");
    printf("3. Purge the list\n");
    printf("\n4. Exit the program\n");

    /* accept input until valid choice made */     

    while (!choice){

        lettertocheck = getchar();

        if (lettertocheck > '0' && lettertocheck < '5') {
            choice = lettertocheck - '0';
        }
        else {
            choice = 0;
        }      

    }

    if (choice == 4) choice = EXIT;

    clearinputbuffer();

    return choice;

}

int * purgelist(int * list){

    /* free up current list and add a 0 element to the end which works like the 
       null termination of a string (tells me when to stop reading elements) */ 

    free(list);
    list = (int *)malloc(sizeof(int)); 
    *list = 0;

    return list;

}

void displaylist(int * list){

    /* display each element in the current list except the terminating element 
       with the value of 0. */

    int offset = 0;

    printf("\nMy favourite numbers are: ");
    while( * (list + offset) != 0){

        printf( "%d ", *(list + offset++));

    }

    printf("\npress enter to continue\n");
    clearinputbuffer();

    return;

}

int * addnumber (int * list){

    /* obtain a number from the user and if this number is not already a favourite add
       it to the list making sure to allocate enough memory for the new element.  */

    int numbertoadd = 0;
    int * workinglist = NULL;
    int numberfound = FALSE;
    int count = 0;

    printf( "What integer number would you like to add?: ");
    scanf ("%d", &numbertoadd );
    clearinputbuffer();
    
    while ( * (list + count) != 0 ){
        if ( * (list + count++) == numbertoadd ) numberfound = TRUE;
    }

    if (numberfound){ 
        printf("You already have that number.\n");
    } else 
        if ((workinglist = (int *) realloc( list, (sizeof(int) * (count + 1)))) == NULL ) 
            printf("\nnot enough memory!\n");
        
    if (workinglist != NULL){
                
            * (workinglist + (count++)) = numbertoadd;
            * (workinglist + (count)) = 0;

        }

    printf("Press enter to continue.\n");
    clearinputbuffer();

    return workinglist;

}



