/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:52:29 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/04 16:41:23 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	middle;
	int	last;

	first = (*stack_a)->content;
	middle = (*stack_a)->next->content;
	last = (*stack_a)->next->next->content;
	if ((first > middle) && (last > first))
		sa(stack_a);
	else if ((first > middle) && (middle > last))
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((first > middle) && (middle < last))
		ra(stack_a);
	else if ((first < middle) && (middle > last) && (first < last))
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((first < middle) && (middle > last) && (first > last))
		rra(stack_a);
}

void	sort_more(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		len_a;
	int		push_elems;

	stack_b = NULL;
	len_a = stack_len(*stack_a);
	if (len_a < 4 || len_a > 10)
		return ;
	push_elems = len_a - 3;
	while (push_elems > 0)
	{
		push_smallest_to_b(stack_a, &stack_b);
		push_elems--;
	}
	sort_three(stack_a);
	while (stack_b)
		pa(stack_a, &stack_b);
}
