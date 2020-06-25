/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:58:24 by gartanis          #+#    #+#             */
/*   Updated: 2020/06/26 18:17:42 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void				free_stack(t_stack *stack)
{
	t_linklist	*tmp;
	int			i;

	i = 0;
	while (i < 2)
	{
		tmp = stack->stack[i];
		while (tmp->head)
		{
			free(tmp->head);
			tmp->head = tmp->head->next;
		}
		free(tmp);
		i++;
	}
}

static void			ft_push_bot(t_linklist *list, int data)
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

static t_linklist	*creat_linkedlist(char lett)
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

static void			creat_stack(t_stack *stack, char **str)
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

int					init_stack(t_stack *stack, char *av[], int ac)
{
	char	**str;
	int		ret;
	int		i;

	stack->opt = 0;
	str = get_arg(stack, ac, av);
	if (!str[0])
		return (NOARG);
	if ((ret = check_stack(str)))
		return (ret);
	creat_stack(stack, str);
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return (ret);
}
