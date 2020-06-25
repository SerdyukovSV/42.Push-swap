/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:53:09 by gartanis          #+#    #+#             */
/*   Updated: 2020/06/23 15:55:09 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int valid_operation(char *s, int (*f)(const char *, const char *))
{
	printf("%s\n", s);
	if (!f(s, "pa") || !f(s, "pb") || !f(s, "sa") || !f(s, "sb") ||
		!f(s, "ra") || !f(s, "rb") || !f(s, "rra") || !f(s, "rrb") ||
		!f(s, "ss") || !f(s, "rr") || !f(s, "rrr"))
		return (1);
	return (0);
}

static void	print_stack(t_node *src, t_node *dst, char *opt, t_stack *stack)
{
	static int count;

	!count ? (count = 0) : 0;
	system("clear");
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
}

static void	do_operation(t_linklist *src, t_linklist *dst, t_stack *stack, \
						char *opt)
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

static int	get_operations(t_linklist *src, t_linklist *dst, t_stack *stack)
{
	char	*oper;

	if (stack->opt & OPT_F)
		stack->fd = open(OUTPUT_PS, O_RDONLY);
	while (get_next_line(stack->fd, &oper) > 0)
	{
		if (!valid_operation(oper, ft_strcmp))
			return (print_error(stack, ERR));
		if (stack->opt & OPT_V)
		{
			print_stack(src->head, dst->head, oper, stack);
			system("sleep 0.05");
		}
		do_operation(src, dst, stack, oper);
		free(oper);
	}
	if (stack->opt & OPT_V)
		print_stack(src->head, dst->head, NULL, stack);
	return (1);
}

int			main(int ac, char **av)
{
	t_stack	stack;
	int		ret;

	stack.prg = *av;
	stack.print = 0;
	stack.fd = 0;
	if (ac < 2)
		return (0);
	av += 1;
	if ((ret = init_stack(&stack, av, ac)))
		return (print_error(&stack, ERR));
	ret = get_operations(stack.stack[0], stack.stack[1], &stack);
	if (ret)
		ft_printf("%s\n", issort(stack.stack[0]) ? OK : KO);
	return (0);
}
