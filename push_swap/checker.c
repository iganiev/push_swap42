/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:34:23 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/25 17:23:18 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	checker(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(line, "sb\n"))
		sb(stack_b);
	else if (!ft_strcmp(line, "ra\n"))
		ra(stack_a);
	else if (!ft_strcmp(line, "rb\n"))
		rb(stack_b);
	else if (!ft_strcmp(line, "rra\n"))
		rra(stack_a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(stack_b);
	else if (!ft_strcmp(line, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(line, "pb\n"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(line, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(line, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(stack_a, stack_b);
	else
		ft_error(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	int		*array;
	int		count_args;
	t_stack	*a;
	char	*line;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	count_args = parse_args(argc, argv, &array);
	if (count_args == -1)
		return (write(2, "Error\n", 6), 0);
	a = create_stack(count_args, array);
	b = NULL;
	line = get_next_line(0);
	if (!line)
		return (check_sorted(&a, &b), free_all(&a, &b, array), 0);
	while (line)
	{
		checker(&a, &b, line);
		free(line);
		line = get_next_line(0);
		if (!line)
			return (check_sorted(&a, &b), free_all(&a, &b, array), 0);
	}
}
