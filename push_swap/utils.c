/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:06:13 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/04 23:06:32 by iganiev          ###   ########.fr       */
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

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
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
