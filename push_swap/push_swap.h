/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:44:15 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/04 16:50:30 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf42/ft_printf.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_newlst(int content);
int		stack_len(t_stack *stack);
int		remove_elem(t_stack **data);
int		lst_last(t_stack *head);
void	print_stack(t_stack *data);

void	push_elem(t_stack **data, int elem);
void	swap_elem(t_stack **data);
void	push_to_stack(t_stack **src, t_stack **dest);
void	rotate_stack(t_stack **data);
void	reverse_rotate_stack(t_stack **data);

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
int		check_elem(t_stack *stack, int pos);
void	push_smallest_to_b(t_stack **stack_a, t_stack **stack_b);

#endif
