
/*
 * Non-blocking input for Linux without using ncurses.
 *
 * http://cc.byexamples.com/2007/04/08/non-blocking-user-input-in-loop-without-ncurses/
 */

/*
 * Engage or disengage non blocking
 */
#define NB_ENABLE 1
#define NB_DISABLE 2

void nonblock(int state);


/*
 * Non blocking keyboard reading
 */
int kbhit(void);
