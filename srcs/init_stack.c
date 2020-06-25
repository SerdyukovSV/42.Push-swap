/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:58:24 by gartanis          #+#    #+#             */
/*   Updated: 2020/06/23 16:00:03 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_push_bot(t_linklist *list, int data)
{
	t_node *tmp;

	if (!(tmp = (t_node*)malloc(sizeof(t_node))))
		exit(1);
	tmp->data = data;
	tmp->next = NULL;
	tmp->prev = list->tail;
	if (list->tail)
		list->tail->next = tmp;
	list->tail = tmp;
	if (!list->head)
		list->head = tmp;
	list->size += 1;
}

t_linklist	*creat_linkedlist(char lett)
{
	t_linklist *tmp;

	if (!(tmp = (t_linklist*)malloc(sizeof(t_linklist))))
		return (NULL);
	tmp->size = 0;
	tmp->letter = lett;
	tmp->head = NULL;
	tmp->tail = NULL;
	return (tmp);
}

void		creat_stack(t_stack *stack, char **str)
{
	if (!(stack->stack[0] = creat_linkedlist('a')))
		exit(1);
	if (!(stack->stack[1] = creat_linkedlist('b')))
		exit(1);
	while (*str)
	{
		ft_push_bot(stack->stack[0], ft_atoi(*str));
		str += 1;
	}
}

int			init_stack(t_stack *stack, char *av[], int ac)
{
	char	**str;
	int		ret;
	int		i;

	str = get_arg(stack, ac, av);
	if (!str[0])
		return (NOARG);
	if ((ret = check_stack(str)))
		return (ret);
	creat_stack(stack, str);
	return (ret);
}
