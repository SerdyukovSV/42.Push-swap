/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:01:40 by gartanis          #+#    #+#             */
/*   Updated: 2020/06/23 16:01:47 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	revrotate(t_linklist *list, t_stack *stack)
{
	t_node *tmp;

	if (list->head && list->tail)
	{
		tmp = list->tail;
		tmp->next = list->head;
		list->head->prev = tmp;
		list->head = tmp;
		list->tail = list->tail->prev;
		list->tail->next = NULL;
		list->head->prev = NULL;
		print_operation(stack, "rr", list->letter);
	}
}

void	rotate(t_linklist *list, t_stack *stack)
{
	if (list->head && list->tail)
	{
		list->tail->next = list->head;
		list->head->prev = list->tail;
		list->tail = list->head;
		list->head = list->head->next;
		list->head->prev = NULL;
		list->tail->next = NULL;
		print_operation(stack, "r", list->letter);
	}
}

void	swap(t_linklist *list, t_stack *stack)
{
	int tmp;

	if (list->head && list->head->next)
	{
		tmp = list->head->data;
		list->head->data = list->head->next->data;
		list->head->next->data = tmp;
		print_operation(stack, "s", list->letter);
	}
}

void	push(t_linklist *src, t_linklist *dst, t_stack *stack)
{
	t_node *tmp;

	if (!src)
		return ;
	tmp = src->head;
	if (src->head->next)
	{
		src->head = src->head->next;
		src->head->prev = NULL;
	}
	else
		src->head = NULL;
	tmp->next = dst->head;
	tmp->prev = NULL;
	if (dst->head)
		dst->head->prev = tmp;
	dst->head = tmp;
	if (!dst->tail)
		dst->tail = tmp;
	src->size -= 1;
	dst->size += 1;
	print_operation(stack, "p", dst->letter);
}
