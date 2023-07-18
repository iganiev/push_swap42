/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <g.ibrogim98@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:43:29 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/17 09:43:54 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_duplicates(const int *arr, int size)
{
    int i;
	int j;
	
	i = 0;
    while (i < size)
	{
        j = i + 1;
        while (j < size)
		{
            if (arr[i] == arr[j])
                return 1;
            j++;
        }
        i++;
    }
    return (0);
}

int valid_elem(char *str)
{
    int i;
	
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

int check_valid_nums(char **num_array)
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
		var.elem = ft_atoi(num_array[var.i]);
		if (var.elem == -1 || var.elem < INT_MIN)
			return (free(var.all_numbers), -1);
		var.all_numbers[var.i] = var.elem;
		var.i++;
	}
	if (check_duplicates(var.all_numbers, var.count_elem))
		return (free(var.all_numbers), -1);
	return (free(var.all_numbers), var.count_elem);
}

char *join_arguments(int argc, char *argv[])
{
    char *joined_args;
    int i;
	char *temp;
	
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

int check_all_spaces(int argc, char *argv[])
{
	int	i;

	i = 1;
    while (i < argc)
    {
        int j = 0;
        while (argv[i][j] != '\0')
        {
            if (!ft_isspace(argv[i][j]))
                break;
            j++;
        }
        if (argv[i][j] == '\0')
            return -1;
		i++;
    }
    return (0);
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
		(*int_array)[i] = ft_atoi(split_args[i]);
		i++;
	}
	ft_free(split_args);
	return (valid_args);
}

t_stack *create_stack(int count, const int *arr)
{
    t_stack *stack = NULL;
    int i = count - 1;

    while (i >= 0)
    {
        push_elem(&stack, arr[i]);
        i--;
    }
    return (stack);
}

int is_sorted(const t_stack *stack)
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




// int main(int argc, char *argv[]) 
// {
//     int *int_array;
//     int count;
//     t_stack *stack_a;

//     stack_a = NULL;
//     // printf("Hello\n");
//     count = parse_args(argc, argv, &int_array);
//     if (count == -1)
//     {
//         fprintf(stderr, "Error: Invalid arguments.\n");
//         return 1;
//     }
//     stack_a = create_stack(count, int_array);
    
//     ft_printf("Before sorting:\n");
//     print_stack(stack_a);
//     sort_more(&stack_a);
//     // sort_three(&stack_a);
//     ft_printf("After sorting:\n");
//     print_stack(stack_a);
//     return 0;
// }

// int parser(char **argv)
// {
// 	int i;
// 	char *numbers;
// 	i = 1;
// 	numbers = ft_strdup("");
// 	while (argv[i])
// 	{
// 		numbers = ft_strjoin(numbers, argv[i]);
// 		numbers = ft_strjoin(numbers, " ");
// 		i++;
// 	}
// 	if (check_valid_args(numbers) == -1)
// 		return (-1);
// }

// void	get_stack(int ac, char *av[], t_stack **stack_a)
// {
//     int     i;
//     int     elem;
//     i = ac - 1;
//     while (i > 0)
//     {
//         elem = ft_atoi(av[i]);
//         push_elem(stack_a, elem);
//         i--;
//     }
// }