#include "../includes/push_swap.h"

void	mini_sort(t_linklist *lst, t_stack *stack)
{
	// printf("mini_sort\n");
	if (!issort(lst))
	{
		if (lst->head->data > lst->head->next->data)
			swap(lst, stack);
		else if (lst->head->next->data > lst->tail->data)
			revrotate(lst, stack);
		else
			rotate(lst, stack);
		mini_sort(lst, stack);
	}
}

void	small_sort(t_linklist *lst, t_stack *stack)
{
	if (!issort(lst))
	{
		if (lst->size > 3)
		{

				swap(lst, stack);
		}
		else
			revrotate(lst, stack);
		small_sort(lst, stack);
	}
}

void	quick_sort(t_linklist *src, t_linklist *dst, t_stack *stack)
{
	// printf("quick_sort\n");
	stack->div = 2;
	if (!issort(src))
		split_stack(src, dst, stack);
	else if (dst->size > 0)
		merger_stack(src, dst, stack);
	else
		return ;
	quick_sort(src, dst, stack);
	
}

void	sort_stack(t_stack *stack, int ind)
{
	// printf("sort_stack\n");
	if (stack->push[STK_A][stack->num_a] <= 3)
		mini_sort(stack->stack[ind], stack);
	// else if (stack->stack[ind]->size <= 6)
	// 	small_sort(stack->stack[ind], stack);
	else
		quick_sort(stack->stack[0], stack->stack[1], stack);
}