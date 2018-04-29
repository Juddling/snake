#include <time.h>
#include <ncurses.h>
#include <stdlib.h>

#include "snake.h"
#include "board.h"

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

int random_number(int minimum_number, int max_number)
{
    return rand() % (max_number + 1 - minimum_number) + minimum_number;
}

int main()
{
    snake_init();
    ncurses_init();
    random_init();

    // init food
    food.x = random_number(0, COLS);
    food.y = random_number(0, LINES);

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