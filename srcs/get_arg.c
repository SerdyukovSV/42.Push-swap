#include "../includes/push_swap.h"

void    ft_print_options(t_stack *stack, const char *str, const char let)
{
    if (stack->print)
    {
        ft_putstr(str);
        let ? ft_putchar(let) : 0;
        ft_putchar('\n');
        if (stack->opt & OPT_F)
        {
            ft_putstr_fd(str, stack->fd);
            let ? write(stack->fd, &let, 1) : 0;
            write(stack->fd, "\n", 1);
        }
    }
}

static int get_opions(t_stack *stack, char *str)
{
    int ret;

    ret = 0;
    if (*str++ == '-' && ft_isalpha(*str))
    {
        while (str && ft_strchr("vcf", *str))
        {
            ret = 1;
            if (ft_strchr(str, 'v'))
                stack->opt |= OPT_V;
            else if (ft_strchr(str, 'c'))
                stack->opt |= OPT_C;
            else if (ft_strchr(str, 'f'))
                stack->opt |= OPT_F;
            str++;
        }
        return (ret);
    }
    return (ret);
}

char **get_arg(t_stack *stack, int ac, char *av[])
{
    char **str;
    int i;
    int k;
    
    i = 0;
    k = 0;
    stack->opt = 0;
    if (!(str = (char **)malloc(sizeof(char *) * ac)))
        exit (1);
    while (av[i])
        if (get_opions(stack, av[i]))
            i++;
        else
        {
            if (ft_strchr(av[i], ' '))
                str = ft_strsplit(av[0], ' ');
            else
                str[k++] = ft_strdup((const char *)av[i]);
            i++;
        }
    str[k] = NULL;
    return (str);
}