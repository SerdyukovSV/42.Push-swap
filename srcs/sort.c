#include "../includes/push_swap.h"

int get_median(t_node *list)
{
    int max;
    int min;

    max = min = list->data;
    while (list)
    {
        if (max < list->data)
            max = list->data;
        if (min > list->data)
            min = list->data;
        list = list->next;
    }
    return ((max + min) / 2);
}

int get_len_substack(t_node *list, int med)
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

void    small_sort(t_linklist *stack)
{
    // printf("small_sort\n");
    if (!issort(stack))
    {
        if (stack->head->data > stack->head->next->data)
            if (stack->head->data > stack->head->next->next->data)
                rotate(stack);
            else
                swap(stack);
        else
            revrotate(stack);
        small_sort(stack);
    }
    else
        return ;
}

void    sort_stack(t_stack *stack)
{
    if (stack->stack[A]->size <= 3)
        small_sort(stack->stack[A]);
    else if (stack->stack[A]->size <= 6)
        ;
    else
        quick_sort(stack->stack[A], stack->stack[B]);
}