#include "../includes/push_swap.h"

int creat_check(char **str)
{
}

int check_stack(char **str)
{
}

int init_stack(t_stack *stack, char *arg)
{
    t_stack stak_a;
    char **str;
    int ret;

    ret = 0;
    if (!(str = ft_strsplit(arg, " ")))
        return (ret);
    if (!(ret = check_stack(str)))
        return (ret);
}