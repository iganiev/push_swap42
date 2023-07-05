/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:03:33 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/04 12:34:26 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	swap_elem(stack_a);
	ft_printf("sa\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push_to_stack(stack_b, stack_a);
	ft_printf("pa\n");
}

void	ra(t_stack **stack_a)
{
	rotate_stack(stack_a);
	ft_printf("ra\n");
}

void	rra(t_stack **stack_a)
{
	reverse_rotate_stack(stack_a);
	ft_printf("rra\n");
}
