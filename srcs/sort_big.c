/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:07:25 by gartanis          #+#    #+#             */
/*   Updated: 2020/07/02 21:04:21 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		merger_stack(t_linklist *src, t_linklist *dst, t_stack *stack)
{
	int med;
	int rot;

	rot = 0;
	med = get_median(stack, STK_B, stack->num_b);
	stack->push[STK_A][stack->num_a] ? stack->num_a++ : 0;
	while (is_substack(stack, med, STK_B))
	{
		if (dst->head->data >= med)
		{
			push(dst, src, stack);
			stack->push[STK_A][stack->num_a]++;
			stack->push[STK_B][stack->num_b]--;
		}
		else if (++rot)
			rotate(dst, stack);
	}
	while (stack->num_b > 0 && rot--)
		revrotate(dst, stack);
	!stack->push[STK_B][stack->num_b] ? stack->num_b-- : 0;
	sort_stack(stack, STK_A);
}

void		split_stack(t_linklist *src, t_linklist *dst, t_stack *stack)
{
	int med;
	int rot;

	rot = 0;
	med = get_median(stack, STK_A, stack->num_a);
	stack->push[STK_B][stack->num_b] ? stack->num_b++ : 0;
	while (is_substack(stack, med, STK_A) && !issort(src))
	{
		if (src->head->data <= med)
		{
			push(src, dst, stack);
			stack->push[STK_A][stack->num_a]--;
			stack->push[STK_B][stack->num_b]++;
		}
		else if (++rot)
			rotate(src, stack);
	}
	while (stack->num_a > 0 && rot--)
		revrotate(src, stack);
	!stack->push[STK_A][stack->num_a] ? stack->num_a-- : 0;
	sort_stack(stack, STK_A);
}
