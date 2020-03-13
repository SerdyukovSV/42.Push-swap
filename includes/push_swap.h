#ifndef FT_PUSH_SWAP
# define FT_PUSH_SWAP

# include "../libft/libft.h"

# include <stdio.h>

# define STACK_A        (0)
# define STACK_B        (1)

/*
** Error message
*/
# define NOARG          (1 << 0)
# define EOVERFLOW      (1 << 1)
# define DUBLICATE      (1 << 2)
# define ARGNOINT       (1 << 3)

typedef struct      s_node
{
    struct s_node    *next;
    struct s_node    *prev;
    int             data;
}                   t_node;

typedef struct  s_linkedlist
{
    t_node      *head;
    t_node      *tail;
    size_t      size;
}               t_linkedlist;

typedef struct      s_stack
{
    char            *prg;
    t_linkedlist    *stack[2];
}                   t_stack;


int init_stack(t_stack *stack, char *arg);
int check_stack(char **str);

#endif