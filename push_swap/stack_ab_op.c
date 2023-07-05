/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:27:28 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/04 12:37:59 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_elem(stack_a);
	swap_elem(stack_b);
	ft_printf("ss\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	ft_printf("rr\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
	ft_printf("rrr\n");
}
