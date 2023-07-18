/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <g.ibrogim98@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:44:15 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/18 23:15:15 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf42/ft_printf.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				target;
	int				price;
	int				index;
	// int				data;
	// int				current_pos;
	// int				cost_a;
	// int				cost_b;
	int				sort_index;
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_var
{
	int			*all_numbers;
	int			i;
	long long 	elem;
	int			count_elem;
}	t_var;

t_stack	*ft_newlst(int content);
int		stack_len(t_stack *stack);
int		remove_elem(t_stack **data);
int		lst_last(t_stack *head);
void	print_stack(t_stack *data);
int		ft_isspace(const int c);
void	ft_free(char **array);

void	push_elem(t_stack **node, int elem);
void	swap_elem(t_stack **node);
void	push_to_stack(t_stack **src, t_stack **dest);
void	rotate_stack(t_stack **node);
void	reverse_rotate_stack(t_stack **node);

void	sa(t_stack **stack_a);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rra(t_stack **stack_a);

void	sb(t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rb(t_stack **stack_b);
void	rrb(t_stack **stack_b);

void	ss(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void	sort_three(t_stack **stack_a);
void	sort_more(t_stack **stack_a);

int		find_smallest_elem_pos(t_stack *data);
int		check_elem_pos(t_stack *stack, int pos);
void	push_smallest_to_b(t_stack **stack_a, t_stack **stack_b);

int		parse_args(int ac, char *av[], int **int_array);
t_stack	*create_stack(int count, const int *arr);
void	free_stack(t_stack *top);
int		is_sorted(const t_stack *stack);
void	quick_sort(t_stack **stack_a, t_stack **stack_b);
// void	push_swap(t_stack **stack_a);
void	push_swap(t_stack **stack_a, t_stack **stack_b);

#endif
