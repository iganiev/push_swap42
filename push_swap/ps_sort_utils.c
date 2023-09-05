/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:04:43 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/25 07:54:21 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		smallest_bigger;

	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_b != NULL)
	{
		smallest_bigger = INT_MAX;
		temp_a = *stack_a;
		while (temp_a != NULL)
		{
			if (temp_a->content > temp_b->content
				&& temp_a->content < smallest_bigger)
				smallest_bigger = temp_a->content;
			temp_a = temp_a->next;
		}
		temp_b->target = smallest_bigger;
		temp_b = temp_b->next;
	}
}

int	count_moves_in_a(t_stack *stack, int target)
{
	t_stack	*temp;
	t_var	var;

	temp = stack;
	var.rotations = 0;
	var.target_index = -1;
	var.current_index_a = 0;
	while (temp != NULL)
	{
		if (temp->content == target)
		{
			var.target_index = var.current_index_a;
			break ;
		}
		temp = temp->next;
		var.current_index_a++;
	}
	if (var.target_index >= 0)
	{
		var.rotations = var.target_index;
		if (var.rotations > stack_len(stack) / 2)
			var.rotations = var.rotations - stack_len(stack);
	}
	return (var.rotations);
}

int	count_moves_in_b(t_stack *stack, int element)
{
	t_stack	*temp;
	t_var	var;

	temp = stack;
	var.moves = 0;
	var.element_index = -1;
	var.current_index_b = 0;
	while (temp != NULL)
	{
		if (temp->content == element)
		{
			var.element_index = var.current_index_b;
			break ;
		}
		temp = temp->next;
		var.current_index_b++;
	}
	if (var.element_index >= 0)
	{
		var.moves = var.element_index;
		if (var.moves > stack_len(stack) / 2)
			var.moves = var.moves - stack_len(stack);
	}
	return (var.moves);
}

void	get_price(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		moves_a;
	int		moves_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_b != NULL)
	{
		moves_a = count_moves_in_a(*stack_a, temp_b->target);
		moves_b = count_moves_in_b(*stack_b, temp_b->content);
		temp_b->price = (ft_abs(moves_a) + ft_abs(moves_b));
		temp_b->cost_a = moves_a;
		temp_b->cost_b = moves_b;
		if (temp_a != NULL)
			temp_a = temp_a->next;
		temp_b = temp_b->next;
	}
}

t_stack	*find_lowest_price(t_stack *stack_b)
{
	t_stack	*lowest;
	t_stack	*temp;

	lowest = stack_b;
	temp = stack_b->next;
	while (temp != NULL)
	{
		if (temp->price < lowest->price)
		{
			lowest = temp;
		}
		temp = temp->next;
	}
	return (lowest);
}
