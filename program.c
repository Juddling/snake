#include <time.h>

#include "snake.h"
#include "board.h"

int main()
{
    snake_initialise();

    int miliseconds = 200;
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = miliseconds * 1000 * 1000;

    while (true)
    {
        snake_advance();
        print_board();
        nanosleep(&t, NULL);
    }
}