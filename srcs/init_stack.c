#include "../includes/push_swap.h"

t_lst *ft_creat_elem(int data)
{
    t_lst *new;

    if (new = (t_lst*)malloc(sizeof(t_lst)))
        return (NULL);
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}

// t_lst ft_lst_push_front()

int creat_stack(t_stack *stack, char **str)
{
}

int init_stack(t_stack *stack, char *arg)
{
    char **str;
    int ret;

    str = ft_strsplit(arg, ' ');
    if (!*str)
        return (NOARG);
    if ((ret = check_stack(str)))
        return (ret);
    
    return (0);
}