/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:56:58 by gartanis          #+#    #+#             */
/*   Updated: 2020/07/04 14:38:42 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		free_str(char **str)
{
	int i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

static int	arg_len(char **arg)
{
	int i;

	i = 0;
	if (!arg)
		return (0);
	while (arg[i] != NULL)
		i++;
	return (i);
}

static char	**arg_join(char *av, char **arg)
{
	char	**str;
	char	**tmp;
	int		i;
	int		k;

	str = ft_strsplit(av, ' ');
	if (!(i = arg_len(arg)))
		return (str);
	k = arg_len(str);
	if (!(tmp = (char **)malloc(sizeof(char *) * (i + k + 1))))
		exit(1);
	i = -1;
	while (arg[++i])
		tmp[i] = arg[i];
	k = -1;
	while (str[++k])
		tmp[i + k] = str[k];
	tmp[i + k] = NULL;
	free(arg);
	free(str);
	return (tmp);
}

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

char		**get_arg(t_stack *stack, char *av[])
{
	char	**arg;
	int		i;

	i = -1;
	arg = NULL;
	while (av[++i])
	{
		if (!get_options(stack, av[i]))
		{
			arg = arg_join(av[i], arg);
		}
	}
	return (arg);
}
