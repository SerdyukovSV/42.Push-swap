/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:56:58 by gartanis          #+#    #+#             */
/*   Updated: 2020/06/23 15:57:54 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_options(t_stack *stack, char *str)
{
	int ret;

	ret = 0;
	if (*str++ == '-' && ft_isalpha(*str))
	{
		while (str && ft_strchr("vcf", *str))
		{
			ret = 1;
			if (*str == 'v')
				stack->opt |= OPT_V;
			else if (*str == 'c')
				stack->opt |= OPT_C;
			else if (*str == 'f')
				stack->opt |= OPT_F;
			str++;
		}
		return (ret);
	}
	return (ret);
}

char		**get_arg(t_stack *stack, int ac, char *av[])
{
	char	**str;
	int		i;
	int		k;

	i = -1;
	k = 0;
	if (!(str = (char **)malloc(sizeof(char *) * ac)))
		exit(1);
	while (av[++i])
	{
		if (!get_options(stack, av[i]))
		{
			if (ft_strchr(av[i], ' '))
			{
				free(str);
				str = ft_strsplit(av[i], ' ');
			}
			else
			{
				str[k++] = ft_strdup((const char *)av[i]);
				str[k] = NULL;
			}
		}
	}
	return (str);
}
