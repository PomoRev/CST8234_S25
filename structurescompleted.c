/* structurescompleted.c
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-06-25
 *
 * Code to help identify patterns in programming problems and match them
 * structures for implementation.
 * 
 * Use this code to check your own work against.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* bounds definitions program can scale on these numbers */

#define     WIDTH  3
#define     HEIGHT 3
#define     DEPTH  4

/* define utility macros and types using header guards */ 

#ifndef FALSE
    #define     FALSE  0
#endif

#ifndef BOOL
    #define BOOL
    typedef char bool;
#endif

typedef struct {
    int x;
    int y;
    int z;
    bool live;
} Coordinates;

/* ENTITY FUNCTIONS */

Coordinates * createentity( int x, int y, int z ){

    /*  dynamically creates an entity and returns a pointer
        to that entity to the calling environment */

    Coordinates * entity;

    entity = (Coordinates *)malloc(sizeof(Coordinates));

    entity->x = x;
    entity->y = y;
    entity->z = z;
    entity->live = !FALSE;

    return entity;

}

bool collision( Coordinates * entity1, Coordinates * entity2 ){

    /* do the entities occupy the same space? */ 

    return ((entity1->x == entity2->x) && (entity1->y == entity2->y) && (entity1->z == entity2->z));

}

void moveentity( Coordinates * entity){

/*     Directions   1   2   3
                    4   *   5
                    6   7   8   with 9 and 10 moving you backward or forward on z axis.
*/

    int direction = (rand() % 10) + 1;

    /* deal with x coordinate  */

    if ( ((direction == 1) || (direction == 4) || (direction == 6)) 
        && (entity->x > 0) ) entity->x -= 1;
    if ( ((direction == 3) || (direction == 5) || (direction == 8)) 
        && (entity->x < (HEIGHT - 1)) ) entity->x += 1;

    /* deal with y coordinate */ 

    if ( ((direction == 1) || (direction == 2) || (direction == 3)) 
        && (entity->y > 0) ) entity->y -= 1;
    if ( ((direction == 6) || (direction == 7) || (direction == 8)) 
        && (entity->y < (WIDTH - 1)) ) entity->y += 1;

    /* deal with z coordinate */

    if ( (direction == 9) && (entity->z > 0) ) entity->z -= 1;
    if ( (direction == 10) && (entity->z < (DEPTH - 1)) ) entity->z += 1;

    return;

}

/* GRID FUNCTIONS  */

void plotentity( char * grid, Coordinates * entity, char representation ){

    /* put the entity into the three dimensional space */ 

    *(grid + (entity->z * (HEIGHT * WIDTH)) + (entity->x * HEIGHT)  + entity->y) = representation;

    return;
}

void resetgrid( char * grid ){

    /* blank out the grid */ 

    int i;

    for (i=0; i < (WIDTH * HEIGHT * DEPTH); i++ ) *(grid +i) = ' ';

    return;
}

void displayGrid( char grid[(WIDTH * HEIGHT) * DEPTH] ){

    /*  display the grid, think about how you would need
        to change this code to print the planes beside each other
        on the command line? */ 

    int j, k, l, i = 0;
    
    for (k=0; k<DEPTH; k++){
        printf("Level %d\n", k+1);
        for(l=0;l<(WIDTH + 2);l++) printf ("#");
        printf("\n");
        for (; i<(HEIGHT + (HEIGHT * k)); i++){
            printf("#");
            for (j=0; j<WIDTH; j++) printf("%c", grid[(i * WIDTH) + j] );
            printf("#\n");
        }
        for(l=0;l<(WIDTH + 2);l++) printf ("#");
        printf("\n");
    }

    return;
}

int main(){

    /*  make two instances of the Coordinates structure wander 
        around a 3X3X2 grid until they collide. Show their progress 
        and kill them when they collide. Report the collision with 
        a simple message: 'boom!' 

        think about how you could modify this code to add a third
        player entity and reporting the first collision between the 
        enemy and one of the player entities, announcing the non-colliding
        entity (if one exists) as the winner. (Will this effect the data
        model? if so how?)

        think about making the number of player entities scale
        to a value that is macro defined (like HEIGHT, WIDTH, etc.)
    */

    Coordinates * player;
    Coordinates * enemy;
    char grid[(WIDTH * HEIGHT) * DEPTH];

    srand(time(NULL));  /* seeds the pseudo random number generator from the clock */     
   
    /* initialize grid */

    resetgrid(grid);
    
    /* create entities */

    player = createentity( 0, 0, 0 );
    enemy = createentity( HEIGHT - 1, WIDTH - 1, DEPTH - 1 );

    /* plot entities  */

    plotentity( grid, player, 'P' );
    plotentity( grid, enemy, 'Z' );

    displayGrid(grid);

    /* move entities */

    while (!collision( player, enemy )){

        moveentity(player);
        moveentity(enemy);
        resetgrid(grid);
        plotentity( grid, player, 'P' );
        plotentity( grid, enemy, 'Z' );
        displayGrid(grid);
        
    }

    /* report collision */

    printf("BOOM!\n");

    /* clean up memory */

    free(player);
    free(enemy);

    return 0;
}


