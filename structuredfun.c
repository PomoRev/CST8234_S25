/* looking as structure syntax
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2025-06-30
 */

#include <stdio.h>
#include "utility.h"

#ifndef BOOL 
    #define BOOL
    typedef char bool;
#endif

#define BLUE  2

/* data structures */

typedef struct {
    int x;
    int y;
} Location ;

typedef struct {
    int height;
    int width;
    bool active;
} Hitbox;

struct Bonhomme {
    Location location;
    Hitbox hitbox;
    char colour;
    char health;
};

struct Enemy {
    Location location;
    Hitbox hitbox;
    char colour;
    char health;
    int aggression;
};


/* functions */

int main(){

    struct Bonhomme hero;
    struct Enemy boss = { 0,0, 10,10, 1, BLUE, 100};

    printf("I have a %d hero.\n", hero.colour);
    printf("But the big bad guy is %d aggressive!\n", boss.hitbox.active);

    printf("%d is how big the structure location is.", (int)sizeof(Location));

    clearinputbuffer();

    return 0;
}


