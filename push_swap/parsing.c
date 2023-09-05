/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:43:29 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/25 16:50:01 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ps_atoi(const char *str)
{
	size_t		i;
	long		sign;
	long long	nbr;
	long long	temp;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' && ++i)
		sign = -1;
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = nbr;
		nbr = (nbr * 10) + (str[i] - '0');
		if (nbr < temp)
			return (2147483649);
		i++;
	}
	return (nbr * sign);
}

int	check_valid_nums(char **num_array)
{
	t_var	var;

	var.count_elem = 0;
	if (!num_array || !*num_array)
		return (0);
	while (num_array[var.count_elem])
		var.count_elem++;
	var.all_numbers = malloc(sizeof(int) * var.count_elem);
	var.i = 0;
	while (num_array[var.i])
	{
		if (valid_elem(num_array[var.i]) == -1)
			return (free(var.all_numbers), -1);
		var.elem = ps_atoi(num_array[var.i]);
		if (var.elem > INT_MAX || var.elem < INT_MIN)
			return (free(var.all_numbers), -1);
		var.all_numbers[var.i] = var.elem;
		var.i++;
	}
	if (check_duplicates(var.all_numbers, var.count_elem))
		return (free(var.all_numbers), -1);
	return (free(var.all_numbers), var.count_elem);
}

int	parse_args(int ac, char *av[], int **int_array)
{
	char	*joined_args;
	char	**split_args;
	int		valid_args;
	int		i;

	if (check_all_spaces(ac, av) == -1)
		return (-1);
	joined_args = join_arguments(ac, av);
	split_args = ft_split(joined_args, ' ');
	free(joined_args);
	valid_args = check_valid_nums(split_args);
	if (valid_args == -1)
		return (ft_free(split_args), -1);
	*int_array = malloc(sizeof(int) * valid_args);
	if (int_array == NULL)
		return (ft_free(split_args), -1);
	i = 0;
	while (i < valid_args)
	{
		(*int_array)[i] = ps_atoi(split_args[i]);
		i++;
	}
	ft_free(split_args);
	return (valid_args);
}
