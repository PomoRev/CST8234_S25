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
    Wordptr prev;

} Word;

int main(){

    Wordptr head;
    char word[8] = "example";
    Wordptr startingpoint = NULL;

    head = (Wordptr)malloc(sizeof(Word));
        
    head->word = word;
    head->next = NULL;
    head->prev = NULL;

    startingpoint = head;

    while (startingpoint != NULL){
        printf("%s\n", startingpoint->word);
        startingpoint = startingpoint->next;
    }

    free(head);

    return 0;
}


