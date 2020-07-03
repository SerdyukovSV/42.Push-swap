/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:10:32 by gartanis          #+#    #+#             */
/*   Updated: 2020/06/23 16:11:31 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		print_error(t_stack *stack, int errcode)
{
	if (errcode & NOARG)
		ft_printf("\033[39;1m%s:\033[0m %s %s\n", stack->prg, ERR_M, NOARG_MS);
	if (errcode & EOVERFLOW)
		ft_printf("\033[39;1m%s:\033[0m %s %s\n", stack->prg, ERR_M, \
					EOVERFLOW_MS);
	if (errcode & DUBLICATE)
		ft_printf("\033[39;1m%s:\033[0m %s %s\n", stack->prg, ERR_M, \
					DUBLICATE_MS);
	if (errcode & ARGNOINT)
		ft_printf("\033[39;1m%s:\033[0m %s %s\n", stack->prg, ERR_M, \
					ARGNOINT_MS);
	if (errcode & ERR)
		ft_printf("Error\n");
	return (0);
}

void	print_operation(t_stack *stack, const char *str, const char let)
{
	if (stack->print)
	{
		if (!(stack->opt & OPT_F))
		{
			ft_putstr(str);
			let ? ft_putchar(let) : 0;
			ft_putchar('\n');
		}
		if (stack->opt & OPT_F)
		{
			ft_putstr_fd(str, stack->fd);
			let ? write(stack->fd, &let, 1) : 0;
			write(stack->fd, "\n", 1);
		}
	}
}

int		get_median(t_stack *stack, int s, int num)
{
	t_node	*lst;
	int		max;
	int		min;
	int		i;

	lst = stack->stack[s]->head;
	max = lst->data;
	min = lst->data;
	i = -1;
	while (++i < stack->push[s][num])
	{
		(max < lst->data) ? max = lst->data : 0;
		(min > lst->data) ? min = lst->data : 0;
		lst = lst->next;
	}
	if (max == min)
		return (max);
	return ((max + min) / 2);
}

int		is_substack(t_stack *stack, int med, int s)
{
	t_node	*tmp;
	int		ret;
	int		i;

	ret = 0;
	i = -1;
	tmp = stack->stack[s]->head;
	if (s == A)
		while (++i < stack->push[s][stack->num_a])
		{
			if (tmp->data <= med)
				ret++;
			tmp = tmp->next;
		}
	else
		while (++i < stack->push[s][stack->num_b])
		{
			if (tmp->data >= med)
				ret++;
			tmp = tmp->next;
		}
	return (ret);
}

int		issort(t_linklist *stack)
{
	t_node *tmp;

	tmp = stack->head;
	if (stack->letter == 'a')
		while (tmp->next && tmp->data < tmp->next->data)
			tmp = tmp->next;
	else
		while (tmp->next && tmp->data > tmp->next->data)
			tmp = tmp->next;
	return (!(stack->letter == 'a' ? tmp->next : tmp->prev));
}
