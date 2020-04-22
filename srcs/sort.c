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

void    small_sort(t_linklist *stack)
{
    // printf("small_sort\n");
    if (!issort(stack))
    {
        if (stack->size > 2 && stack->head->data > stack->head->next->data)
            if (stack->head->data > stack->head->next->next->data)
                rotate(stack, 1);
            else
                swap(stack, 1);
        else
            revrotate(stack, 1);
        small_sort(stack);
    }
}

void    sort_stack(t_stack *stack)
{
    // printf("sort_stack\n");
    if (stack->stack[0]->size <= 3)
        small_sort(stack->stack[0]);
    else
        quick_sort(stack->stack[0], stack->stack[1]);
}