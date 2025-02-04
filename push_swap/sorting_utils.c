/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:53:42 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/19 21:51:28 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest_elem_pos(t_stack *data)
{
	int		pos;
	int		smallest_pos;
	t_stack	*current;
	t_stack	*smallest_elem;

	pos = 1;
	smallest_pos = 1;
	if (data == NULL)
		return (0);
	current = data;
	smallest_elem = data;
	while (current != NULL)
	{
		if (current->content < smallest_elem->content)
		{
			smallest_elem = current;
			smallest_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (smallest_pos);
}

int	check_elem_pos(t_stack *stack, int pos)
{
	int	stack_size;

	stack_size = stack_len(stack);
	if (pos <= stack_size / 2)
		return (1);
	else
		return (-1);
}

void	push_smallest_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;
	int	elem_pos;
	int	move_elem;

	len_a = stack_len(*stack_a);
	elem_pos = find_smallest_elem_pos(*stack_a);
	move_elem = check_elem_pos(*stack_a, elem_pos);
	if (move_elem == 1)
	{
		elem_pos = elem_pos - 1;
		while (elem_pos-- > 0)
			ra(stack_a);
	}
	else
	{
		elem_pos = len_a - elem_pos + 1;
		while (elem_pos-- > 0)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	sort_int_array(int **matrix, int len)
{
	int	i;
	int	temp;
	int	*new;

	new = *matrix;
	i = 0;
	while (i < (len - 1))
	{
		if (new[i] > new[i + 1])
		{
			temp = new[i];
			new[i] = new[i + 1];
			new[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	*matrix = new;
}

int	is_sorted(const t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
