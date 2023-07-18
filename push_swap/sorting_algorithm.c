/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <g.ibrogim98@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:52:29 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/19 01:51:39 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	middle;
	int	last;

	first = (*stack_a)->content;
	middle = (*stack_a)->next->content;
	last = (*stack_a)->next->next->content;
	if ((first > middle) && (last > first))
		sa(stack_a);
	else if ((first > middle) && (middle > last))
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((first > middle) && (middle < last))
		ra(stack_a);
	else if ((first < middle) && (middle > last) && (first < last))
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((first < middle) && (middle > last) && (first > last))
		rra(stack_a);
}

void	sort_more(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		len_a;
	int		push_elems;

	stack_b = NULL;
	len_a = stack_len(*stack_a);
	if (len_a < 4 || len_a > 10)
		return ;
	push_elems = len_a - 3;
	while (push_elems > 0)
	{
		push_smallest_to_b(stack_a, &stack_b);
		push_elems--;
	}
	sort_three(stack_a);
	while (stack_b)
		pa(stack_a, &stack_b);
}

void	sort_int_array(int **matrix, int len)
{
	int	i;
	int	temp;
	int	*new;

	new = *matrix;
	i = 0;
	while (i < (len - 1))
	{
		if (new[i] > new[i + 1])
		{
			temp = new[i];
			new[i] = new[i + 1];
			new[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	*matrix = new;
}

int find_median(t_stack *stack_a, int len)
{
    int 	*temp_array;
	t_stack	*current;
    int 	median_index;
    int 	median;
    int 	i;
    
    median_index = len / 2;
    median = 0;
    temp_array = malloc(sizeof(int) * len);
    if (temp_array == NULL)
        return -1;
    current = stack_a;
    i = 0;
    while (current != NULL)
    {
        temp_array[i] = current->content;
        current = current->next;
        i++;
    }
	sort_int_array(&temp_array, len);
    median = temp_array[median_index];
    free(temp_array);
    return median;
}

// int find_largest_elem_pos(t_stack *data)
// {
//     int pos;
//     int largest_pos;
//     t_stack *current;
//     t_stack *largest_elem;

//     pos = 1;
//     largest_pos = 1;
//     if (data == NULL)
//         return 0;
//     current = data;
//     largest_elem = data;
//     while (current != NULL)
//     {
//         if (current->content > largest_elem->content)
//         {
//             largest_elem = current;
//             largest_pos = pos;
//         }
//         pos++;
//         current = current->next;
//     }
//     return largest_pos;
// }

void	quick_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;
	int	i;
	int pivot;


	len_a = stack_len(*stack_a);
	if (len_a > 3)
	{
		i = 0;
		pivot = find_median(*stack_a, len_a);
		// printf("pivot == %d\n", pivot);
		while (i < len_a / 2 - 1)
		{
			if ((*stack_a)->content < pivot)
			{
				pb(stack_a, stack_b);
				i++;
			}
			else
				ra(stack_a);
		}
		quick_sort(stack_a, stack_b);
	}
}

// void	sort_a(t_stack **stack_a)
// {
// 	while (!is_sorted(*stack_a))
// 	{
// 		ra(stack_a);
// 	}
// }

void sort_a(t_stack **stack_a)
{
    int	elem_pos;
	int	move_elem;
	int	len_a;

	len_a = stack_len(*stack_a);
	elem_pos = find_smallest_elem_pos(*stack_a);
	move_elem = check_elem_pos(*stack_a, elem_pos);
	if (move_elem == 1)
	{
		elem_pos = elem_pos - 1;
		while (elem_pos-- > 0)
			ra(stack_a);
	}
	else
	{
		elem_pos = len_a - elem_pos + 1;
		while (elem_pos-- > 0)
			rra(stack_a);
	}
}



void	get_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp_a = *stack_a;
	t_stack *temp_b = *stack_b;
	int smallest_bigger;
    while (temp_b != NULL)
    {
        smallest_bigger = INT_MAX;
        temp_a = *stack_a;

        while (temp_a != NULL)
        {
            if (temp_a->content > temp_b->content && temp_a->content < smallest_bigger)
                smallest_bigger = temp_a->content;
            temp_a = temp_a->next;
        }
		temp_b->target = smallest_bigger;
        temp_b = temp_b->next;
    }
}

int count_moves_in_a(t_stack *stack, int target)
{
    int rotations = 0;
    while (stack != NULL)
    {
        if (stack->content == target)
            break;
        stack = stack->next;
        rotations++;
    }
    if (rotations > stack_len(stack) / 2)
        rotations = stack_len(stack) - rotations;
    return (rotations);
}

int count_moves_in_b(t_stack *stack, int element)
{
    int moves = 0;
    while (stack != NULL)
    {
        if (stack->content == element)
            break;
        stack = stack->next;
        moves++;
    }
    if (moves > stack_len(stack) / 2)
        moves = stack_len(stack) - moves;
    return moves;
}


void get_price(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp_a = *stack_a;
    t_stack *temp_b = *stack_b;

    while (temp_b != NULL)
    {
        int moves_a = count_moves_in_a(temp_a, temp_b->content);
        int moves_b = count_moves_in_b(temp_b, temp_b->content);
		// printf("moves_a === %d\n", moves_a);
		// printf("moves_B === %d\n", moves_b);
        temp_b->price = (moves_a) + (moves_b);
		if (temp_a != NULL)
        	temp_a = temp_a->next;
        temp_b = temp_b->next;
    }
}

t_stack *find_lowest_price(t_stack *stack_b)
{
    t_stack *lowest = stack_b;
    t_stack *temp = stack_b->next;

    while (temp != NULL)
    {
        if (temp->price < lowest->price)
            lowest = temp;
        temp = temp->next;
    }
    return (lowest);
}

void assign_indexes(t_stack *stack)
{
    int index = 0;
    t_stack *temp = stack;

    while (temp != NULL)
    {
        temp->index = index;
        temp = temp->next;
        index++;
    }
}

void assign_stack_indexes(t_stack **stack_a, t_stack **stack_b)
{
    assign_indexes(*stack_a);
    assign_indexes(*stack_b);
}

t_stack *get_stack_top(t_stack *stack)
{
    if (stack == NULL)
        return NULL;
    
    while (stack->next != NULL)
        stack = stack->next;
    
    return (stack);
}

t_stack	*find_node_from_stk(t_stack *stk, int val)
{
	t_stack	*tmp;

	tmp = stk;
	while (tmp != NULL)
	{
		if (tmp->content == val)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

// void move_to_top(t_stack **stack_a, t_stack **stack_b, t_stack *lowest_price_element)
// {
// 	// t_stack	*temp_b;
// 	// static int i;
// 	t_stack	*target;
// 	int		num_of_rotations;

//     while (*stack_b != lowest_price_element)
//     {
//         if (lowest_price_element->index <= stack_len(*stack_b) / 2)
//             rb(stack_b);
//         else
//             rrb(stack_b);
//     }
// 	target = find_node_from_stk(*stack_a, lowest_price_element->target);
// 	if (target->index >= stack_len(*stack_a) / 2)
// 		num_of_rotations = stack_len(*stack_a) - target->index;
// 	else
// 		num_of_rotations = target->index;
//     while (num_of_rotations-- != 0)
//     {
// 		if (target->index >= stack_len(*stack_a) / 2)
//             rra(stack_a);
//         else
//             ra(stack_a);
//     }
// }

void move_to_top(t_stack **stack_a, t_stack **stack_b, t_stack *lowest_price_element)
{
	t_stack	*target;
	int		num_of_rotations;

	target = find_node_from_stk(*stack_a, lowest_price_element->target);
	if (target->index >= stack_len(*stack_a) / 2)
		num_of_rotations = stack_len(*stack_a) - target->index;
	else
		num_of_rotations = target->index;
    while (*stack_b != lowest_price_element && num_of_rotations-- != 0)
    {
        if (lowest_price_element->index <= stack_len(*stack_b) / 2)
            rb(stack_b);
        else
            rrb(stack_b);
		if (target->index >= stack_len(*stack_a) / 2)
            rra(stack_a);
        else
            ra(stack_a);
    }
}




void	move_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*lowest_price;

	while (*stack_b != NULL)
	{	
		assign_stack_indexes(stack_a, stack_b);
		get_target_pos(stack_a, stack_b);
		get_price(stack_a, stack_b);
		lowest_price = find_lowest_price(*stack_b);
		move_to_top(stack_a, stack_b, lowest_price);
		pa(stack_a, stack_b);
	}
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	quick_sort(stack_a, stack_b);
	sort_three(stack_a);
	move_to_a(stack_a, stack_b);
	sort_a(stack_a);
}



// int	find_median(t_stack *stack)
// {
// 	int	i;
// 	int	sum;

// 	i = 0;
// 	sum = 0;
// 	while (stack)
// 	{
// 		sum += stack->sort_index;
// 		i++;
// 		if (stack->next == NULL) {
//             break; // Exit the loop if it reaches the end of the list
//         }
// 		stack = stack->next;
// 	}
// 	if (sum % i == 0)
// 		return (sum / i);
// 	else
// 		return ((sum / i) + 1);
// }

// void move_to_b(t_stack **stack_a, t_stack **stack_b, int *elems_to_move)
// {
//     int median;
//     int i;

//     median = find_median(*stack_a);
//     i = ((*elems_to_move) / 2) + 1;
//     while (i > 0)
//     {
//         if ((*stack_a)->content < median)
//             pb(stack_a, stack_b);
//         else if ((*stack_a)->next->content < median)
//         {
//             ra(stack_a);
//             pb(stack_a, stack_b);
//         }
//         else if (lst_last(*stack_a) < median)
//         {
//             rra(stack_a);
//             pb(stack_a, stack_b);
//         }
//         else
//             ra(stack_a);
//         i--;
//         (*elems_to_move)--;
//     }
// }

// void move_to_b_by_median(t_stack **stack_a, t_stack **stack_b)
// {
//     int elems_to_move;

//     elems_to_move = stack_len(*stack_a) - 3;
//     while (elems_to_move > 0)
//         move_to_b(stack_a, stack_b, &elems_to_move);
// }


// void	assign_elem_position(t_stack **stack_a, t_stack **stack_b)
// {
// 	int		i;
// 	t_stack	*temp_a;
// 	t_stack	*temp_b;

// 	i = 0;
// 	temp_a = *stack_a;
// 	temp_b = *stack_b;
// 	while (temp_a)
// 	{
// 		temp_a->current_pos = i++;
// 		temp_a = temp_a->next;
// 	}
// 	i = 0;
// 	while (temp_b)
// 	{
// 		temp_b->current_pos = i++;
// 		temp_b = temp_b->next;
// 	}
// }

// void	assign_index(int len, t_stack **stack, int *sorted_list)
// {
// 	int		i;
// 	t_stack	*temp;

// 	temp = *stack;
// 	while (temp)
// 	{
// 		i = 0;
// 		while (i < len)
// 		{
// 			if (temp->data == sorted_list[i])
// 			{
// 				temp->sort_index = i;
// 				break ;
// 			}
// 			i++;
// 		}
// 		temp = temp->next;
// 	}
// }

// void	put_sorting_index(t_stack **stack)
// {
// 	int		len;
// 	t_stack	*temp;
// 	int		i;
// 	int		*sorted_list;

// 	temp = *stack;
// 	len = stack_len(*stack);
// 	sorted_list = malloc(sizeof(int) * len);
// 	if (!sorted_list)
// 		return ;
// 	i = 0;
// 	while (temp)
// 	{
// 		sorted_list[i++] = temp->data;
// 		temp = temp->next;
// 	}
// 	sort_int_array(&sorted_list, len);
// 	temp = *stack;
// 	assign_index(len, &temp, sorted_list);
// 	*stack = temp;
// 	free(sorted_list);
// }

// int	count_forward_moves(t_stack *stack, int target_pos)
// {
// 	int	i;

// 	i = 0;
// 	while (stack->sort_index != target_pos)
// 	{
// 		i++;
// 		stack = stack->next;
// 	}
// 	return (i);
// }

// int	count_backward_moves(t_stack *stack, int target_pos)
// {
// 	int	i;

// 	i = 0;
// 	while (stack->sort_index != target_pos)
// 		stack = stack->next;
// 	stack = stack->next;
// 	while (stack)
// 	{
// 		i++;
// 		stack = stack->next;
// 	}
// 	return (i + 1);
// }

// int	find_cheapest(t_stack **stack_b)
// {
// 	int		cheapest;
// 	t_stack	*temp;
// 	int		cost_a;
// 	int		cost_b;
// 	int		cheapest_pos;

// 	temp = *stack_b;
// 	cheapest = INT_MAX;
// 	while (temp)
// 	{
// 		cost_a = temp->cost_a;
// 		if (cost_a < 0)
// 			cost_a = temp->cost_a * -1;
// 		cost_b = temp->cost_b;
// 		if (cost_b < 0)
// 			cost_b = temp->cost_b * -1;
// 		if (cheapest > (cost_a + cost_b))
// 		{
// 			cheapest = (cost_a + cost_b);
// 			cheapest_pos = temp->current_pos;
// 		}
// 		temp = temp->next;
// 	}
// 	return (cheapest_pos);
// }

// void	find_min_and_max(int *a_min, int *a_max, t_stack *temp)
// {
// 	*a_min = temp->sort_index;
// 	*a_max = temp->sort_index;
// 	while (temp->next != NULL)
// 	{
// 		if (*a_min > temp->next->sort_index)
// 			*a_min = temp->next->sort_index;
// 		if (*a_max < temp->next->sort_index)
// 			*a_max = temp->next->sort_index;
// 		temp = temp->next;
// 	}
// }

// void	check_min_and_max_diff(int *min_pos_diff, int *max_diff,
// 									t_stack **a, t_stack **b)
// {
// 	t_stack	*temp_a;
// 	int		next_diff;

// 	temp_a = *a;
// 	*max_diff = temp_a->sort_index - (*b)->sort_index;
// 	*min_pos_diff = 1000;
// 	if ((temp_a->sort_index - (*b)->sort_index) > 0)
// 		*min_pos_diff = (temp_a->sort_index - (*b)->sort_index);
// 	while (temp_a->next)
// 	{
// 		next_diff = temp_a->next->sort_index - (*b)->sort_index;
// 		if (*max_diff < next_diff)
// 			*max_diff = next_diff;
// 		if (next_diff > 0 && *min_pos_diff > next_diff)
// 			*min_pos_diff = next_diff;
// 		temp_a = temp_a->next;
// 	}
// }

// int	get_target_pos(t_stack **stack_a, t_stack **stack_b)
// {
// 	int		min_pos_diff;
// 	int		max_diff;
// 	int		target;
// 	int		a_min;
// 	int		a_max;

// 	target = 0;
// 	check_min_and_max_diff(&min_pos_diff, &max_diff, stack_a, stack_b);
// 	find_min_and_max(&a_min, &a_max, *stack_a);
// 	if (max_diff > 0)
// 		target = min_pos_diff + (*stack_b)->sort_index;
// 	else if (max_diff < 0)
// 		target = a_min;
// 	return (target);
// }

// void	get_cost(t_stack **stack_a, t_stack **stack_b)
// {
// 	int		len_b;
// 	t_stack	*temp_b;
// 	int		back_moves;
// 	int		target_pos;

// 	temp_b = *stack_b;
// 	len_b = stack_len(*stack_b);
// 	while (temp_b)
// 	{
// 		temp_b->cost_b = temp_b->current_pos;
// 		if (temp_b->cost_b > len_b / 2)
// 			temp_b->cost_b = (temp_b->current_pos - len_b);
// 		target_pos = get_target_pos(stack_a, &temp_b);
// 		back_moves = count_backward_moves(*stack_a, target_pos);
// 		temp_b->cost_a = count_forward_moves(*stack_a, target_pos);
// 		if (back_moves < temp_b->cost_a)
// 			temp_b->cost_a = back_moves * -1;
// 		temp_b = temp_b->next;
// 	}
// }

// void	adjust(int cheapest_pos, t_stack **a, t_stack **b)
// {
// 	t_stack	*temp;

// 	temp = *b;
// 	while (temp->current_pos != cheapest_pos)
// 		temp = temp->next;
// 	if ((temp->cost_a < 0) && (temp->cost_b < 0))
// 		rrr(a, b);
// 		// reverse_rotate_both(a, b, temp->cost_a, temp->cost_b);
// 	else if ((temp->cost_a > 0) && (temp->cost_b > 0))
// 		rr(a, b);
// 		// rotate_both(a, b, temp->cost_a, temp->cost_b);
// 	else if (temp->cost_b >= 0 && temp->cost_a <= 0)
// 	{
// 		rb(b);
// 		rra(a);
// 		// rotate(b, "rb", temp->cost_b);
// 		// reverse_rotate(a, "rra", temp->cost_a);
// 	}
// 	else if (temp->cost_b <= 0 && temp->cost_a >= 0)
// 	{
// 		rrb(b);
// 		ra(a);
// 		// reverse_rotate(b, "rrb", temp->cost_b);
// 		// rotate(a, "ra", temp->cost_a);
// 	}
// }

// void	rearrange_a(t_stack **stack, int point)
// {
// 	int	ra_size;
// 	int	rra_size;

// 	ra_size = count_forward_moves(*stack, point);
// 	rra_size = count_backward_moves(*stack, point);
// 	if (ra_size == 0)
// 		return ;
// 	else if (ra_size > rra_size)
// 		while (rra_size--)
// 			rra(stack);
// 			// reverse_rotate(stack, "rra", -1);
// 	else
// 		while (ra_size--)
// 			ra(stack);
// 			// rotate(stack, "ra", 1);
// }

// void	move_to_a(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	cheapest_elem;

// 	while (*stack_b)
// 	{
// 		assign_elem_position(stack_a, stack_b);
// 		get_cost(stack_a, stack_b);
// 		cheapest_elem = find_cheapest(stack_b);
// 		adjust(cheapest_elem, stack_a, stack_b);
// 		pa(stack_a, stack_b);
// 	}
// }

// void	push_swap(t_stack **stack_a)
// {
// 	t_stack	*stack_b;

// 	stack_b = NULL;
// 	if (stack_len(*stack_a) > 3)
// 	{
// 		move_to_b_by_median(stack_a, &stack_b);
// 		sort_three(stack_a);
// 	}
// 	move_to_a(stack_a, &stack_b);
// 	rearrange_a(stack_a, 0);
// 	free_stack(stack_b);
// 	return ;
// }







