/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:33:10 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/25 08:02:18 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(t_stack *stack_a, int len)
{
	int		*temp_array;
	t_stack	*current;
	int		median_index;
	int		median;
	int		i;

	median_index = len / 2;
	median = 0;
	temp_array = malloc(sizeof(int) * len);
	if (temp_array == NULL)
		return (-1);
	current = stack_a;
	i = 0;
	while (current != NULL)
	{
		temp_array[i] = current->content;
		current = current->next;
		i++;
	}
	sort_int_array(&temp_array, len);
	median = temp_array[median_index];
	free(temp_array);
	return (median);
}

void	quick_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;
	int	i;
	int	pivot;

	len_a = stack_len(*stack_a);
	if (len_a > 3)
	{
		i = 0;
		pivot = find_median(*stack_a, len_a);
		while (i < len_a / 2 - 1)
		{
			if ((*stack_a)->content < pivot)
			{
				pb(stack_a, stack_b);
				i++;
			}
			else
				ra(stack_a);
		}
		quick_sort(stack_a, stack_b);
	}
}

void	sort_a(t_stack **stack_a)
{
	int	elem_pos;
	int	move_elem;
	int	len_a;

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
}

void	move_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*lowest_price;

	while (*stack_b != NULL)
	{
		get_target_pos(stack_a, stack_b);
		get_price(stack_a, stack_b);
		lowest_price = find_lowest_price(*stack_b);
		move_to_top(stack_a, stack_b, lowest_price);
		pa(stack_a, stack_b);
	}
}

void	push_swap(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	quick_sort(stack_a, &stack_b);
	sort_three(stack_a);
	move_to_a(stack_a, &stack_b);
	sort_a(stack_a);
	free_stack(stack_b);
}
