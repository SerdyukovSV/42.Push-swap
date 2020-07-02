/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:05:05 by gartanis          #+#    #+#             */
/*   Updated: 2020/07/02 21:04:48 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int ac, char *av[])
{
	t_stack		stack;
	int			ret;

	ret = 0;
	stack.prg = *av;
	stack.print = 1;
	if (ac < 2)
		return (print_error(&stack, NOARG));
	av += 1;
	if ((ret = init_stack(&stack, av, ac)))
		return (print_error(&stack, ret));
	if (stack.opt & OPT_F)
		stack.fd = open(OUTPUT_PS, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	sort_stack(&stack, STK_A);
	free_stack(&stack);
	return (ret);
}
