#ifndef FT_PUSH_SWAP
# define FT_PUSH_SWAP

# include "../libft/libft.h"

# define STACK_A        (0)
# define STACK_B        (1)

/*
** Error message
*/
# define NOARG          (1)
# define EOVERFLOW      (2)
# define DUBL           (3)
# define ARGNOINT       (4)

typedef struct      s_lst
{
    struct s_lst    *next;
    struct s_lst    *prev;
    int             data;
}                   t_lst;

typedef struct      s_stack
{
    char            *prg;
    t_lst           stack[2];
}                   t_stack;


int init_stack(t_stack *stack, char *arg);

#endif