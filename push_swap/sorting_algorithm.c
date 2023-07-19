/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <g.ibrogim98@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:52:29 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/19 20:55:13 by iganiev          ###   ########.fr       */
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

// int count_moves_in_a(t_stack *stack, int target)
// {
// 	// t_stack *tmp = stack;
//     int rotations = 0;
//     while (stack != NULL)
//     {
// 		// printf("stack === %d\n", stack->content);
// 		// printf("target === %d\n", target);
//         if (stack->content == target)
//             break ;
//         stack = stack->next;
//         rotations++;
//     }
// 	// printf("Stack12 === %d\n", stack->content);
// 	// printf("rotat=== %d\n", target);
// 	// if(rotations == 0 || stack == NULL)
// 	// 	return 0;
//     if (rotations > stack_len(stack) / 2)
//         rotations = stack_len(stack) - rotations;
//     return (rotations);
// }

int count_moves_in_a(t_stack *stack, int target)
{
    t_stack *tmp = stack;
    int rotations = 0;
    int target_index = -1;
    int current_index = 0;

    while (tmp != NULL)
    {
        if (tmp->content == target)
        {
            target_index = current_index;
            break;
        }
        tmp = tmp->next;
        current_index++;
    }
    if (target_index >= 0)
    {
        rotations = target_index;
        if (rotations > stack_len(stack) / 2)
            rotations = rotations - stack_len(stack);
    }
    return rotations;
}


// t_stack	*find_node_from_stk(t_stack *stk, int val)
// {
// 	t_stack	*tmp;

// 	tmp = stk;
// 	while (tmp != NULL)
// 	{
// 		if (tmp->content == val)
// 			return (tmp);
// 		tmp = tmp->next;
// 	}
// 	return (NULL);
// }

// int count_moves_in_a(t_stack *stack, int target)
// {	
//     while (stack != NULL)
//     {
// 		// printf("stack === %d\n", stack->content);
// 		// printf("target === %d\n", target);
//         if (stack->content == target)
//             break ;
//         stack = stack->next;
//         rotations++;
//     }
// 	printf("Stack12 === %d\n", stack->content);
// 	printf("rotat=== %d\n", target);
// 	if(rotations == 0 || stack == NULL)
// 		return 0;
//     if (rotations > stack_len(stack) / 2)
//         rotations = stack_len(stack) - rotations;
//     return (rotations);
// }

// int count_moves_in_b(t_stack *stack, int element)
// {
// 	// t_stack *temp = stack;
//     int moves = 0;
//     while (temp != NULL)
//     {
//         if (stack->content == element)
//             break;
//         stack = stack->next;
//         moves++;
//     }
//     if (moves > stack_len(stack) / 2)
//         moves = stack_len(stack) - moves;
//     return moves;
// }

int count_moves_in_b(t_stack *stack, int element)
{
    t_stack *temp = stack;
    int moves = 0;
    int element_index = -1;
    int current_index = 0;

    while (temp != NULL)
    {
        if (temp->content == element)
        {
            element_index = current_index;
            break;
        }
        temp = temp->next;
        current_index++;
    }

    if (element_index >= 0)
    {
        moves = element_index;
        if (moves > stack_len(stack) / 2)
            moves = moves - stack_len(stack);
    }
    return (moves);
}


int	ft_abs(int value)
{
	if (value < 0)
		value *= -1;
	return (value);
}

void get_price(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp_a = *stack_a;
    t_stack *temp_b = *stack_b;

    while (temp_b != NULL)
    {
        int moves_a = count_moves_in_a(*stack_a, temp_b->target);
        int moves_b = count_moves_in_b(*stack_b, temp_b->content);
		// printf("moves_a === %d\n", moves_a);
		// printf("moves_B === %d\n", moves_b);
        temp_b->price = (ft_abs(moves_a) + ft_abs(moves_b));
		// if(temp_b->price < 0)
		// 	temp_b->price *= -1;
		
		temp_b->cost_a = moves_a;
		temp_b->cost_b = moves_b;
		// printf("content === %d\n", temp_b->content);
		// // printf("target === %d\n", temp_b->target);
		// printf("moves_a === %d\n", moves_a);
		// printf("moves_B === %d\n", moves_b);
		// printf("price === %d\n", temp_b->price);
		if (temp_a != NULL)
        	temp_a = temp_a->next;
        temp_b = temp_b->next;
    }
	// print_stack(*stack_a);
	// print_stack(*stack_b);
	
	// exit(0);
}

