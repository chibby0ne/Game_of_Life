#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/game.h"


void evolveUniv(int rows, int cols, int univ[][cols])
{
    int new_univ[rows][cols];    // new temporary univ that holds new cells
    int i, j;
    int live_neighbours;

    for (i = 0; i != rows; i++) {
        for (j = 0; j != cols; j++) {
            live_neighbours = getNeighbours(i, j, rows, cols, univ);
            new_univ[i][j] = (live_neighbours == 3 || (live_neighbours == 2 && univ[i][j]));
        }
    }
    /* copy new_univ contents in univ for future display */
    for (i = 0; i != rows; i++) {
        for (j = 0; j != cols; j++) {
            univ[i][j] = new_univ[i][j];
        }
    }
}

int getNeighbours(int row_coord, int col_coord, int rows, int cols, int univ[][cols])
{
    int i, j;
    int live_neighbours = 0;
    for (i = row_coord - 1; i <= row_coord + 1; i++) {              // range [x - 1, x + 2)
        for (j = col_coord - 1; j <= col_coord + 1; j++) {          // range [y - 1, y + 2)
            if (univ[(i + rows) % rows][(j + cols) % cols] == 1) {  
                live_neighbours++; // modulus because each border is connected to the opposite one so, cells in borders have opposing border's cells as neighbours
            }
        }
    }
    if (univ[row_coord][col_coord] == 1) {  // substract cell evaluated
        live_neighbours--;
    }
    return live_neighbours;
}


void showUniv(int rows, int cols, int univ[][cols])
{
    int i, j;
    printEscapeCode(FIRST_BLOCK); // move to leftmost upmost block in terminal (coord: (1.1))
    for (i = 0; i != rows; i++) {
        for (j = 0; j != cols; j++) {
            if (univ[i][j]) {
                printEscapeCode(BLOCK);         // if cell is alive then print a block
            } else {
                printf(" ");                    // else if cell is dead then print a space
            }
        }
        printEscapeCode(NEXT_LINE);             //move cursor to next line
    }
    fflush(stdout);                             // flush output buffer in order to show new univ
}

int randomfun(void)
{
    return (rand() % 100) < Init_probability;
}

void initUniv(int rows, int cols, int univ[][cols])
{
    int i, j;
    srand(time(NULL));          // initialize seed rand (initial layout depends on system clock)
    for (j = 0; j != cols; j++) {
        for (i = 0; i != rows; i++) {
            univ[i][j] = randomfun();
        }
    }
}
