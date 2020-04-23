#include "../includes/push_swap.h"

void    swap_stack(t_linklist *src, t_linklist *dst, int med, t_stack *stack)
{
    // printf("swap_stack\n");
    if (src->head->data > src->head->next->data)
        if (src->head->next->data < med)
            if (dst->size > 2 && dst->head->next->data > dst->head->data && \
                dst->head->data > dst->tail->data)
                    doub_swap(src, dst, stack);
            else
                swap(src, stack);
    if (dst->size > 2 && dst->head->next->data > dst->head->data)
        if (dst->head->data > dst->tail->data)
            swap(dst, stack);
}

void    revrotate_stack(t_linklist *src, t_linklist *dst, int med, t_stack *stack)
{
    // printf("revrotate_stack\n");
    if (src->head->data > src->tail->data)
        if (src->tail->data < med)
            if (dst->size > 2 && dst->head->next->data < dst->head->data && \
                dst->head->data < dst->tail->data)
                    doub_revrotate(src, dst, stack);
            else
                revrotate(src, stack);
    if (dst->size > 2 && dst->head->next->data < dst->head->data)
        if (dst->head->data < dst->tail->data)
            revrotate(dst, stack);
}

void    rotate_stack(t_linklist *src, t_linklist *dst, int med, t_stack *stack)
{
    // printf("rotate_stack\n");
    if (src->head->data >= med)
        if (med <= src->head->next->data)
            if (dst->size > 2 && dst->head->next->data > dst->head->data && \
                dst->head->data < dst->tail->data)
                    doub_rotate(src, dst, stack);
            else
                rotate(src, stack);
    if (dst->size > 2 && dst->head->next->data > dst->head->data)
        if (dst->head->data < dst->tail->data)
            rotate(dst, stack);
}

static void merger_stack(t_linklist *src, t_linklist *dst, t_stack *stack)
{
    // printf("merger_stack\n");
    while (issort(src) && dst->size > 0)
    {
        if (dst->size > 1 && dst->head->data > dst->head->next->data)
        {
            if (dst->head->data > dst->tail->data)
                push(dst, src, stack);
        }
        else if (dst->size < 3)
            push(dst, src, stack);
        swap_stack(src, dst, get_median(src, stack->div), stack);
        revrotate_stack(src, dst, get_median(src, stack->div), stack);
        rotate_stack(src, dst, get_median(src, stack->div), stack);
    }
}

static void split_stack(t_linklist *src, t_linklist *dst, int med, t_stack *stack)
{
    // printf("split_stack\n");
    // printf("med %d\n", med);
    while (is_substack(src->head, med) && !issort(src) && src->size > 3)
    {
        if (src->head->data < src->head->next->data && src->head->data < med)
            if (src->head->data < src->tail->data)
                push(src, dst, stack);
        swap_stack(src, dst, med, stack);
        revrotate_stack(src, dst, med, stack);
        rotate_stack(src, dst, med, stack);
    }
}

void    quick_sort(t_linklist *src, t_linklist *dst, t_stack *stack)
{
    // printf("quick_sort\n");
    stack->div = 4;
    if (!issort(src))
    {
        if (src->size > 3)
            split_stack(src, dst, get_median(src, stack->div), stack);
        else
            small_sort(src, stack);
        quick_sort(src, dst, stack);
    }
    else if (dst->size > 0)
    {
        merger_stack(src, dst, stack);
        quick_sort(src, dst, stack);
    }
}
