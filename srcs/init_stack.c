#include "../includes/push_swap.h"

int print_error(t_stack stack, int errcode)
{
    if (errcode & NOARG)
        printf("\033[39;1m%s:\033[0m %s %s\n", stack.prg, ERR_M, NOARG_MS);
    if (errcode & EOVERFLOW)
        printf("\033[39;1m%s:\033[0m %s %s\n", stack.prg, ERR_M, EOVERFLOW_MS);
    if (errcode & DUBLICATE)
        printf("\033[39;1m%s:\033[0m %s %s\n", stack.prg, ERR_M, DUBLICATE_MS);
    if (errcode & ARGNOINT)
        printf("\033[39;1m%s:\033[0m %s %s\n", stack.prg, ERR_M, ARGNOINT_MS);
    if (errcode & -1)
        printf("Error\n");
    return (0);
}

void    ft_push_front(t_linklist *list, int data)
{
    t_node *tmp;

    if (!(tmp = (t_node*)malloc(sizeof(t_node))))
        exit (1);
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

t_linklist *creat_linkedlist()
{
    t_linklist *tmp;

    if (!(tmp = (t_linklist*)malloc(sizeof(t_linklist))))
        return (NULL);
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;

    return (tmp);
}

void    creat_stack(t_linklist **list, char **str)
{
    *list = creat_linkedlist();
    while (*str)
    {
        ft_push_front(*list, ft_atoi(*str));
        str += 1;
    }
}

int init_stack(t_stack *stack, char *av[], int ac)
{
    char **str;
    int ret;
    int i;

    i = 0;
    if (ac == 2)
        str = ft_strsplit(av[0], ' ');
    else if (ac > 2)
    {
        if (!(str = (char **)malloc(sizeof(char *) * ac)))
            return (0);
        while (av[i])
            str[i] = ft_strdup((const char *)av[i++]);
        str[i] = NULL;
    }
    if (!*str)
        return (NOARG);
    if ((ret = check_stack(str)))
        return (ret);
    creat_stack(&stack->stack[A], str);
    stack->stack[A]->letter = 'a';
    stack->stack[B] = creat_linkedlist();
    stack->stack[B]->letter = 'b';
    return (ret);
}