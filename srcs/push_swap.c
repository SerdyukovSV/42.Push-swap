#include "../includes/push_swap.h"

int main(int ac, char *av[])
{
    // printf("Push_swap\n");
    t_stack stack;
    int ret;

    ret = 0;
    stack.prg = *av;
    if (ac < 2)
        return (print_error(stack, NOARG));
    av += 1;
    if ((ret = init_stack(&stack, av, ac)))
        return (print_error(stack, ret));
    sort_stack(&stack);    
    return (ret);
}