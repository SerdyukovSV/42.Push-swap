#include "../includes/push_swap.h"

void	doub_revrotate(t_linklist *src, t_linklist *dst, t_stack *stack)
{
	int i;

	i = stack->print ? stack->print : 0;
	stack->print ? stack->print = 0 : 0;
	revrotate(src, stack);
	revrotate(dst, stack);
	stack->print = i;
	print_operation(stack, "rrr", 0);
}

void	doub_rotate(t_linklist *src, t_linklist *dst, t_stack *stack)
{
	int i;

	i = stack->print ? stack->print : 0;
	stack->print ? stack->print = 0 : 0;
	rotate(src, stack);
	rotate(dst, stack);
	stack->print = i;
	print_operation(stack, "rr", 0);
}

void	doub_swap(t_linklist *src, t_linklist *dst, t_stack *stack)
{
	int i;

	i = stack->print ? stack->print : 0;
	stack->print ? stack->print = 0 : 0;
	swap(src, stack);
	swap(dst, stack);
	stack->print = i;
	print_operation(stack, "ss", 0);
}
