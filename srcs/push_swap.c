#include "../includes/push_swap.h"

int main(int ac, char *av[])
{
    t_stack stack;
    int ret;

    ret = 0;
    stack.prg = *av;
    stack.print = 1;
    if (ac < 2)
        return (print_error(stack, NOARG));
    av += 1;
    if ((ret = init_stack(&stack, av, ac)))
        return (print_error(stack, ret));
    if (stack.opt & OPT_F)
        stack.fd = open(OUTPUT_PS, O_WRONLY|O_CREAT|O_TRUNC);
    sort_stack(&stack);
    return (ret);
}