#include "../includes/push_swap.h"

static void	swap_stack(t_linklist *src, t_linklist *dst, int med, t_stack *stack)
{
	if (src->head->data > src->head->next->data)
		if (src->head->next->data < med)
		{
			if (dst->size > 2 && dst->head->next->data > dst->head->data && \
				dst->head->data > dst->tail->data)
				doub_swap(src, dst, stack);
			else
				swap(src, stack);
		}
	if (dst->size > 2 && dst->head->next->data > dst->head->data)
		if (dst->head->data > dst->tail->data)
			swap(dst, stack);
}

static void	revrotate_stack(t_linklist *src, t_linklist *dst, int med, t_stack *stack)
{
	if (src->head->data > src->tail->data)
		if (src->tail->data < med)
		{
			if (dst->size > 2 && dst->head->next->data < dst->head->data && \
				dst->head->data < dst->tail->data)
				doub_revrotate(src, dst, stack);
			else
				revrotate(src, stack);
		}
	if (dst->size > 2 && dst->head->next->data < dst->head->data)
		if (dst->head->data < dst->tail->data)
			revrotate(dst, stack);
}

static void	rotate_stack(t_linklist *src, t_linklist *dst, int med, t_stack *stack)
{
	if (src->head->data >= med)
		if (med <= src->head->next->data)
		{
			if (dst->size > 2 && dst->head->next->data > dst->head->data && \
				dst->head->data < dst->tail->data)
				doub_rotate(src, dst, stack);
			else
				rotate(src, stack);
		}
	if (dst->size > 2 && dst->head->next->data > dst->head->data)
		if (dst->head->data < dst->tail->data)
			rotate(dst, stack);
}

void		merger_stack(t_linklist *src, t_linklist *dst, t_stack *stack)
{
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

void		split_stack(t_linklist *src, t_linklist *dst, int med, t_stack *stack)
{
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
