#include <time.h>
#include <ncurses.h>

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

int main()
{
    snake_initialise();

    // delay init
    int miliseconds = 200;
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = miliseconds * 1000 * 1000;

    // ncurses init
    initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
    timeout(200);

    while (true)
    {
        clear();

        snake_advance(direction);
        print_board();

        refresh();

        nanosleep(&t, NULL);
        set_direction();
    }

    endwin();

    // todo ncurses for keyboard input
}