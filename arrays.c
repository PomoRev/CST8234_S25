/* arrays.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-04-30
 */

#include <stdio.h>

int stingLength (char *string){
    int i = 0;
    while(string[i++] != '\0');
    
    return i - 1;
}

int countValues (int arraySize, int array[]){

    int i, count = 0;
    for (i = 0; i < arraySize; i++) if (array[i] != 0) count++;
    
    return count;
}

int main(int argc, char *argv[]){

    int i;
    int argumentLengths[10];

    for (i = 1; i <  argc; i++){

        printf("Argument #%d: %s", i + 1, argv[i]);
        printf(" has %d characters\n", stingLength(argv[i]));

        if (i < 10) argumentLengths[i - 1] = stingLength(argv[i]);

    }

    for (i = 0; i < 10; i++){
        printf("%d", argumentLengths[i]);
        if (i < 9) printf(", ");
        else printf(".\n");
    };

    printf("I only counted %d strings.\n", countValues(10, argumentLengths));

    return 0;
}




