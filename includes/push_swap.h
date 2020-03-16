#ifndef FT_PUSH_SWAP
# define FT_PUSH_SWAP

# include "../libft/libft.h"

# include <stdio.h>

# define ERR_M "\033[31;1merror:\033[00m"

# define STACK_A        (0)
# define STACK_B        (1)

/*
** Error message
*/
# define NOARG          (1 << 0)
# define EOVERFLOW      (1 << 1)
# define DUBLICATE      (1 << 2)
# define ARGNOINT       (1 << 3)

# define NOARG_MS        "\033[39;1mmissing arguments\033[0m"
# define EOVERFLOW_MS    "\033[39;1mvalue too large to be stored in data type\033[0m"
# define DUBLICATE_MS    "\033[39;1mthere are duplicates\033[0m"
# define ARGNOINT_MS     "\033[39;1margument are not integer\033[0m"

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