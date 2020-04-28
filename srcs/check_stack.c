#include "../includes/push_swap.h"

static int	isdublicate(char **str)
{
	int i;
	int k;

	i = 0;
	while (str[i])
	{
		k = 0;
		while (str[k])
		{
			if (k != i)
				if (!ft_strcmp(str[i], str[k]))
					return (DUBLICATE);
			k++;
		}
		i++;
	}
	return (0);
}

static int	isvalueint(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_atoi(str[i]) == 0 && ft_strlen(str[i]) > 1)
			return (EOVERFLOW);
		i++;
	}
	return (0);
}

static int	istypeint(char **str)
{
	int i;
	int k;

	i = -1;
	while (str[++i])
	{
		k = -1;
		while (str[i][++k])
		{
			if (!ft_isdigit(str[i][k]))
				if (str[i][k] != '-')
					return (ARGNOINT);
		}
	}
	return (0);
}

int			check_stack(char **str)
{
	int ret;

	ret = 0;
	if ((ret = istypeint(str) | isvalueint(str) | isdublicate(str)))
		return (ret);
	return (0);
}
