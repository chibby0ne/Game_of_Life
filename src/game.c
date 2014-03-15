#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../headers/game.h"

/* external variables */
int Init_probability;

void playGame(int rows, int cols, int time)
{
    int univ[rows][cols];

    initUniv(rows, cols, univ);
    while (1) {
        showUniv(rows, cols, univ);
        evolveUniv(rows, cols, univ);
        usleep(time);
    }

}

int main(int argc, const char *argv[])
{
    int rows, cols;
    int width = 0;
    int height = 0;
    int refresh_time = 0;
    int time;

    /* get commmand-line arguments */
    while (--argc > 0 && (*++argv)[0] == '-') {
        char c = (*argv)[1];
        --argc;
        if (argc > 0) {
            switch (c) {
                case 'w':
                    width = atoi(*++argv);
                    break;
                case 'h':
                    height = atoi(*++argv);
                    break;
                case 'r':
                    refresh_time = atoi(*++argv);
                    break;
                case 'p':
                    Init_probability = atoi(*++argv);
                    break;
                case 'H':
                    help();
                    return 0;
                default:
                    printf("\"I'm sorry Dave. I'm afraid I can't let you do that\". (%s) is not a valid option \n", *argv);
                    printf("Exiting...\n");
                    return -1;
            }
        } else {
            printf("Error. Missing argument for option selected (%s)\n", *argv);
            printf("Exiting...\n");
            return -1;
        }
    }

    if(getTermSize(&rows, &cols) == -1) {    // get terminal size
        return -1;                           // return -1 if error accessing terminal properties
    }
    /* check if width was entered by user and if it's a valid size */
    if (width != 0 && width <= cols) {
        cols = width;
    }
    /* check if height was entered by user and if it's a valid size */
    if (height != 0 && height <= rows) {
        rows = height;
    }
    if (refresh_time != 0) {
        time = refresh_time;
    } else {
        time = 200000;              // default refresh time= 0.2s
    }
    if (Init_probability <= 0 || Init_probability >= 100) {
        Init_probability = 10;
    }
    playGame(rows, cols, time);
    return 0;
}
