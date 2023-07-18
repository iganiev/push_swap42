/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <g.ibrogim98@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:09:49 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/18 23:00:55 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// void	sa(t_stack **stack_a)
// {
// 	swap_elem(stack_a);
// 	ft_printf("sa\n");
// }

// void	pa(t_stack **stack_a, t_stack **stack_b)
// {
// 	push_to_stack(stack_b, stack_a);
// 	ft_printf("pa\n");
// }

// void	ra(t_stack **stack_a)
// {
// 	rotate_stack(stack_a);
// 	ft_printf("ra\n");
// }

// void	rra(t_stack **stack_a)
// {
// 	reverse_rotate_stack(stack_a);
// 	ft_printf("rra\n");
// }

// void	sb(t_stack **stack_b)
// {
// 	swap_elem(stack_b);
// 	ft_printf("sb\n");
// }

// void	pb(t_stack **stack_a, t_stack **stack_b)
// {
// 	push_to_stack(stack_a, stack_b);
// 	ft_printf("pb\n");
// }

// void	rb(t_stack **stack_b)
// {
// 	rotate_stack(stack_b);
// 	ft_printf("rb\n");
// }

// void	rrb(t_stack **stack_b)
// {
// 	reverse_rotate_stack(stack_b);
// 	ft_printf("rrb\n");
// }

void push_elem(t_stack **node, int elem)
{
    t_stack *new_node = ft_newlst(elem);

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
