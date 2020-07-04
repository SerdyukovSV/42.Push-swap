/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 20:58:47 by gartanis          #+#    #+#             */
/*   Updated: 2020/07/04 21:49:10 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	mini_sort(t_linklist *lst, t_stack *stack)
{
	t_linklist	*dst;
	int			p;

	p = 0;
	dst = stack->stack[B];
	while (!issort(lst))
	{
		if (lst->head->data > lst->head->next->data)
		{
			if (dst->size > 1 && dst->head->data < dst->head->next->data && !p)
				doub_opt(stack, "ss", swap);
			else
				swap(lst, stack);
		}
		else if (++p)
			push(lst, dst, stack);
	}
	if (p)
	{
		while (p--)
			push(dst, lst, stack);
		mini_sort(lst, stack);
	}
}

void	quick_sort(t_stack *stack)
{
	if (!issort(stack->stack[A]))
		split_stack(stack, get_median(stack, A, stack->num_a));
	else if (stack->stack[B]->size > 0)
		merger_stack(stack, get_median(stack, B, stack->num_b));
	else
		return ;
	quick_sort(stack);
}

void	sort_stack(t_stack *stack)
{
	if (stack->push[A][stack->num_a] <= 3)
		mini_sort(stack->stack[A], stack);
	else
		quick_sort(stack);
}
