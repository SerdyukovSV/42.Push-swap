#include "../includes/push_swap.h"

void    revrotate(t_linklist *list)
{
    t_node *tmp;

    tmp = list->tail;
    tmp->next = list->head;
    list->head->prev = tmp;
    list->head = tmp;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    list->head->prev = NULL;
    printf("rr%c\n", list->letter);
}

void    doub_revrotate(t_linklist *src, t_linklist *dst)
{
    revrotate(src);
    revrotate(dst);
}

void    rotate(t_linklist *list)
{
    list->tail->next = list->head;
    list->head->prev = list->tail;
    list->tail = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    list->tail->next = NULL;
    printf("r%c\n", list->letter);
}

void    doub_rotate(t_linklist *src, t_linklist *dst)
{
    rotate(src);
    rotate(dst);
}

void    swap(t_linklist *list)
{
    int tmp;

    tmp = list->head->data;
    list->head->data = list->head->next->data;
    list->head->next->data = tmp;
    // printf("s%c\n", list->letter);
}

void    doub_swap(t_linklist *a, t_linklist *b)
{
    swap(a);
    swap(b);
}

void    push(t_linklist *src, t_linklist *dst)
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
    // printf("p%c\n", dst->letter);
}