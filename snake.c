#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

#include "snake.h"

bool is_snake(int x, int y)
{
    snake_t *n;

    SLIST_FOREACH(n, &head, next)
    {
        if (x == n->position.x && y == n->position.y) {
            return true;
        }
    }

    return false;
}

// sets up the snake's initial position
void snake_initialise()
{
    SLIST_INIT(&head);

    position p = {1, 1};
    snake_t *node;

    // add three nodes to the snake
    for (int i = 0; i < SNAKE_INITIAL_LENGTH; i++)
    {
        node = malloc(sizeof(snake_t));
        node->position = p;

        SLIST_INSERT_HEAD(&head, node, next);
        p.y++;
    }
}

int direction_x(enum direction_t direction)
{
    switch (direction) {
        case Left:
            return -1;
        case Right:
            return 1;
        default:
            return 0;
    }
}

int direction_y(enum direction_t direction)
{
    switch (direction) {
        case Up:
            return -1;
        case Down:
            return 1;
        default:
            return 0;
    }
}

void remove_last()
{
    snake_t *n, *prev;

    SLIST_FOREACH(n, &head, next)
    {
        if (n->next.sle_next == NULL) {
            SLIST_REMOVE(&head, prev, _snake, next);
            free(prev);
        }

        prev = n;
    }
}

// move the snake
void snake_advance(enum direction_t direction)
{
    int x = direction_x(direction);
    int y = direction_y(direction);

    // get the node at the front of the snake
    snake_t *snake_first;
    snake_first = SLIST_FIRST(&head);

    // create the new node
    snake_t *node;
    node = (snake_t *)malloc(sizeof(snake_t));
    // set the position of the new node based on the current direction
    node->position.x = snake_first->position.x + x;
    node->position.y = snake_first->position.y + y;

    SLIST_INSERT_HEAD(&head, node, next);

    remove_last();
}