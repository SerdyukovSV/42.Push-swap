#include "../includes/push_swap.h"

void    *ft_push_front(t_linkedlist *list, int data)
{
    t_node *tmp;

    if (!(tmp = (t_node*)malloc(sizeof(t_node))))
        return (NULL);
    tmp->data = data;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head)
        list->head->prev = tmp;
    list->head = tmp;
    if (!list->tail)
        list->tail = tmp;
    list->size += 1;
    return (tmp);
}

t_linkedlist *creat_linkedlist()
{
    t_linkedlist *tmp;

    printf("creat_linkedlist\n");
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    printf("creat_linkedlist\n");

    return (tmp);
}



t_linkedlist *creat_stack(char **str)
{
    printf("creat_stack\n");
    t_linkedlist *tmp;

    // tmp = creat_linkedlist();
    while (*str)
    {
        // ft_push_front(tmp, ft_atoi(*str));
        printf("%d ", ft_atoi(*str));
        str += 1;
    }
    return (tmp);
}

int init_stack(t_stack *stack, char *arg)
{
    char **str;
    int ret;

    str = ft_strsplit(arg, ' ');
    if (!*str)
        return (NOARG);
    if ((ret = check_stack(str)))
        return (ret);
    stack->stack[STACK_A] = creat_stack(str);

    t_linkedlist *tmp;
    tmp = stack->stack[0];
    int i = 0;
    // while (i++ <= tmp->size)
    // {
    //     printf("head = %d\n", tmp->head->data);
    //     tmp->head = tmp->head->prev;
    // }

    
    return (0);
}