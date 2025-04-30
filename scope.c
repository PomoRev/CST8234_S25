/* scope.c\
 *
 * Code to demonstrate the idea of scoping using C variables.
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-04-30
 */

#include <stdio.h>

void anotherScope (char passedLetter){

    static char localLetter = 'a';

    printf("\nlocalLetter from inside anotherScope: %c\n", localLetter++);
    printf("passedLetter from inside anotherScope: %c\n", passedLetter);

    return;
}

char globalLetter = 'A';

int main(){

    char localLetter = 'B';

    anotherScope('D');
    anotherScope(globalLetter);
    anotherScope(localLetter);

    printf("\nlocalLetter from inside main: %c\n", localLetter);
    printf("globalLetter from inside main: %c\n", globalLetter);

    return 0;
}