t_stack *find_lowest_price(t_stack *stack_b)
{
    t_stack *lowest = stack_b;
    t_stack *temp = stack_b->next;

    while (temp != NULL)
    {
		// printf("lowwest :%d\n", lowest->price);
		// printf("tmp->:%d\n", temp->price);
        if (temp->price < lowest->price)
		{
            lowest = temp;
		}
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

// t_stack	*find_node_from_stk(t_stack *stk, int val)
// {
// 	t_stack	*tmp;

// 	tmp = stk;
// 	while (tmp != NULL)
// 	{
// 		if (tmp->content == val)
// 			return (tmp);
// 		tmp = tmp->next;
// 	}
// 	return (NULL);
// }

void move_to_top(t_stack **stack_a, t_stack **stack_b, t_stack *lowest_price_element)
{
	// printf("cont: %d\n", lowest_price_element->content);
	// printf("cosT_a: %d\n", lowest_price_element->cost_a);
	// printf("cost_b: %d\n", lowest_price_element->cost_b);
	
	if (lowest_price_element->cost_b > 0)
	{
		while (lowest_price_element->cost_b != 0)
		{
			rb(stack_b);
			lowest_price_element->cost_b--;
		}
	}
	else if(lowest_price_element->cost_b < 0)
	{
		while (lowest_price_element->cost_b != 0)
		{
			rrb(stack_b);
			lowest_price_element->cost_b++;
		}
	}
	
	if(lowest_price_element->cost_a > 0)
	{
		while (lowest_price_element->cost_a != 0)
		{
			ra(stack_a);
			lowest_price_element->cost_a--;
		}
	}
	else if(lowest_price_element->cost_a < 0)
	{
		while (lowest_price_element->cost_a != 0)
		{
			rra(stack_a);
			lowest_price_element->cost_a++;
		}
	}
	// pa(stack_a, stack_b);
    // while (*stack_b != lowest_price_element)
    // {
    //     if (lowest_price_element->index <= stack_len(*stack_b) / 2)
    //         rb(stack_b);
    //     else
    //         rrb(stack_b);
    // }
	// target = find_node_from_stk(*stack_a, lowest_price_element->target);
	// if (target->index >= stack_len(*stack_a) / 2)
	// 	num_of_rotations = stack_len(*stack_a) - target->index;
	// else
	// 	num_of_rotations = target->index;
    // while (num_of_rotations-- != 0)
    // {
	// 	if (target->index >= stack_len(*stack_a) / 2)
    //         rra(stack_a);
    //     else
    //         ra(stack_a);
    // }
}

// void move_to_top(t_stack **stack_a, t_stack **stack_b, t_stack *lowest_price_element)
// {
// 	t_stack	*target;
// 	int		num_of_rotations;

// 	target = find_node_from_stk(*stack_a, lowest_price_element->target);
// 	if (target->index >= stack_len(*stack_a) / 2)
// 		num_of_rotations = stack_len(*stack_a) - target->index;
// 	else
// 		num_of_rotations = target->index;
//     while (*stack_b != lowest_price_element && num_of_rotations-- != 0)
//     {
//         if (lowest_price_element->index <= stack_len(*stack_b) / 2)
//             rb(stack_b);
//         else
//             rrb(stack_b);
// 		if (target->index >= stack_len(*stack_a) / 2)
//             rra(stack_a);
//         else
//             ra(stack_a);
//     }
// }




void	move_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*lowest_price;

	while (*stack_b != NULL)
	{	
		assign_stack_indexes(stack_a, stack_b);
		get_target_pos(stack_a, stack_b);
		get_price(stack_a, stack_b);
		lowest_price = find_lowest_price(*stack_b);
		// printf("lowest == %d\n", lowest_price->content);
		// exit(0);
		// printf("mv_A == %d\n", lowest_price->cost_a);
		// printf("mv_b == %d\n", lowest_price->cost_b);
		// printf("price == %d\n", lowest_price->price);
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
