/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:07:25 by gartanis          #+#    #+#             */
/*   Updated: 2020/06/23 16:08:24 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap_stack(t_linklist *src, t_linklist *dst, int med, \
						t_stack *stack)
{
	// printf("swap_stack\n");
	if (src->head->data < med)
	{
		if (src->head->data > src->head->next->data)
		{
			if (dst->size > 2 && dst->head->next->data > dst->head->data && \
				dst->head->data > dst->tail->data)
				doub_swap(src, dst, stack);
			else
				swap(src, stack);
		}
	}
	if (dst->size > 2 && dst->head->next->data > dst->head->data)
		if (dst->head->data > dst->tail->data)
			swap(dst, stack);
}

static void	revrotate_stack(t_linklist *src, t_linklist *dst, int med, \
							t_stack *stack)
{
	// printf("revrotate_stack\n");
	if (src->head->data > src->tail->data)
		if (src->tail->data < med)
		{
			if (dst->size > 2 && dst->head->next->data < dst->head->data && \
				dst->head->data < dst->tail->data)
				doub_revrotate(src, dst, stack);
			else
				revrotate(src, stack);
		}
	if (dst->size > 2 && dst->head->next->data < dst->head->data)
		if (dst->head->data < dst->tail->data)
			revrotate(dst, stack);
}

static void	rotate_stack(t_linklist *src, t_linklist *dst, int med, \
						t_stack *stack)
{
	// printf("rotate_stack\n");
	if (src->head->data >= med && src->tail->data >= med)
	{
		if (dst->size > 2 && dst->head->next->data > dst->head->data && dst->head->data < dst->tail->data)
			doub_rotate(src, dst, stack);
		else
			rotate(src, stack);
	}
	if (dst->size > 2 && dst->head->next->data > dst->head->data)
		if (dst->head->data < dst->tail->data)
			rotate(dst, stack);
}

void		merger_stack(t_linklist *src, t_linklist *dst, t_stack *stack)
{
	// printf("merger_stack\n");
	int med;

	med = get_median(dst, stack->div);
	while (is_substack(dst->head, med) && issort(src) && dst->size > 0)
	{
		// printf("loop\n");
		if (dst->head->data > med /* || dst->size < 3 */)
				push(dst, src, stack);
		else
		{
			swap_stack(src, dst, med, stack);
			revrotate_stack(src, dst, med, stack);
			// rotate_stack(src, dst, med, stack);
		}
	}
}

void		split_stack(t_linklist *src, t_linklist *dst, t_stack *stack)
{
	// printf("split_stack\n");
	int med;

	med = get_median(src, stack->div);
	while (is_substack(src->head, med) && !issort(src) && src->size > 3)
	{
		if (src->head->data < med && src->head->data < src->head->next->data)
			push(src, dst, stack);
		else
		{
			swap_stack(src, dst, med, stack);
			revrotate_stack(src, dst, med, stack);
			if (src->head->data >= med && src->tail->data >= med)
				rotate_stack(src, dst, med, stack);
		}
	}
	// printf("out\n");
}
