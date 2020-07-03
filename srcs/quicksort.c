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

void		merger_stack(t_stack *stack, int med)
{
	int sub;
	int rot;

	rot = 0;
	sub = is_substack(stack, med, B);
	stack->push[A][stack->num_a] ? stack->num_a++ : 0;
	while (sub)
	{
		if (stack->stack[B]->head->data >= med)
		{
			push(stack->stack[B], stack->stack[A], stack);
			stack->push[A][stack->num_a]++;
			stack->push[B][stack->num_b]--;
			sub--;
			if (stack->push[A][stack->num_a] <= 3)
				mini_sort(stack->stack[A], stack);
		}
		else if (++rot)
			rotate(stack->stack[B], stack);
	}
	while (stack->num_b > 0 && rot--)
		revrotate(stack->stack[B], stack);
	!stack->push[B][stack->num_b] ? stack->num_b-- : 0;
	sort_stack(stack);
}

void		split_stack(t_stack *stack, int med)
{
	int sub;
	int rot;

	rot = 0;
	sub = is_substack(stack, med, A);
	stack->push[B][stack->num_b] ? stack->num_b++ : 0;
	while (sub && !issort(stack->stack[A]))
	{
		if (stack->stack[A]->head->data <= med)
		{
			push(stack->stack[A], stack->stack[B], stack);
			stack->push[A][stack->num_a]--;
			stack->push[B][stack->num_b]++;
			sub--;
		}
		else if (++rot)
			rotate(stack->stack[A], stack);
	}
	while (stack->num_a > 0 && rot--)
		revrotate(stack->stack[A], stack);
	!stack->push[A][stack->num_a] ? stack->num_a-- : 0;
	sort_stack(stack);
}
