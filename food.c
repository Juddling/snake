#include <stdlib.h>
#include <ncurses.h>
#include "snake.h"

int random_number(int minimum_number, int max_number)
{
    return rand() % (max_number + 1 - minimum_number) + minimum_number;
}

void food_move()
{
    food.x = random_number(0, COLS);
    food.y = random_number(0, LINES);
}

// these are both aliases for the same struct but there's no nice way of comparing
// https://stackoverflow.com/q/141720
bool is_food(snake_t *node, food_t food)
{
    return node->position.x == food.x && node->position.y == food.y;
}