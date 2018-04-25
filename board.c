#include <stdio.h>

#include "board.h"
#include "snake.h"

// output in colour https://stackoverflow.com/a/3219471
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

void print_green(const char *content)
{
    printf(ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, content);
}

void clear_terminal()
{
    // woo escape codes
    printf("\033[H\033[J");
}

void print_board()
{
    clear_terminal();

    for (int y = 0; y < BOARD_Y; y++)
    {
        for (int x = 0; x < BOARD_X; x++)
        {
            if (is_snake(x, y))
            {
                print_green("@");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }
}