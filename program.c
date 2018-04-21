#include <stdio.h>
#include <stdbool.h>

// output in colour https://stackoverflow.com/a/3219471
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

// board config
#define BOARD_X 10
#define BOARD_Y 10

typedef struct
{
    int x;
    int y;
} position;

typedef struct
{
    int nums[10];
    position body[255];
} snake;

// void debug_snake(snake s)
// {
//     printf("snake: x = %d, y = %d, length = %d", s.position.x, s.position.y, s.length);
// }

void print_green(const char *content)
{
    printf(ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, content);
}

bool is_snake(int x, int y)
{
    if (x == y) {
        return true;
    }

    return false;
}

void print_board()
{
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

int main()
{
    position p = {1, 1};
    position body[] = {p, p, p, p};

    snake s = {.nums = {5, 4, 3, 2, 1}};

    // print_green("@@@@");
    print_board();
    // debug_snake(s);
}