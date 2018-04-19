#include <stdio.h>

typedef struct {
    int x;
    int y;
} position;

typedef struct {
    // using a struct within a struct
    position position;
    int length;
} snake;

void print_snake(snake s)
{
    printf("snake: x = %d, y = %d, length = %d", s.position.x, s.position.y, s.length);
}

int main()
{
    position p = { 1, 1 };
    snake s = { .position = p, .length = 10 };
    print_snake(s);
}