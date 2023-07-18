/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <g.ibrogim98@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:06:13 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/18 23:14:45 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newlst(int content)
{
	t_stack	*new_elem;

	new_elem = (t_stack *)malloc(sizeof(t_stack));
	if (!new_elem)
		return (0);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}

int	stack_len(t_stack *stack)
{
	int	len;
	t_stack	*temp;

	len = 0;
	temp = stack;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

int	remove_elem(t_stack **data)
{
	int		elem;
	t_stack	*temp;

	if (*data == NULL)
		return (0);
	elem = (*data)->content;
	temp = *data;
	*data = (*data)->next;
	free(temp);
	return (elem);
}

int	lst_last(t_stack *head)
{
	if (!head)
		return (0);
	while (head && head->next)
		head = head->next;
	return (head->content);
}

void	print_stack(t_stack *data)
{
	ft_printf("Stack: ");
	while (data != NULL)
	{
		ft_printf("%d ", data->content);
		data = data->next;
	}
	ft_printf("\n");
}

int	ft_isspace(const int c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r');
}

void	ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	// array = NULL;
}

void	free_stack(t_stack *top)
{
    t_stack	*temp;
    while (top != NULL)
	{
        temp = top;
        top = top->next;
        free(temp);
    }
}