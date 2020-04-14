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
///////////////////////////////////
    tmp = stack->stack[B]->head;
    printf("stack_b = ");
    while (tmp)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int print_error(t_stack stack, int errcode)
{
    if (errcode & NOARG)
        printf("\033[39;1m%s:\033[0m %s %s\n", stack.prg, ERR_M, NOARG_MS);
    if (errcode & EOVERFLOW)
        printf("\033[39;1m%s:\033[0m %s %s\n", stack.prg, ERR_M, EOVERFLOW_MS);
    if (errcode & DUBLICATE)
        printf("\033[39;1m%s:\033[0m %s %s\n", stack.prg, ERR_M, DUBLICATE_MS);
    if (errcode & ARGNOINT)
        printf("\033[39;1m%s:\033[0m %s %s\n", stack.prg, ERR_M, ARGNOINT_MS);
    return (0);
}

int main(int ac, char **av)
{
    t_stack stack;
    int ret;

    ret = 0;
    stack.prg = *av;
    if (ac < 2)
        return (print_error(stack, NOARG));
    av += 1;
    if ((ret = init_stack(&stack, *av)))
        return (print_error(stack, ret));
///////////////////////////////////
    t_node *tmp;
    tmp = stack.stack[A]->head;
    printf("stack_a = ");
    while (tmp)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
///////////////////////////////////
    sort_stack(&stack);
    print_stack(&stack);
    
    return (ret);
}