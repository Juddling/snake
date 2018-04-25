#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

#include "snake.h"
#include "board.h"

typedef struct
{
    int x;
    int y;
} position;

// snake is just a singley linked list
typedef struct _snake
{
    position position;
    SLIST_ENTRY(_snake)
    next;
} snake_t;

int main()
{
    // creates a stuct for the head of the list
    SLIST_HEAD(head_s, _snake)
    head;
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

    snake_t *n;
    SLIST_FOREACH(n, &head, next)
    {
        printf("position x = %d, y = %d\n", n->position.x, n->position.y);
    }

    // print_board();
}