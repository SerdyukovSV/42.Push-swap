/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:26:26 by gartanis          #+#    #+#             */
/*   Updated: 2020/06/23 15:44:16 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
// # include <stdio.h>

# define OUTPUT_PS "OPERATIONS.txt"

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

typedef struct		s_substeck
{
	t_linklist		**stack;
	int				size;
	int				total;
}					t_substeck;

typedef struct		s_stack
{
	char			*prg;
	int				div;
	int				opt;
	int				fd;
	int				print;
	int				deb_mode;
	t_linklist		*stack[2];
	t_substeck		*sub;
}					t_stack;

int					init_stack(t_stack *stack, char *av[], int ac);
char				**get_arg(t_stack *stack, int ac, char *av[]);
t_linklist			*creat_linkedlist(char stack);
int					check_stack(char **str);
void				free_stack(t_stack *stack);

int					get_median(t_linklist *stack, int div);
int					is_substack(t_node *head, int med);
int					issort(t_linklist *stack);

int					print_error(t_stack *stack, int errcode);
void				print_operation(t_stack *stack, const char *str, \
									const char let);
int					debugging_mode(t_stack *stack);
void				print_stack(t_node *src, t_node *dst, char *opt, int dmode);
t_linklist			**realloc_substack(t_substeck *substack, int size);

void				sort_stack(t_stack *stack);
void				small_sort(t_linklist *list, t_stack *stack);
void				quick_sort(t_linklist *src, t_linklist *dst, \
								t_stack *stack);
void				merger_stack(t_linklist *src, t_linklist *dst, \
								t_stack *stack);
void				split_stack(t_linklist *src, t_linklist *dst, t_stack *stack);

void				rotate(t_linklist *list, t_stack *stack);
void				doub_rotate(t_linklist *src, t_linklist *dst, \
								t_stack *stack);
void				revrotate(t_linklist *list, t_stack *stack);
void				doub_revrotate(t_linklist *src, t_linklist *dst, \
									t_stack *stack);
void				swap(t_linklist *list, t_stack *stack);
void				doub_swap(t_linklist *src, t_linklist *dst, t_stack *stack);
void				push(t_linklist *src, t_linklist *dst, t_stack *stack);

#endif
