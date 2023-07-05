/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:42:18 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/04 16:50:54 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
// int	main()
// {
// 	ft_printf("Hello!\n");
// }

// void	print_stack(t_stack *data)
// {
// 	ft_printf("Stack: ");
// 	while (data != NULL)
// 	{
// 		ft_printf("%d ", data->content);
// 		data = data->next;
// 	}
// 	ft_printf("\n");
// }

// int	stack_len(t_stack *stack)
// {
// 	int	len;

// 	len = 0;
// 	while (stack)
// 	{
// 		len++;
// 		stack = stack->next;
// 	}
// 	return (len);
// }

// void	sort_three(t_stack **stack_a)
// {
// 	int	top;
// 	int	mid;
// 	int	bot;

// 	top = (**stack_a).content;
// 	mid = (**stack_a).next->content;
// 	bot = (**stack_a).next->next->content;
// 	if ((top > mid) && (bot > top))
// 		sa(stack_a);
// 	else if ((top > mid) && (mid > bot))
// 	{
// 		sa(stack_a);
// 		rra(stack_a);
// 	}
// 	else if ((top > mid) && (mid < bot))
// 		ra(stack_a);
// 	else if ((top < mid) && (mid > bot) && (top < bot))
// 	{
// 		sa(stack_a);
// 		ra(stack_a);
// 	}
// 	else if ((top < mid) && (mid > bot) && (top > bot))
// 		rra(stack_a);
// }

// int	lst_last(t_stack *head)
// {
// 	if (!head)
// 		return (0);
// 	while (head && head->next)
// 		head = head->next;
// 	return (head->content);
// }

// int	find_smallest_elem_pos(t_stack *data)
// {
// 	int		pos;
// 	int		smallest_pos;
// 	t_stack	*current;
// 	t_stack	*smallest_elem;

// 	pos = 1;
// 	smallest_pos = 1;
// 	if (data == NULL)
// 		return (0);
// 	current = data;
// 	smallest_elem = data;
// 	while (current != NULL)
// 	{
// 		if (current->content < smallest_elem->content)
// 		{
// 			smallest_elem = current;
// 			smallest_pos = pos;
// 		}
// 		pos++;
// 		current = current->next;
// 	}
// 	return (smallest_pos);
// }

// int	check_elem(t_stack *stack, int pos)
// {
// 	int	stack_size;

// 	stack_size = stack_len(stack);
// 	if (pos <= stack_size / 2)
// 		return (1);
// 	else
// 		return (-1);
// }

// void	push_smallest_to_b(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	len_a;
// 	int	elem_pos;
// 	int	move_elem;

// 	len_a = stack_len(*stack_a);
// 	elem_pos = find_smallest_elem_pos(*stack_a);
// 	move_elem = check_elem(*stack_a, elem_pos);
// 	if 	(move_elem == 1)
// 	{
// 		elem_pos = elem_pos - 1;
// 		while (elem_pos-- > 0)
// 			ra(stack_a);
// 	}
// 	else
// 	{
// 		elem_pos = len_a - elem_pos + 1;
// 		while (elem_pos-- > 0)
// 			rra(stack_a);
// 	}
// 	pb(stack_a, stack_b);
// }

// void	sort_more(t_stack **stack_a)
// {
// 	t_stack	*stack_b;
// 	int		len_a;
// 	int		push_elems;

// 	stack_b = NULL;
// 	len_a = stack_len(*stack_a);
// 	if (len_a < 4 || len_a > 10)
// 		return ;
// 	push_elems = len_a - 3;
// 	while (push_elems > 0)
// 	{
// 		push_smallest_to_b(stack_a, &stack_b);
// 		push_elems--;
// 	}
// 	sort_three(stack_a);
// 	while (stack_b)
// 		pa(stack_a, &stack_b);
// }

int main(int argc, char *argv[]) 
{
    t_stack	*stack_a = NULL;

    // Populate stack A with command line arguments
    for (int i = 1; i < argc; i++)
	{
        int elem = ft_atoi(argv[i]);
        push_elem(&stack_a, elem);
    }

    ft_printf("Before sorting:\n");
    print_stack(stack_a);
    sort_more(&stack_a);
    ft_printf("After sorting:\n");
    print_stack(stack_a);
    return 0;
}
