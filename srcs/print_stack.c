#include "../includes/push_swap.h"

int     debugging_mode(t_stack *stack)
{
    char    *line;
    int     ret;

    ret = 1;
    if (stack->opt & OPT_V && stack->opt & OPT_F)
    {
        ft_printf("Select debugging mode:\n1 - %s\n2 - %s\n", AUTO, MANUAL);
        if (get_next_line(0, &line) > 0)
        {
            if (!ft_strcmp(line, "2"))
                ret = 2;
            free(line);
        }
    }
    return (ret);
}

void	print_stack(t_node *src, t_node *dst, char *opt, int dmode)
{
	static int count;
    char *buf;

	!count ? (count = 0) : 0;
	system("clear");
    ft_printf("Debug mode: %s\n", (dmode == 1) ? AUTO : MANUAL);
	ft_printf("Operation : \033[33;1m%s\033[m\nCounter   : %d\n", \
				opt ? opt : "", count++);
	ft_printf("  Stack A   Stack B\n");
	while (src || dst)
	{
		src ? ft_printf("%9d |", src->data) : ft_printf("          |");
		dst ? ft_printf("%2d", dst->data) : ft_printf("  ");
		src ? (src = src->next) : 0;
		dst ? (dst = dst->next) : 0;
		ft_printf("\n");
	}
    if (dmode == 2)
    {
        ft_printf("\n\n\033[31;1mpress enter\033[m\n");
        get_next_line(0, &buf);
        free(buf);
    }
}