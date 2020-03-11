#include "../includes/push_swap.h"

// int creat_check(char **str)
// {
// }

int isdublicate(char **str)
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
                if (ft_strcmp(str[i], str[k]))
                    return (1);
            k++;
        }
        i++;
    }
    return (0);
}

int isvalueint(char **str)
{
    while (*str)
    {
        while (**str)
        {
            if (ft_atoi(*str) != (long)ft_atoi(*str))
                return (0);
            *str++;
        }
        str++;
    }
    return (1);
}

int istypeint(char **str)
{
    while (*str)
    {
        while (**str)
        {
            if (!ft_isdigit(*str))
                if (*str != '-')
                    return (0);
            *str++;
        }
        str++;
    }
    return (1);
}

int check_stack(char **str)
{
    int i;
    int ret;
    
    i = -1;
    ret = 0;
    if (!istypeint(str))
        return (ARGNOINT);
    if (!isvalueint(str))
        return (EOVERFLOW);
    if (isdublicate(str))
        return (DUBLICATE);
    // while (str[++i])
    // {
    //     k = -1;
    //     while (str[i][++k])
    //         if (!ft_isdigit(str[i][k]) && str[i][k] != '-')
    //             return (ARGNOINT);
    // }
    // i = -1;
    // while (str[++i])
    //     if (ft_atoi(str[i]) == -1 && ft_strlen(str[i]) > 2)
    //         return (EOVERFLOW);
    //     else if (ft_atoi(str[i]) == 0 && ft_strlen(str[i]) > 1)
    //         return (EOVERFLOW);
    return (0);
}

int init_stack(t_stack *stack, char *arg)
{
    t_stack stak_a;
    char **str;
    int ret;

    if (!(str = ft_strsplit(arg, ' ')))
        return (NOARG);
    if ((ret = check_stack(str)))
        return (ret);
    return (0);
}