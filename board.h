#include "snake.h"

// board config
#define BOARD_X 10
#define BOARD_Y 10

// time delay for ncurses
#define DELAY   50

void print_board();
void print_food(food_t food);

void ncurses_init();
void ncurses_end();