/* common defines (macros) */

#ifndef FALSE
    #define FALSE 0
#endif

#ifndef TRUE
    #define TRUE !FALSE 
#endif

typedef char bool;

/* utility structures */

/* utility functions */

void clearinputbuffer();
int  stringlen(char * string);
