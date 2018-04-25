#include "snake.h"
#include "board.h"

int main()
{
    snake_initialise();

    // todo: call this at a regular interval
    snake_advance();
    snake_advance();

    print_board();
}