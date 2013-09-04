
/*
 * Non-blocking input for Linux without using ncurses.
 *
 * http://cc.byexamples.com/2007/04/08/non-blocking-user-input-in-loop-without-ncurses/
 */

#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <sys/select.h>

#include "nb.h"


int
kbhit(void)
{
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds); /* STDIN_FILENO is 0 */
    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
} /* kbhit */


void
nonblock(int state)
{
    struct termios ttystate;
 
    /* get the terminal state */
    tcgetattr(STDIN_FILENO, &ttystate);
 
    if (state == NB_ENABLE) {
        /* turn off canonical mode */
        ttystate.c_lflag &= ~ICANON;
        /* minimum of number input read. */
        ttystate.c_cc[VMIN] = 1;
    } else if (state == NB_DISABLE) {
        /* turn on canonical mode */
        ttystate.c_lflag |= ICANON;
    }
    /* set the terminal attributes. */
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
 
} /* nonblock */
