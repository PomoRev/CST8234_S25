/* wordcount.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-04-27
 */

#include <stdio.h>

#define TRUE 1

int main(){

    char character, isWord;
    int words;

    words = isWord = 0;

    while ((character = getchar()) != '\n'){

        if (character == ' ' || character == '\t'){
            if (isWord == TRUE){
                words++;
                isWord = !TRUE;
            }
        } else isWord = TRUE;
    }

    printf("%d words\n", ++words);

    return 0;
}


