/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 20:59:45 by gartanis          #+#    #+#             */
/*   Updated: 2020/07/03 16:42:44 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			debugging_mode(t_stack *stack)
{
	char	*line;
	int		ret;

	ret = 1;
	if (stack->opt & OPT_V && stack->opt & OPT_F)
	{
		ft_printf("Select debugging mode:\n1 - %s\n2 - %s\n", AUTO, MANUAL);
		if (get_next_line(0, &line) > 0)
			if (!ft_strcmp(line, "2"))
				ret = 2;
		free(line);
	}
	return (ret);
}

static void	ch_next_opr(t_stack *st)
{
	char *buf;

	if (st->deb_mode == 2)
	{
		ft_printf("\n\n\033[31;1mpress enter\033[m\n");
		get_next_line(0, &buf);
		free(buf);
	}
}

void		print_stack(t_node *src, t_node *dst, char *opt, t_stack *st)
{
	ft_printf("\033[39;1mOperation : \033[33;1m%s\033[m\n", opt ? opt : "");
	ft_printf("\033[39;1mCounter   : %d\n", st->count++);
	ft_printf("  Stack A   Stack B\033[0m\n");
	while (src || dst)
	{
		if ((src && src->prev && src->data > src->prev->data) || (src && \
			!src->prev))
			src ? ft_printf("\033[32;1m%9d\033[0m |", src->data) : \
				ft_printf("          |");
		else
			src ? ft_printf("\033[31;1m%9d\033[0m |", src->data) : \
				ft_printf("          |");
		if ((dst && dst->prev && dst->data < dst->prev->data) || (dst && \
			!dst->prev))
			dst ? ft_printf("\033[32;1m%2d\033[0m\n", dst->data) : \
				ft_printf("  \n");
		else
			dst ? ft_printf("\033[31;1m%2d\033[0m\n", dst->data) : \
				ft_printf("  \n");
		src ? (src = src->next) : 0;
		dst ? (dst = dst->next) : 0;
	}
	ch_next_opr(st);
}
