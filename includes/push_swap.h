/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:26:26 by gartanis          #+#    #+#             */
/*   Updated: 2020/07/03 17:06:54 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define OUTPUT_PS		"OPERATIONS.txt"

# define NOARG			(1 << 0)
# define EOVERFLOW		(1 << 1)
# define DUBLICATE		(1 << 2)
# define ARGNOINT		(1 << 3)
# define ERR			(1 << 4)

# define ERR_M			"\033[31;1merror:\033[00m"
# define NOARG_MS		"\033[39;1mmissing arguments\033[0m"
# define EOVERFLOW_MS	"\033[39;1mvalue too large in data type\033[0m"
# define DUBLICATE_MS	"\033[39;1mthere are duplicates\033[0m"
# define ARGNOINT_MS	"\033[39;1margument are not integer\033[0m"
# define OK				"\033[32;1mOK\033[00m"
# define KO				"\033[31;1mKO\033[00m"
# define AUTO			"\033[32;1mauto\033[0m"
# define MANUAL			"\033[32;1mmanual\033[0m"

# define OPT_V			(1 << 0)
# define OPT_C			(1 << 1)
# define OPT_F			(1 << 2)

# define A				(0)
# define B				(1)

typedef struct		s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
}					t_node;

typedef struct		s_linklist
{
	t_node			*head;
	t_node			*tail;
	int				size;
	char			letter;
}					t_linklist;

typedef struct		s_stack
{
	char			*prg;
	int				div;
	int				opt;
	int				fd;
	int				print;
	int				deb_mode;
	int				push[2][4096];
	int				num_a;
	int				num_b;
	int				count;
	t_linklist		*stack[2];
}					t_stack;

/*
**	Initialization functions
*/

int					init_stack(t_stack *stack, char *av[], int ac);
char				**get_arg(t_stack *stack, int ac, char *av[]);
t_linklist			*creat_linkedlist(char stack);
int					check_stack(char **str);
void				free_stack(t_stack *stack);

/*
**	Supporting functions
*/

int					get_median(t_stack *stack, int stk, int num);
int					is_substack(t_stack *stack, int med, int s);
int					issort(t_linklist *stack);
int					print_error(t_stack *stack, int errcode);
void				print_operation(t_stack *stack, const char *str, \
									const char let);
int					debugging_mode(t_stack *stack);
void				print_stack(t_node *src, t_node *dst, char *opt, \
								t_stack *st);

/*
**	Sorting functions
*/

void				sort_stack(t_stack *stack);
void				mini_sort(t_linklist *lst, t_stack *stack);
void				quick_sort(t_stack *stack);
void				merger_stack(t_stack *stack, int med);
void				split_stack(t_stack *stack, int med);

/*
**	Execution of instructions
*/

void				rotate(t_linklist *lst, t_stack *stack);
void				revrotate(t_linklist *lst, t_stack *stack);
void				swap(t_linklist *lst, t_stack *stack);
void				push(t_linklist *src, t_linklist *dst, t_stack *stack);
void				doub_opt(t_stack *stack, char *op, void (*f)(t_linklist *,\
							t_stack *));
void				ps_operations(char *op, t_linklist *src, t_stack *st);

#endif
