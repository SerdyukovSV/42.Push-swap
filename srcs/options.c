#include "../includes/push_swap.h"

void    revrotate(t_linklist *list, int print)
{
    t_node *tmp;

    tmp = list->tail;
    tmp->next = list->head;
    list->head->prev = tmp;
    list->head = tmp;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    list->head->prev = NULL;
    print ? printf("rr%c\n", list->letter) : 0;
}

void    doub_revrotate(t_linklist *src, t_linklist *dst, int print)
{
    revrotate(src, 0);
    revrotate(dst, 0);
    print ? printf("rrr\n") : 0;
}

void    rotate(t_linklist *list, int print)
{
    list->tail->next = list->head;
    list->head->prev = list->tail;
    list->tail = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    list->tail->next = NULL;
    print ? printf("r%c\n", list->letter) : 0;
}

void    doub_rotate(t_linklist *src, t_linklist *dst, int print)
{
    rotate(src, 0);
    rotate(dst, 0);
    print ? printf("rr\n") : 0;
}

void    swap(t_linklist *list, int print)
{
    int tmp;

    tmp = list->head->data;
    list->head->data = list->head->next->data;
    list->head->next->data = tmp;
    print ? printf("s%c\n", list->letter) : 0;
}

void    doub_swap(t_linklist *src, t_linklist *dst, int print)
{
    swap(src, 0);
    swap(dst, 0);
    print ? printf("ss\n") : 0;
}

void    push(t_linklist *src, t_linklist *dst, int print)
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
    print ? printf("p%c\n", dst->letter) : 0;
}