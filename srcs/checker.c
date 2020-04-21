#include "../includes/push_swap.h"

typedef void (*simpleFP)(t_linklist *lst, int print);
typedef struct functionMETA {
    simpleFP funcPtr;
    char * funcName;
} functionMETA;

void    print_stack(t_stack *stack)
{
    t_node *tmp;
    tmp = stack->stack[A]->head;
    printf("stack_a = ");
    while (tmp)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");

    tmp = stack->stack[B]->head;
    printf("stack_b = ");
    while (tmp)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}


void    do_option(t_linklist *src, t_linklist *dst, char *opt)
{
    !ft_strcmp("pb", opt) ? push(src, dst, 0) : 0;
    !ft_strcmp("pa", opt) ? push(dst, src, 0) : 0;
    !ft_strcmp("sa", opt) ? swap(src, 0) : 0;
    !ft_strcmp("sb", opt) ? swap(dst, 0) : 0;
    !ft_strcmp("ss", opt) ? doub_swap(src, dst, 0) : 0;
    !ft_strcmp("ra", opt) ? rotate(src, 0) : 0;
    !ft_strcmp("rb", opt) ? rotate(dst, 0) : 0;
    !ft_strcmp("rr", opt) ? doub_rotate(src, dst, 0) : 0;
    !ft_strcmp("rra", opt) ? revrotate(src, 0) : 0;
    !ft_strcmp("rrb", opt) ? revrotate(dst, 0) : 0;
    !ft_strcmp("rrr", opt) ? doub_revrotate(src, dst, 0) : 0;
}



int get_options(t_stack *stack)
{
    t_linklist *src;
    t_linklist *dst;
    char *opt;
    int ret;

    src = stack->stack[0];
    dst = stack->stack[1];
    while ((ret = get_next_line(0, &opt)) > 0)
    {
        do_option(src, dst, opt);
        free(opt);
    }
    return (ret);
}

int main(int ac, char *av[])
{
    t_stack stack;
    int ret;

    if (ac < 2)
        return (print_error(stack, -1));
    av += 1;
    if ((ret = init_stack(&stack, av, ac)))
        return (print_error(stack, -1));
    ret = get_options(&stack);
    print_stack(&stack);
    return (0);
}