#include "../includes/push_swap.h"

int get_median(t_linklist *stack, int div)
{
    t_node *list;
    int max;
    int min;
    int ret;

    list = stack->head;
    max = min = list->data;
    while (list)
    {
        (max < list->data) ? max = list->data : 0;
        (min > list->data) ? min = list->data : 0;
        list = list->next;
    }
    if (stack->size > 20)
        if ((ret = (max + min) / div) <= min)
            return (get_median(stack, div - 1));
        else
            return (ret);
    else
        ret = (max + min) / 2;
    return (ret);
}

int is_substack(t_node *list, int med)
{
    while (list)
        if (list->data < med)
            return (1);
        else
            list = list->next;
    return (0);
}

int issort(t_linklist *stack)
{
    t_node *tmp;

    tmp = stack->head;
    if (stack->letter == 'a')
        while (tmp->next && tmp->data < tmp->next->data)
            tmp = tmp->next;
    else
        while (tmp->next && tmp->data > tmp->next->data)
            tmp = tmp->next;
    return (!(stack->letter == 'a' ? tmp->next : tmp->prev));
}

void    small_sort(t_linklist *list, t_stack *stack)
{
    if (!issort(list))
    {
        if (list->size > 2 && list->head->data > list->head->next->data)
            if (list->head->data > list->head->next->next->data)
                rotate(list, stack);
            else
                swap(list, stack);
        else
            revrotate(list, stack);
        small_sort(list, stack);
    }
}

void    sort_stack(t_stack *stack)
{
    if (stack->stack[0]->size <= 3)
        small_sort(stack->stack[0], stack);
    else
        quick_sort(stack->stack[0], stack->stack[1], stack);
}