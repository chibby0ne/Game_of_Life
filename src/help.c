#include <stdio.h>
#include "../headers/game.h"

void help(void)
{
    printf("Usage: ./gameoflife [OPTION]\n");
    printf("Simulates the John Conway's game of life \n");
    printf("\n");
    printf("Options:\n");
    printf("-w              Set width of the terminal to be used the simulation (default: width of terminal window)\n");
    printf("-h              Set height of the terminal to be used the simulation (default: height of terminal window)\n");
    printf("-r              Set refresh time of the terminal in useconds (default: 0.2 sec) (time between generations of cells)\n");
    printf("-p              Set initial probability of living cell in percentage (default: 10)\n");
    printf("-h              Show this help and exit\n");
    printf("Written by Antonio Gutierrez\n");

}
