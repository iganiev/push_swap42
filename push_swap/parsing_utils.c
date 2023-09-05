/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:20:10 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/19 22:16:49 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_all_spaces(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isspace(argv[i][j]))
				break ;
			j++;
		}
		if (argv[i][j] == '\0')
			return (-1);
		i++;
	}
	return (0);
}

char	*join_arguments(int argc, char *argv[])
{
	char	*joined_args;
	int		i;
	char	*temp;

	joined_args = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		temp = ft_strjoin(joined_args, argv[i]);
		free(joined_args);
		joined_args = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	return (joined_args);
}

int	check_duplicates(const int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_elem(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (-1);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (1);
}
