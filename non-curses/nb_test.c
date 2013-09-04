
#include <stdio.h>
#include "nb.h"

int
main(int argc, char *argv[])
{
    char c;
    int i=0;
 
    nonblock(NB_ENABLE);
    while(!i) {
        usleep(1);
        i=kbhit();
        if (i!=0) {
            c=fgetc(stdin);
            if (c=='q') {
                i=1;
            } else {
                i=0;
            }
        }

        fprintf(stderr,"%d ",i);
    }
    printf("\n you hit %c. \n",c);
    nonblock(NB_DISABLE);
 
    return 0;
} /* main */
