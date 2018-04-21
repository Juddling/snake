#include <stdio.h>

// output in colour https://stackoverflow.com/a/3219471
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

typedef struct
{
    int x;
    int y;
} position;

typedef struct
{
    // using a struct within a struct
    position position;
    int length;
} snake;

void debug_snake(snake s)
{
    printf("snake: x = %d, y = %d, length = %d", s.position.x, s.position.y, s.length);
}

void print_green(const char *content)
{
    printf(ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, content);
}

int main()
{
    position p = {1, 1};
    snake s = {.position = p, .length = 10};
    print_green("@@@@");
    // debug_snake(s);
}