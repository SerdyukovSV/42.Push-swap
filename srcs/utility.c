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

int		get_median(t_linklist *stack, int div)
{
	// printf("get_median\n");
	t_node	*list;
	int		max;
	int		min;
	int		ret;

	list = stack->head;
	max = list->data;
	min = list->data;
	while (list)
	{
		(max < list->data) ? max = list->data : 0;
		(min > list->data) ? min = list->data : 0;
		list = list->next;
	}
	if (stack->size > 20)
		if ((ret = (max + min) / div) <= min)
			return (get_median(stack, div - 1));
		else
		{
			// printf("med = %d\n", ret);
			return (ret);
		}
	else
		ret = (max + min) / 2;
	// printf("med = %d\n", ret);
	return (ret);
}

int		is_substack(t_node *head, int med)
{
	while (head)
	{
		if (head->data <= med)
			return (1);
		head = head->next;
	}
	return (0);
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
