#include "../includes/push_swap.h"

int print_error(t_stack stack, int errcode)
{
    if (errcode & NOARG)
        printf("%s: %s\n", stack.prg, "Missing arguments");
    if (errcode & EOVERFLOW)
        printf("%s: %s\n", stack.prg, "Value too large to be stored in data type");
    if (errcode & DUBLICATE)
        printf("%s: %s\n", stack.prg, "There are duplicates");
    if (errcode & ARGNOINT)
        printf("%s: %s\n", stack.prg, "Argument are not integer");
    return (0);
}

int main(int ac, char **av)
{
    t_stack stack;
    int ret;

    stack.prg = *av;
    if (ac < 2)
        return (print_error(stack, NOARG));
    av += 1;
    if ((ret = init_stack(&stack, *av)))
        return (print_error(stack, ret));
    
    return (0);
}