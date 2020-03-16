#include "../includes/push_swap.h"

void    ft_push_front(t_linkedlist *list, int data)
{
    t_node *tmp;

    if (!(tmp = (t_node*)malloc(sizeof(t_node))))
        exit (1);
    tmp->data = data;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head)
        list->head->prev = tmp;
    list->head = tmp;
    if (!list->tail)
        list->tail = tmp;
    list->size += 1;
}

t_linkedlist *creat_linkedlist()
{
    t_linkedlist *tmp;

    if (!(tmp = (t_linkedlist*)malloc(sizeof(t_linkedlist))))
        return (NULL);
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;

    return (tmp);
}

void    creat_stack(t_linkedlist **list, char **str)
{
    *list = creat_linkedlist();
    while (*str)
    {
        ft_push_front(*list, ft_atoi(*str));
        str += 1;
    }
}

int init_stack(t_stack *stack, char *arg)
{
    char **str;
    int ret;

    ret = 0;
    str = ft_strsplit(arg, ' ');
    if (!*str)
        return (NOARG);
    if ((ret = check_stack(str)))
        return (ret);
    creat_stack(&stack->stack[STACK_A], str);
    return (ret);
}