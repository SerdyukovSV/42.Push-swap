#include "../includes/push_swap.h"

void    print_stack(t_node *src, t_node *dst, char *opt)
{
    system("clear");
    printf("Operation : \033[33;1m%s\033[00m\n\n", opt ? opt : "");
    printf("  Stack A   Stack B\n");
    while (src || dst)
    {
        src ? printf("%9d |",src->data) : printf("          |");
        dst ? printf("%2d", dst->data) : printf("  ");
        src ? (src = src->next) : 0;
        dst ? (dst = dst->next) : 0;
        printf("\n");
    }
    
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

int get_options(t_linklist *src, t_linklist *dst)
{
    char *opt;
    int ret;

    while ((ret = get_next_line(0, &opt)) > 0)
    {
        // print_stack(src->head, dst->head, opt);
        do_option(src, dst, opt);
        // system("sleep 0.05");
        free(opt);
    }
    // print_stack(src->head, dst->head, NULL);
    return (ret);
}

int main(int ac, char **av)
{
    t_stack stack;
    int ret;

    stack.prg = *av;
    if (ac < 2)
        return (print_error(stack, -1));
    av += 1;
    if ((ret = init_stack(&stack, av, ac)))
        return (print_error(stack, -1));
    ret = get_options(stack.stack[0], stack.stack[1]);
    printf("%s\n", issort(stack.stack[0]) ? OK : KO);
    return (0);
}