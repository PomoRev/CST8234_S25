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

typedef struct Tree Tree;

struct Tree {

    char * word;
    int count;
    Tree * lefty;
    Tree * righty;

};

char * getnxtword(FILE * fp);
char toLower(char ch) { 
    if ((ch >= 'A') && (ch <= 'Z')) ch += ('a' -'A'); 
    return ch;
}
Tree * addtotree(char *, Tree *);
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

            wordtreeroot = addtotree(word, wordtreeroot);

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

Tree * addtotree(char * word, Tree * treenode){

    int compare;

/*     check if tree node is null
        add new node here and end */ 

    if ( treenode == NULL ) {

        /* i have a new word */

        treenode = (Tree *)malloc(sizeof(Tree));

        treenode->word = word;
        treenode->count = 1;
        treenode->lefty = NULL; 
        treenode->righty = NULL;

        printf("added node for %s", treenode->word);

    } else {

    /*     move through the binary tree checking if the current word 
    in the a match, or > or < the word in the node. */

        compare = strcmp(word, treenode->word);

        if (compare > 0) 
            treenode->righty = addtotree(word, treenode->righty);
        else if (compare < 0) 
            treenode->lefty = addtotree(word, treenode->lefty);
        else 
            treenode->count++;

    }

    return treenode;
}