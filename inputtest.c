/* inputtest.c
 *
 * Programme to demonstrate the issues with scanf using the input stream,
 * what is going on with this code? 
 * NOTE: this code is doing exactly what it is being asked to do. 
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-05-18
 */

#include <stdio.h>

int main(){

    int number1 = 0;
    int number2 = 0;
    char letter = 'b';
    
    printf("Enter two numbers:");
    scanf("%d %d", &number1, &number2);

    printf("you entered [%d] and [%d]\n\n", number1, number2);

    printf("Enter a letter and a number:");
    scanf("%c %d", &letter, &number2);
    
    printf("you entered [%c] and [%d]\n\n", letter, number2);

    printf("Enter two numbers: ");
    scanf("%d %d", &number1, &number2);
    printf("the problem is not resolved number 1 is [%d] and number 2 is [%d]\n", number1, number2);

    return 0;
}


