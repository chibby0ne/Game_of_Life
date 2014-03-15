#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "../headers/game.h"


int getTermSize(int *rows, int *cols)
{
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w)) {             //access terminal size struct
        printf("Error accessing terminal parameters\n");
        return -1;
    }
    *rows = w.ws_row;       // set terminal height
    *cols = w.ws_col;       // set terminal width

    return 0;

}

void printEscapeCode(char *s)
{
    printf("%s%s", CSI, s);
}


