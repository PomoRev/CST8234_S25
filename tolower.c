/* filename.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-07-21
 */

#include <stdio.h>

char tolower(char ch) { 
    if ((ch >= 'A') && (ch <= 'Z')) ch += ('a' - 'A'); 
    return ch;
}

int main(){


    char totest = 'G';

    printf("%c \n", tolower(totest));

    return 0;
}


