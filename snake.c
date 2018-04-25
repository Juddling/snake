#include <stdbool.h>
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