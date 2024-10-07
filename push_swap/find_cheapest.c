/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:36:34 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/09/28 11:37:33 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_cheapest(t_list **stack_a, t_list **stack_b, int len_a, int len_b, int *op_count)
{
    int i;
    i = 1;
    int j = 1;
    t_list *cur_a = *stack_a;
    t_list *cur_b = *stack_b;
    int cheapest_operations = 424242;
    int operations_a = 0;
    int operations_b = 0;
    int total_operations = 1;
    int cheapest_position = 1;
    int target_position_b = 1;
    int saved_target_position_b = 1;
    int saved_target_position_b2 = 1;

    while(i <= len_a)
    {
        ft_printf("la longitud de a es %d\n", len_a);
        len_b = ft_lstsize(*stack_b);
        ft_printf("la longitud de b es %d\n", len_b);
        operations_a = 0;
        operations_b = 0;
        if(i <= len_a / 2 || i == 1)
            operations_a = i - 1;
        else
            operations_a = len_a - i + 1;
        ft_printf("Operations to move element %d in stack_a: %d\n", *cur_a->data, operations_a);
        // where in stack_b
        cur_b = *stack_b;
        j = 1;
        target_position_b = 1;
        while(cur_b != NULL)
        {
            if(*cur_a->data > *cur_b->data)
            {
                target_position_b = j;
                ft_printf("Found a position in stack_b: cur_a->data %d > cur_b->data %d at position %d\n", *cur_a->data, *cur_b->data, j);
                break ;
            }
            cur_b = cur_b->next;
            j++;
        }
        // if cur_a->data is smaller than all elements in stack_b, it should go to the end
        if(cur_b == NULL)
        {
            target_position_b = len_b + 1;
            ft_printf("No valid position found in stack_b, setting target position at the end: %d\n", target_position_b);
        }
        // Display the target position for debugging
        ft_printf("Target position for element %d in stack_b is %d\n", *cur_a->data, target_position_b);


        // calculate rotations in b to reach target position
        if(target_position_b <= len_b / 2)
            operations_b = target_position_b - 1;
        else if(target_position_b > len_b / 2 && target_position_b <= len_b)
            operations_b = len_b - target_position_b + 1;
        else
            operations_b = 1;
        ft_printf("Operations to adapt stack_b: %d\n", operations_b);

        total_operations = operations_a + operations_b;
        ft_printf("Total operations to move element %d: %d\n\n", *cur_a->data, total_operations);
        if(total_operations < cheapest_operations)
        {
            cheapest_operations = total_operations;
            cheapest_position = i;
            saved_target_position_b = target_position_b;
            saved_target_position_b2 = target_position_b;
            ft_printf("New cheapest element %d with total operations %d at position %d\n\n", *cur_a->data, total_operations, cheapest_position);
        } 
        cur_a = cur_a->next;
        i++;
    }
    ft_printf("Cheapest element is at position %d, moving accordingly into position in stack_b %d...\n\n", cheapest_position, saved_target_position_b);
    //rotate accordingly stack_a, also stack_b if necessary
    if(saved_target_position_b <= len_b / 2)
    {
        while(saved_target_position_b > 1)
        {
            ft_rotate(stack_b);
            (*op_count)++;
            ft_printf("rb %d\n", *op_count);
            saved_target_position_b--;
        }
    }
    else if(saved_target_position_b > len_b / 2 && saved_target_position_b <= len_b)
    {
        while(saved_target_position_b != 1)
        {
            ft_rev_rotate(stack_b);
            (*op_count)++;
            ft_printf("rrb %d\n", *op_count);
            saved_target_position_b++;
            if (saved_target_position_b > len_b)
                saved_target_position_b = 1;
        }
    }
    if(cheapest_position == 1 && cheapest_position == len_a)
    {
        ft_push(stack_a, stack_b);
        (*op_count)++;
        ft_printf("pb %d\n", *op_count);
    }
    else if(cheapest_position >= 1 && cheapest_position <= len_a / 2)
    {
        while(cheapest_position > 1)
        {
            ft_rotate(stack_a);
            (*op_count)++;
            ft_printf("ra %d\n", *op_count);
            cheapest_position--;
        }
        ft_push(stack_a, stack_b);
        (*op_count)++;
        ft_printf("pb %d\n", *op_count);  
    }
    else if(cheapest_position > len_a / 2 && cheapest_position <= len_a)
    {
        while(cheapest_position <= len_a)
        {
            ft_rev_rotate(stack_a);
            (*op_count)++;
            ft_printf("rra %d\n", *op_count);
            cheapest_position++;
        }
        ft_push(stack_a, stack_b);
        (*op_count)++;
        ft_printf("pb %d\n", *op_count);  
    }
    if(saved_target_position_b == len_b + 1)
    {
        //ft_push(stack_a, stack_b);
        //(*op_count)++;
        //ft_printf("pb %d\n", *op_count);    
        ft_rotate(stack_b);
        (*op_count)++;
        ft_printf("rb %d\n", *op_count);
    }
        //rotate stack_b after transferring a number which is not the maximum
    printf("la posicion reservada antes tiene que retrotraerse %d \n", saved_target_position_b2);
    if(saved_target_position_b2 <= len_b / 2)
    {
        while(saved_target_position_b2 > 1)
        {
            ft_rev_rotate(stack_b);
            (*op_count)++;
            ft_printf("rrb %d\n", *op_count);
            saved_target_position_b2--;
        }
    }
    else if(saved_target_position_b2 > len_b / 2 && saved_target_position_b2 <= len_b)
    {
        while(saved_target_position_b2 != 1)
        {
            ft_rotate(stack_b);
            (*op_count)++;
            ft_printf("rb %d\n", *op_count);
            saved_target_position_b2++;
            if (saved_target_position_b2 > len_b)
                saved_target_position_b2 = 0;
        }
    }
                                        //check
                        printf("Contents of stack_a:\n");
                        print_stack(*stack_a);
            
                        printf("Contents of stack_b:\n");
                        print_stack(*stack_b);  
    return ;
}