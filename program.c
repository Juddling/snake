#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

#include "snake.h"
#include "board.h"

int main()
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

    print_board();
}