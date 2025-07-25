/* btree.c   -> aw (analyze words)
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-07-20
 */

/*      THE CHALLENGE:
        This program reads in a file of words using fscanf() and 
        adds the words to a binary tree. When a duplicate word is found
        a count in that word's structure will be incremented. 
        The program will then print out the words in order (DFS) with 
        the count of each individual word. 
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



    int error = 0;
    FILE * fp = NULL;
    Tree * wordtreeroot = NULL;
    char * word = NULL;

    /* open the file */

    if (argc > 1) 
        fp = fopen(argv[1], "r");
    else
        error = 1;

    if (fp){
        /* loop through the file */

        while ((word = getnxtword(fp))){

            /* add fetched word to the tree */

printf("[%s]", word);

        }

printf("\n");

        /* done with the file, so we close it */
        
        fclose(fp);

    }

    
    /* print the tree with counts */


    return error;
}

char * getnxtword(FILE * fp){

/*  takes a file pointer to an open file and fetches characters 
    until it finds a word to return or NULL if the file end is reached. 
 */

    char buffer[BUFFERSIZE];
    char ch;
    int i, count = 0;
    char * newword = NULL;

    /* throw away non alphabetic characters and catch the end of the file */

    while (((ch = toLower(fgetc(fp))) < 'a') || (ch > 'z'))
        if (ch == EOF) break;

    /* if we have a an alphabetic collect it with any 
       following letters in the buffer */

    if (ch != EOF){

        do { 

            buffer[count++] = ch;

            /* get another possible letter */

            ch = toLower(fgetc(fp));

        } while((ch >= 'a') && (ch <= 'z') && (count < (BUFFERSIZE))); 

        /* if we have a word send back a pointer to it */

        if (count > 0){
            newword = (char *) malloc (sizeof(char) * (count + 1));

            /* copy the word into the allocated space */

            for(i=0; i < count; i++) 
                newword[i] = buffer[i];

            /* make it a real string by ending with a null character */

            newword[count] = '\0';

        } 
    }

    return newword;
}

