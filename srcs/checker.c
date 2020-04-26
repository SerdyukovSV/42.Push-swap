#include "../includes/push_swap.h"

static void    print_stack(t_node *src, t_node *dst, char *opt, t_stack *stack)
{
    static int count;
    int a;
    int b;

    !count ? (count = 0) : 0;
    system("clear");
    printf("Operation : \033[33;1m%s\033[m\nCounter   : %d\n", opt ? opt : "", count++);
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


static void    do_operation(t_linklist *src, t_linklist *dst, t_stack *stack, char *opt)
{
    !ft_strcmp("pb", opt) ? push(src, dst, stack) : 0;
    !ft_strcmp("pa", opt) ? push(dst, src, stack) : 0;
    !ft_strcmp("sa", opt) ? swap(src, stack) : 0;
    !ft_strcmp("sb", opt) ? swap(dst, stack) : 0;
    !ft_strcmp("ss", opt) ? doub_swap(src, dst, stack) : 0;
    !ft_strcmp("ra", opt) ? rotate(src, stack) : 0;
    !ft_strcmp("rb", opt) ? rotate(dst, stack) : 0;
    !ft_strcmp("rr", opt) ? doub_rotate(src, dst, stack) : 0;
    !ft_strcmp("rra", opt) ? revrotate(src, stack) : 0;
    !ft_strcmp("rrb", opt) ? revrotate(dst, stack) : 0;
    !ft_strcmp("rrr", opt) ? doub_revrotate(src, dst, stack) : 0;
}

static int get_operations(t_linklist *src, t_linklist *dst, t_stack *stack)
{
    char *opt;
    int ret;

    if (stack->opt & OPT_F)
        stack->fd = open(OUTPUT_PS, O_RDONLY);
    while ((ret = get_next_line(stack->fd, &opt)) > 0)
    {
        if (stack->opt & OPT_V)
        {
            print_stack(src->head, dst->head, opt, stack);
            system("sleep 0.05");
        }
        do_operation(src, dst, stack, opt);
        free(opt);
    }
    if (stack->opt & OPT_V)
        print_stack(src->head, dst->head, NULL, stack);
    return (ret);
}

int main(int ac, char **av)
{
    t_stack stack;
    int ret;

    stack.prg = *av;
    stack.print = 0;
    stack.fd = 0;
    if (ac < 2)
        return (print_error(stack, -1));
    av += 1;
    if ((ret = init_stack(&stack, av, ac)))
        return (print_error(stack, -1));
    ret = get_operations(stack.stack[0], stack.stack[1], &stack);
    printf("%s\n", issort(stack.stack[0]) ? OK : KO);
    return (0);
}