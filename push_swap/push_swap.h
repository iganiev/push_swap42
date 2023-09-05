/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:44:15 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/25 16:45:01 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf42/ft_printf.h"
# include <limits.h>
# include <stdio.h>

// # define INT_MAX 2147483647
// # define INT_MIN -2147483648
// # define LONG_MAX 9223372036854775807
// # define LONG_MIN -9223372036854775808

typedef struct s_stack
{
	int				target;
	int				price;
	int				cost_a;
	int				cost_b;
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_var
{
	int			*all_numbers;
	int			i;
	long long	elem;
	int			count_elem;

	int			rotations;
	int			target_index;
	int			current_index_a;

	int			moves;
	int			element_index;
	int			current_index_b;
}	t_var;

t_stack	*ft_newlst(int content);
int		stack_len(t_stack *stack);
int		remove_elem(t_stack **data);
t_stack	*create_stack(int count, const int *arr);

int		ft_isspace(const int c);
void	ft_free(char **array);
void	free_stack(t_stack *top);
void	ft_free(char **array);
int		ft_abs(int value);

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
void	sort_it(t_stack **stack_a);

int		find_smallest_elem_pos(t_stack *data);
int		check_elem_pos(t_stack *stack, int pos);
void	push_smallest_to_b(t_stack **stack_a, t_stack **stack_b);
void	sort_int_array(int **matrix, int len);
int		is_sorted(const t_stack *stack);

int		check_duplicates(const int *arr, int size);
int		valid_elem(char *str);
int		check_all_spaces(int argc, char *argv[]);
char	*join_arguments(int argc, char *argv[]);

int		check_valid_nums(char **num_array);
int		parse_args(int ac, char *av[], int **int_array);

int		find_median(t_stack *stack_a, int len);
void	quick_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_a(t_stack **stack_a);
void	move_to_top(t_stack **stack_a, t_stack **stack_b, \
					t_stack *lowest_price_element);
void	move_to_a(t_stack **stack_a, t_stack **stack_b);
void	push_swap(t_stack **stack_a);

void	get_target_pos(t_stack **stack_a, t_stack **stack_b);
int		count_moves_in_a(t_stack *stack, int target);
int		count_moves_in_b(t_stack *stack, int element);
void	get_price(t_stack **stack_a, t_stack **stack_b);
t_stack	*find_lowest_price(t_stack *stack_b);

int		ft_strcmp(char *s1, char *s2);
void	ft_error(t_stack **stack_a, t_stack **stack_b);
void	free_all(t_stack **stack_a, t_stack **stack_b, int *int_array);
void	check_sorted(t_stack **stack_a, t_stack **stack_b);

#endif
