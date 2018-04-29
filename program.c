#include <time.h>
#include <ncurses.h>
#include <stdlib.h>

#include "snake.h"
#include "board.h"
#include "food.h"

enum direction_t direction = Right;

void set_direction()
{
    int ch = getch();

    switch(ch) {
        case KEY_UP:
            direction = Up;
            break;
        case KEY_DOWN:
            direction = Down;
            break;
        case KEY_LEFT:
            direction = Left;
            break;
        case KEY_RIGHT:
            direction = Right;
            break;
    }
}

void random_init()
{
    srand(time(NULL));
}

int main()
{
    snake_init();
    ncurses_init();
    random_init();
    food_move();

    while (true)
    {
        clear();

        snake_advance(direction);
        print_board();
        print_food(food);

        refresh();

        set_direction();
    }

    ncurses_end();
}