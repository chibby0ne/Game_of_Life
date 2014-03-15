#ifndef GAME
#define GAME

#define BLOCK "07m \033[m"
#define CLEAR_SCREEN "2J"
#define FIRST_BLOCK "H"
#define NEXT_LINE "E"
#define CSI "\033["
#define HIDE_CURSOR "?25l"
#define SHOW_CURSOR "?25h"

extern int Init_probability;

int randomfun(void);
void showUniv(int rows, int cols, int univ[][cols]);
void initUniv(int rows, int cols, int univ[][cols]);
void playGame(int rows, int cols, int time);
void evolveUniv(int rows, int cols, int univ[][cols]);
int getNeighbours(int row_coord, int col_coord, int rows, int cols, int univ[][cols]);
int getTermSize(int *rows, int *cols);
void waitFor(unsigned int sec);
void printEscapeCode(char *s);
void help(void);

#endif 
