#include "../includes/push_swap.h"
#include <stdio.h>

int print_error(t_stack stack, int errorcode)
{
    if (errorcode == NOARG)
        printf("%s: %s\n", stack.prg, "Missing arguments");
    else if (errorcode == EOVERFLOW)
        printf("%s: %s\n", stack.prg, "Value too large to be stored in data type");
    else if (errorcode == DUBL)
        printf("%s: %s\n", stack.prg, "There are duplicates");
    else if (errorcode == ARGNOINT)
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
    else
        if (ret = init_stack(&stack, *av))
            return (print_error(stack, ret));
    
    return (0);
}