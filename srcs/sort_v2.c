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

// static void	swap_stack(t_linklist *src, t_linklist *dst, int med, \
// 						t_stack *stack)
// {
// 	// printf("swap_stack\n");
// 	if (src->head->data < med)
// 	{
// 		if (src->head->data > src->head->next->data)
// 		{
// 			if (dst->size > 2 && dst->head->next->data > dst->head->data && \
// 				dst->head->data > dst->tail->data)
// 				doub_swap(src, dst, stack);
// 			else
// 				swap(src, stack);
// 		}
// 	}
// 	if (dst->size > 2 && dst->head->next->data > dst->head->data)
// 		if (dst->head->data > dst->tail->data)
// 			swap(dst, stack);
// }

// static void	revrotate_stack(t_linklist *src, t_linklist *dst, int med, \
// 							t_stack *stack)
// {
// 	// printf("revrotate_stack\n");
// 	if (src->head->data > src->tail->data)
// 		if (src->tail->data < med)
// 		{
// 			if (dst->size > 2 && dst->head->next->data < dst->head->data && \
// 				dst->head->data < dst->tail->data)
// 				doub_revrotate(src, dst, stack);
// 			else
// 				revrotate(src, stack);
// 		}
// 	if (dst->size > 2 && dst->head->next->data < dst->head->data)
// 		if (dst->head->data < dst->tail->data)
// 			revrotate(dst, stack);
// }

// static void	rotate_stack(t_linklist *src, t_linklist *dst, int med, \
// 						t_stack *stack)
// {
// 	// printf("rotate_stack\n");
// 	if (src->head->data >= med && src->tail->data >= med)
// 	{
// 		if (dst->size > 2 && dst->head->next->data > dst->head->data && dst->head->data < dst->tail->data)
// 			doub_rotate(src, dst, stack);
// 		else
// 			rotate(src, stack);
// 	}
// 	if (dst->size > 2 && dst->head->next->data > dst->head->data)
// 		if (dst->head->data < dst->tail->data)
// 			rotate(dst, stack);
// }

static int  get_len_substack(t_substeck *sub, int num)
{
    int len;

    len = 0;
    while (sub->stack[num]->head != sub->stack[num]->tail)
    {
        sub->stack[num]->head = sub->stack[num]->head->next;
        len++;
    }
    if (sub->stack[num]->head == sub->stack[num]->tail)
        len++;
    return (len);
    
}

void		merger_stack(t_substeck *sub, t_linklist *dst, t_stack *stack)
{
	int med;

    
	med = get_median(dst, stack->div);
	while (is_substack(dst->head, med) && issort(src) && dst->size > 0)
	{
		if (dst->head->data > med)
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
    t_substeck *sub;
	int med;

    sub = stack->sub;
	med = get_median(src, stack->div);
    if (sub->size == sub->total)
        sub->stack = realloc_substack(sub, sub->total);
	while (is_substack(src->head, med) && !issort(src))
	{
		if (src->head->data <= med)
        {
            if (src->head->data > src->head->next->data)
                swap(src, stack);
            else
            {
                if (!sub->stack[sub->size]->tail)
                    sub->stack[sub->size]->tail = src->head;
                push(src, dst, stack);
            }
        }
		else if (src->tail->data < med)
            revrotate(src, stack);
        else
            rotate(src, stack);
	}
    sub->stack[sub->size]->head = dst->head;
    sub->size++;
}
