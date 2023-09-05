/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:50:51 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/25 15:52:19 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_error(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(*stack_a);
	free_stack(*stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

void	free_all(t_stack **stack_a, t_stack **stack_b, int *int_array)
{
	free_stack(*stack_a);
	free_stack(*stack_b);
	free(int_array);
}

void	check_sorted(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a) && *stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
