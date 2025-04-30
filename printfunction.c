/* printfunction.c
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

int main(int argc, char *argv[]){

    int i = 1;

    if ( argc > 1 ) printf ("%12s %7s %6s\n", "Argument", " ", "Size");

    for(; i < argc; i++) printf("%-20.20s  %4d\n", argv[i], stingLength(argv[i]));

    return 0;
}


