/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <g.ibrogim98@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:42:18 by iganiev           #+#    #+#             */
/*   Updated: 2023/07/19 01:19:20 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


int main(int argc, char *argv[]) 
{
    int *int_array;
    int count_args;
    t_stack *stack_a;
    t_stack *stack_b;
    

    if (argc <= 2)
        return (0);
    stack_a = NULL;
    count_args = parse_args(argc, argv, &int_array);
    if (count_args == -1)
    {
        write (2, "Error\n", 6);
        free(int_array);
        return 1;
    }
    stack_a = create_stack(count_args, int_array);
    stack_b = NULL;
    if (is_sorted(stack_a))
        return (0);
    // ft_printf("Before sorting:\n");
    // print_stack(stack_a);
    push_swap(&stack_a, &stack_b);


    
    // quick_sort(&stack_a, &stack_b);
    // sort_more(&stack_a);
    // sort_three(&stack_a);
    ft_printf("After sorting:\n");
    print_stack(stack_a);
    free_stack(stack_a);
    free(int_array);
    return 0;
}
