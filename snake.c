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
    for (int i = 0; i < 3; i++)
    {
        node = (snake_t *)malloc(sizeof(snake_t));
        node->position = p;

        SLIST_INSERT_HEAD(&head, node, next);
        p.y++;
    }
}

// move the snake
void snake_advance()
{
    // get the node at the front of the snake
    snake_t *snake_first;
    snake_first = SLIST_FIRST(&head);

    // create the new node
    snake_t *node;
    node = (snake_t *)malloc(sizeof(snake_t));
    // set the position of the new node based on the current direction
    node->position.x = snake_first->position.x;
    node->position.y = snake_first->position.y + 1;

    SLIST_INSERT_HEAD(&head, node, next);

    // todo remove node from the tail of the snake
}