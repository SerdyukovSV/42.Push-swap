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

void		merger_stack(t_linklist *src, t_linklist *dst, t_stack *stack)
{
    // printf("merger_stack\n");
	int med;
    int rot;

    rot = 0;
	med = get_median(stack, STK_B, stack->num_b);
    stack->push[STK_A][stack->num_a] ? stack->num_a++ : 0;
	while (is_substack(stack, med, STK_B))
	{
        // printf("step 1\n");
		if (dst->head->data > med)
        {
			push(dst, src, stack);
            stack->push[STK_A][stack->num_a]++;
            stack->push[STK_B][stack->num_b]--;
        }
		else
        {
            rotate(dst, stack);
            rot++;
        }
	}
    while (stack->num_b > 0 && rot--)
        revrotate(dst, stack);
    !stack->push[STK_B][stack->num_b] ? stack->num_b-- : 0;
    sort_stack(stack, STK_A);
}

void		split_stack(t_linklist *src, t_linklist *dst, t_stack *stack)
{
    // printf("split_stack\n");
	int med;
    int rot;

    rot = 0;
	med = get_median(stack, STK_A, stack->num_a);
    stack->push[STK_B][stack->num_b] ? stack->num_b++ : 0;
	while (is_substack(stack, med, STK_A) && !issort(src))
	{
		if (src->head->data < med)
        {
            if (src->head->data > src->head->next->data)
                swap(src, stack);
            else
            {
                push(src, dst, stack);
                stack->push[STK_A][stack->num_a]--;
                stack->push[STK_B][stack->num_b]++;
            }
        }
		else if (src->tail->data < med)
            revrotate(src, stack);
        else
        {
            rotate(src, stack);
            rot++;
        }
	}
    while (stack->num_a > 0 && rot--)
        revrotate(dst, stack);
    !stack->push[STK_A][stack->num_a] ? stack->num_a-- : 0;
    sort_stack(stack, STK_A);
}



// void		split_stack(t_linklist *src, t_linklist *dst, t_stack *stack)
// {
//     // t_substeck *sub;
// 	int med;

//     // sub = stack->sub;
// 	med = get_median(src, stack->div);
//     // if (sub->size == sub->total)
//     //     sub->stack = realloc_substack(sub, sub->total);
// 	while (is_substack(src, med, 0) && !issort(src))
// 	{
// 		if (src->head->data < med)
//         {
//             if (src->head->data > src->head->next->data)
//                 swap(src, stack);
//             else
//             {
//                 // if (!sub->stack[sub->size]->tail)
//                 //     sub->stack[sub->size]->tail = src->head;
//                 push(src, dst, stack);
//             }
//         }
// 		else if (src->tail->data < med)
//             revrotate(src, stack);
//         else
//             rotate(src, stack);
// 	}
//     // sub->stack[sub->size]->head = dst->head;
//     // sub->stack[sub->size]->size = get_len_substack(sub->stack[sub->size]);
//     // sub->size++;
// }
