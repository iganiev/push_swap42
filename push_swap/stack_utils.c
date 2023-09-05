/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:06:13 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/19 22:19:00 by iganiev          ###   ########.fr       */
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
	int		len;
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

t_stack	*create_stack(int count, const int *arr)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = count - 1;
	while (i >= 0)
	{
		push_elem(&stack, arr[i]);
		i--;
	}
	return (stack);
}
