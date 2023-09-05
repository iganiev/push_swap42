/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:09:49 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/19 21:17:26 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_elem(t_stack **node, int elem)
{
	t_stack	*new_node;

	new_node = ft_newlst(elem);
	if (*node == NULL)
	{
		*node = new_node;
	}
	else
	{
		new_node->next = *node;
		*node = new_node;
	}
}

void	swap_elem(t_stack **node)
{
	int	temp;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	temp = (*node)->content;
	(*node)->content = (*node)->next->content;
	(*node)->next->content = temp;
}

void	push_to_stack(t_stack **src, t_stack **dest)
{
	int	elem;

	if (*src == NULL)
		return ;
	elem = remove_elem(src);
	push_elem(dest, elem);
}

void	rotate_stack(t_stack **node)
{
	t_stack	*last;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	last = *node;
	while (last->next != NULL)
		last = last->next;
	last->next = *node;
	*node = (*node)->next;
	last->next->next = NULL;
}

void	reverse_rotate_stack(t_stack **node)
{
	t_stack	*prev;
	t_stack	*current;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	prev = NULL;
	current = *node;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	current->next = *node;
	*node = current;
	prev->next = NULL;
}
