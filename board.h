#include "snake.h"

// board config
#define BOARD_X 10
#define BOARD_Y 10

// time delay for ncurses
#define DELAY   75

void print_board();
void print_food(food_t food);
void print_score();

void ncurses_init();
void ncurses_end();