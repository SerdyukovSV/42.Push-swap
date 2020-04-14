#include "../includes/push_swap.h"

static void    print_stack(t_linklist *src, t_linklist *dst)
{
    t_node *tmp;
    tmp = src->head;
    printf("stack_a = ");
    while (tmp)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");

    tmp = dst->head;
    printf("stack_b = ");
    while (tmp)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
    sleep(1);
}

void    swap_stack(t_linklist *src, t_linklist *dst)
{
    // printf("swap_stack\n");
    int i;

    i = 0;
    if (dst->letter == 'b' && dst->size > 1 && dst->head->data < dst->head->next->data && ++i)
        doub_swap(src, dst);
    else if (dst->letter == 'a' && dst->head->data > dst->head->next->data && ++i)
        doub_swap(src, dst);
    else
        swap(src);
    printf("s%c\n", (i != 0 ? 's' : src->letter));
}

void    push_stack(t_linklist *src, t_linklist *dst, int med)
{
    // int i;

    // i = 0;
    // if (src->letter == 'a')
    //     if (src->head->data < src->head->next->data)
    //         if (src->head->data < src->tail->data && ++i)
    //             push(src, dst);
    // else if (src->letter == 'b')
    //     if (src->head->next && src->head->data > src->head->next->data)
    //         if (src->head->data > src->tail->data && ++i)
    //             push(src, dst);
    // (i == 1) ? printf("p%c\n", src->letter) : 0;
    push(src, dst);
    printf("p%c\n", src->letter)
}

void    revrotate_stack(t_linklist *src, t_linklist *dst, int med)
{
    int i;

    i = 0;
    if (src->letter == 'a' && src->tail->data < src->head->data && src->head->data < med)
        if (dst->tail->data > dst->head->data && ++i)
            doub_revrotate(src, dst);
        else
            revrotate(src);
    else if (src->letter == 'b' && src->tail->data > src->head->data)
        if (dst->tail->data > dst->head->data && ++i)
            doub_revrotate(src, dst);
        else
            revrotate(src);
    else if (dst->letter == 'b' && dst->tail->data > dst->head->data)
    {
            revrotate(dst);
            i = 2;
    }
    if (i == 2)
        printf("rr%c\n", dst->letter);
    else
        printf("rr%c\n", (i == 1 ? 'r' : src->letter));
}

void    rotate_stack(t_linklist *src, t_linklist *dst, int med)
{
    int i;

    i = 0;
    if (src->letter == 'a' /* && (src->head->data && src->head->next->data) > med */)
        if (dst->head->data < dst->tail->data && ++i)
            doub_rotate(src, dst);
        else
            rotate(src);
    else if (src->letter == 'b' && src->head->data < src->tail->data)
            rotate(src);
    else if (dst->letter == 'b' && dst->head->data < dst->tail->data)
    {
            rotate(dst);
            i = 2;
    }
    if (i == 2)
        printf("rr%c\n", dst->letter);
    else
        printf("rr%c\n", (i == 1 ? 'r' : src->letter));
}

static void merger_stack(t_linklist *src, t_linklist *dst)
{
    while (src->size > 0)
    {
        if (src->head->next && src->head->data < src->head->next->data)
            swap_stack(src, dst);
        else
            push(src, dst);
        // print_stack(src, dst); //////////////////////////////////////////////////
    }
}

static void split_stack(t_linklist *src, t_linklist *dst, int med)
{
    while (get_len_substack(src->head, med))
    {
        if (src->head->next->data > src->head->data < med)
            if (src->tail->data > src->head->data)
                push_stack(src, dst, med);
        if (src->head->next->data < src->head->data < med || )
            if (src->head->data)
            swap_stack(src, dst);
        else if (src->tail->data < med)
            revrotate(src);
        else
            rotate(src);
        // print_stack(src, dst); //////////////////////////////////////////////////
    }
}

void    quick_sort(t_linklist *src, t_linklist *dst)
{
    if ((src->letter == 'a') && !issort(src))
    {
        if (src->size > 3)
            split_stack(src, dst, get_median(src->head));
        else
        {
            small_sort(src);
            // print_stack(src, dst); //////////////////////////////////////////////////
        }
        quick_sort(src, dst);
    }
    else if (dst->size > 0)
    {
        merge_stack(dst, src);
    }
    else if (!issort(src))
        quick_sort(src, dst);
}
