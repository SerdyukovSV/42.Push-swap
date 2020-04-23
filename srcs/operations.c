#include "../includes/push_swap.h"

void    revrotate(t_linklist *list, t_stack *stack)
{
    t_node *tmp;

    tmp = list->tail;
    tmp->next = list->head;
    list->head->prev = tmp;
    list->head = tmp;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    list->head->prev = NULL;
    ft_print_options(stack, "rr", list->letter);
}

void    doub_revrotate(t_linklist *src, t_linklist *dst, t_stack *stack)
{
    int i;

    i = stack->print ? stack->print : 0;
    stack->print ? stack->print = 0 : 0;
    revrotate(src, stack);
    revrotate(dst, stack);
    stack->print = i;
    ft_print_options(stack, "rrr", 0);
}

void    rotate(t_linklist *list, t_stack *stack)
{
    list->tail->next = list->head;
    list->head->prev = list->tail;
    list->tail = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    list->tail->next = NULL;
    ft_print_options(stack, "r", list->letter);
}

void    doub_rotate(t_linklist *src, t_linklist *dst, t_stack *stack)
{
    int i;

    i = stack->print ? stack->print : 0;
    stack->print ? stack->print = 0 : 0;
    rotate(src, stack);
    rotate(dst, stack);
    stack->print = i;
    ft_print_options(stack, "rr", 0);
}

void    swap(t_linklist *list, t_stack *stack)
{
    int tmp;

    tmp = list->head->data;
    list->head->data = list->head->next->data;
    list->head->next->data = tmp;
    ft_print_options(stack, "s", list->letter);
}

void    doub_swap(t_linklist *src, t_linklist *dst, t_stack *stack)
{
    int i;

    i = stack->print ? stack->print : 0;
    stack->print ? stack->print = 0 : 0;
    swap(src, stack);
    swap(dst, stack);
    stack->print = i;
    ft_print_options(stack, "ss", 0);
}

void    push(t_linklist *src, t_linklist *dst, t_stack *stack)
{
    t_node *tmp;

    tmp = src->head;
    if (src->head->next)
    {
        src->head = src->head->next;
        src->head->prev = NULL;
    }
    else
        src->head = NULL;
    tmp->next = dst->head;
    tmp->prev = NULL;
    if (dst->head)
        dst->head->prev = tmp;
    dst->head = tmp;
    if (!dst->tail)
        dst->tail = tmp;
    src->size -= 1;
    dst->size += 1;
    ft_print_options(stack, "p", dst->letter);
}