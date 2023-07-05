/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:23:59 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/04 12:35:13 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **stack_b)
{
	swap_elem(stack_b);
	ft_printf("sb\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push_to_stack(stack_a, stack_b);
	ft_printf("pb\n");
}

void	rb(t_stack **stack_b)
{
	rotate_stack(stack_b);
	ft_printf("rb\n");
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate_stack(stack_b);
	ft_printf("rrb\n");
}
