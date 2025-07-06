/* linkedlist.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-07-06
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Word * Wordptr;

typedef struct Word{

    char * word;
    Wordptr next;

} Word;

int main(){

    char word[8] = "example";
    Wordptr startingpoint = NULL;
    Wordptr head = (Wordptr)malloc(sizeof(Word));
        
    head->word = word;
    head->next = NULL;

    startingpoint = head;

    while (startingpoint != NULL){
        printf("%s\n", startingpoint->word);
        startingpoint = startingpoint->next;
    }

    free(head);

    return 0;
}


