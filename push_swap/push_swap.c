/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:42:18 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/25 15:53:03 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		*int_array;
	int		count_args;
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	count_args = parse_args(argc, argv, &int_array);
	if (count_args == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = create_stack(count_args, int_array);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free(int_array);
		return (0);
	}
	else
		sort_it(&stack_a);
	free_stack(stack_a);
	free(int_array);
}

// void	print_stack(t_stack *data)
// {
// 	ft_printf("Stack: ");
// 	while (data != NULL)
// 	{
// 		ft_printf("%d ", data->content);
// 		data = data->next;
// 	}
// 	ft_printf("\n");
// }
