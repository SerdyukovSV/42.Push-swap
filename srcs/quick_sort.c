#include "../includes/push_swap.h"

void    swap_stack(t_linklist *src, t_linklist *dst, int med)
{
    // printf("swap_stack\n");
    if (src->head->data > src->head->next->data)
        if (src->head->next->data < med)
            if (dst->size > 2 && dst->head->next->data > dst->head->data && \
                dst->head->data > dst->tail->data)
                    doub_swap(src, dst, 1);
            else
                swap(src, 1);
    if (dst->size > 2 && dst->head->next->data > dst->head->data)
        if (dst->head->data > dst->tail->data)
            swap(dst, 1);
}

void    revrotate_stack(t_linklist *src, t_linklist *dst, int med)
{
    // printf("revrotate_stack\n");
    if (src->head->data > src->tail->data)
        if (src->tail->data < med)
            if (dst->size > 2 && dst->head->next->data < dst->head->data && \
                dst->head->data < dst->tail->data)
                    doub_revrotate(src, dst, 1);
            else
                revrotate(src, 1);
    if (dst->size > 2 && dst->head->next->data < dst->head->data)
        if (dst->head->data < dst->tail->data)
            revrotate(dst, 1);
}

void    rotate_stack(t_linklist *src, t_linklist *dst, int med)
{
    // printf("rotate_stack\n");
    if (src->head->data >= med)
        if (med <= src->head->next->data)
            if (dst->size > 2 && dst->head->next->data > dst->head->data && \
                dst->head->data < dst->tail->data)
                    doub_rotate(src, dst, 1);
            else
                rotate(src, 1);
    if (dst->size > 2 && dst->head->next->data > dst->head->data)
        if (dst->head->data < dst->tail->data)
            rotate(dst, 1);
}

static void merger_stack(t_linklist *src, t_linklist *dst)
{
    // printf("merger_stack\n");
while (issort(src) && dst->size > 0)
    {
        if (dst->size > 1 && dst->head->data > dst->head->next->data)
        {
            if (dst->head->data > dst->tail->data)
                push(dst, src, 1);
        }
        else if (dst->size < 3)
            push(dst, src, 1);
        swap_stack(src, dst, get_median(src->head));
        revrotate_stack(src, dst, get_median(src->head));
        rotate_stack(src, dst, get_median(src->head));
    }
}

static void split_stack(t_linklist *src, t_linklist *dst, int med)
{
    // printf("split_stack\n");
    while (is_substack(src->head, med) && !issort(src) && src->size > 3)
    {
        if (src->head->data < src->head->next->data && src->head->data < med)
            if (src->head->data < src->tail->data)
                push(src, dst, 1);
        swap_stack(src, dst, med);
        revrotate_stack(src, dst, med);
        rotate_stack(src, dst, med);
    }
}

void    quick_sort(t_linklist *src, t_linklist *dst)
{
    // printf("quick_sort\n");
    if (!issort(src))
    {
        if (src->size > 3)
            split_stack(src, dst, get_median(src->head));
        else
            small_sort(src);
        quick_sort(src, dst);
    }
    else if (dst->size > 0)
    {
        merger_stack(src, dst);
        quick_sort(src, dst);
    }
}
