#include <stdio.h>

void displaySpace(char * space, int height, 
                  int width, int depth){

    int i, j, k, offset = 0;
 
    for (i = 0; i < depth; i++){
        for(j = 0; j < (width + 2); j++) 
             printf ("#");
        printf(" ");
    }
    printf("\n");

    for (i = 0; i < height; i++){
        printf("#");
        for (j = 0; j < depth; j++){
            for(k = 0; k < width; k++){
              printf("%c", *(space + offset++));
            }
            if (j < (depth - 1)) printf("# #");
        }
        printf("#\n");      
    }  

    for (i = 0; i < depth; i++){
        for(j = 0; j < (width + 2); j++) 
             printf ("#");
        printf(" ");
    }
    printf("\n");

    return;
}

int main(){

    int i;
    char array[36];

    for (i = 0; i < 36; i++) 
        array[i] = (i < 18) ? ('a' + i) 
                          : ('A' + (i - 18));

    displaySpace(array, 3, 3, 4);
    return 0;
}


