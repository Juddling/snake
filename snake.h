#include <stdbool.h>
#include <sys/queue.h>

#ifndef SNAKE_H_
#define SNAKE_H_

#define SNAKE_INITIAL_LENGTH 5

typedef struct
{
    int x;
    int y;
} position_t, food_t;

// snake is just a singley linked list
typedef struct _snake
{
    position_t position;
    SLIST_ENTRY(_snake) next;
} snake_t;

enum direction_t { Up, Down, Left, Right };

// creates a stuct for the head of the list
SLIST_HEAD(head_s, _snake) head;

bool is_snake(int x, int y);
void snake_init();
void snake_advance();

food_t food;

#endif