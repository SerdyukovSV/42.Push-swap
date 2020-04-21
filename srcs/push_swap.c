#include "../includes/push_swap.h"

void    print_stack(t_stack *stack)
{
    t_node *tmp;
    tmp = stack->stack[A]->head;
    printf("stack_a = ");
    while (tmp)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");

    tmp = stack->stack[B]->head;
    printf("stack_b = ");
    while (tmp)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int main(int ac, char *av[])
{
    // printf("Push_swap\n");
    t_stack stack;
    int ret;

    ret = 0;
    stack.prg = *av;
    if (ac < 2)
        return (print_error(stack, NOARG));
    av += 1;
    if ((ret = init_stack(&stack, av, ac)))
        return (print_error(stack, ret));
///////////////////////////////////
    sort_stack(&stack);
    // print_stack(&stack);
    
    return (ret);
}