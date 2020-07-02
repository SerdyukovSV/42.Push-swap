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

void	doub_opt(t_stack *stack, char *op, void (*f)(t_linklist *, t_stack *))
{
	int i;

	i = stack->print;
	stack->print = 0;
	f(stack->stack[STK_A], stack);
	f(stack->stack[STK_B], stack);
	stack->print = i;
	print_operation(stack, op, 0);
}

void	revrotate(t_linklist *lst, t_stack *stack)
{
	t_node *tmp;

	if (lst->head && lst->tail)
	{
		tmp = lst->tail;
		tmp->next = lst->head;
		lst->head->prev = tmp;
		lst->head = tmp;
		lst->tail = lst->tail->prev;
		lst->tail->next = NULL;
		lst->head->prev = NULL;
		print_operation(stack, "rr", lst->letter);
	}
}

void	rotate(t_linklist *lst, t_stack *stack)
{
	if (lst->head && lst->tail)
	{
		lst->tail->next = lst->head;
		lst->head->prev = lst->tail;
		lst->tail = lst->head;
		lst->head = lst->head->next;
		lst->head->prev = NULL;
		lst->tail->next = NULL;
		print_operation(stack, "r", lst->letter);
	}
}

void	swap(t_linklist *lst, t_stack *stack)
{
	int tmp;

	if (lst->head && lst->head->next)
	{
		tmp = lst->head->data;
		lst->head->data = lst->head->next->data;
		lst->head->next->data = tmp;
		print_operation(stack, "s", lst->letter);
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
