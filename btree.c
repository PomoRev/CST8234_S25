/* btree.c   -> aw (analyze words)
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-07-20
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE  20

typedef struct {

    char * word;
    int count;
    struct Tree * lefty;
    struct Tree * righty;

} Tree;

char * getnxtword(FILE * fp);
char toLower(char ch) { 
    if ((ch >= 'A') && (ch <= 'Z')) ch += ('a' -'A'); 
    return ch;
}
void addtotree(char *, Tree *);
void printtree(Tree *);

int main(int argc, char ** argv){

/*     This program reads in a file of words using fscanf() and 
    adds the words to a binary tree. When a duplicate word is found
    a count in that word's structure will be incremented. 
    The program will then print out the words in order (DFS) with 
    the count of each individual word. */

    FILE * fp;
    char buffer[BUFFERSIZE];
    Tree * wordtreeroot = NULL;
    char * word = NULL;

    /* open the file */

    if (argc > 1) 
        fp = fopen(argv[1], "r");

    if (fp){
        /* loop through the file */

        word = getnxtword(fp);
        printf("%s\n", word);

        while (((word = getnxtword(fp)))){
            printf("%s\n", word);
        }
        
        /* get the next word */

        /* add to the tree */
    }





    /* print the tree with counts */


    return 0;
}

char * getnxtword(FILE * fp){

    char buffer[BUFFERSIZE];
    char ch;
    int i;
    int count = 0;
    char * newword = NULL;

    while( (ch = toLower(fgetc(fp)) < 'a') || ch > 'z' );

    do { 

        ch = toLower(ch);
        buffer[count++] = ch;

    } while( (ch = fgetc(fp)) && (count < (BUFFERSIZE - 1)) );

    if (count > 0){
        newword = (char *) malloc (sizeof(char) * (count + 1));

        for(i=0; i < count; i++) 
            newword[i] = buffer[i];
        newword[count] = '\0';

        printf("i saw [%s] this many characters %d\n", newword, count);
    }

    return newword;

}

