/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:09:49 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/04 16:43:16 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_elem(t_stack **data, int elem)
{
	t_stack	*new;

	new = ft_newlst(elem);
	new->next = *data;
	*data = new;
}

void	swap_elem(t_stack **data)
{
	int	temp;

	if (*data == NULL || (*data)->next == NULL)
		return ;
	temp = (*data)->content;
	(*data)->content = (*data)->next->content;
	(*data)->next->content = temp;
}

void	push_to_stack(t_stack **src, t_stack **dest)
{
	int	elem;

	if (*src == NULL)
		return ;
	elem = remove_elem(src);
	push_elem(dest, elem);
}

void	rotate_stack(t_stack **data)
{
	t_stack	*last;

	if (*data == NULL || (*data)->next == NULL)
		return ;
	last = *data;
	while (last->next != NULL)
		last = last->next;
	last->next = *data;
	*data = (*data)->next;
	last->next->next = NULL;
}

void	reverse_rotate_stack(t_stack **data)
{
	t_stack	*prev;
	t_stack	*current;

	if (*data == NULL || (*data)->next == NULL)
		return ;
	prev = NULL;
	current = *data;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	current->next = *data;
	*data = current;
	prev->next = NULL;
}
