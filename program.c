#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/queue.h>

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

// snake is just a singley linked list
typedef struct _snake
{
    position position;
    SLIST_ENTRY(_snake)
    next;
} snake_t;

void print_green(const char *content)
{
    printf(ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, content);
}

bool is_snake(int x, int y)
{
    if (x == y)
    {
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

    // snake s = {.nums = {5, 4, 3, 2, 1}};

    // print_green("@@@@");
    // print_board();
    // debug_snake(s);
}