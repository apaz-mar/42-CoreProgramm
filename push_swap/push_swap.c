/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:35:07 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/09/28 11:35:15 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int main(int ac, char **av)
{
    if(ac < 2)
        return (0);
            
    int op_count = 0;

    t_list *stack_a = NULL;
    t_list *stack_b = NULL;

    fill_stack(ac, av, &stack_a);
    
    printf("Contents of stack_a:\n");
    print_stack(stack_a);

    int len_a = ft_lstsize(stack_a);
    int len_b = ft_lstsize(stack_b);
    printf("la longitud de la lista es %d\n", len_a);

    //push two numbers into stack b to have a maximum
    ft_push(&stack_a, &stack_b);
    op_count++;
    ft_printf("pb %d\n", op_count); 
    ft_push(&stack_a, &stack_b);
    op_count++;
    ft_printf("pb %d\n", op_count); 
                    //check
        printf("Contents of stack_a:\n");
        print_stack(stack_a);

        printf("Contents of stack_b:\n");
        print_stack(stack_b);   
    int pos_max = find_maximum(&stack_b);
    printf("la posicion del maximo en b es %d\n", pos_max);
    if(pos_max != 1)
    {
        ft_rotate(&stack_b);
        op_count++;
        ft_printf("rb %d\n", op_count);
    }

    //calculate cheapest number to push and rotate accordingly
    while(ft_lstsize(stack_a) > 3)
    {
        len_a = ft_lstsize(stack_a);
        len_b = ft_lstsize(stack_b);
        find_cheapest(&stack_a, &stack_b, len_a, len_b, &op_count);
        //ft_push(&stack_a, &stack_b);
        //op_count++;
        //ft_printf("pb %d\n", op_count); 
        len_a = ft_lstsize(stack_a);
        len_b = ft_lstsize(stack_b);        
                                    //check
                        printf("Contents of stack_a:\n");
                        print_stack(stack_a);
            
                        printf("Contents of stack_b:\n");
                        print_stack(stack_b);  
    }
    //push the remaining numbers from stack_b
    sort_three(&stack_a, &op_count);
    move_stack_a(&stack_a, &stack_b, &op_count);
    //while(stack_b != NULL)
    //{
    //    ft_push(&stack_b, &stack_a);
    //    op_count++;
    //    ft_printf("pa %d\n", op_count);         
    //}
                                //check
                    printf("Contents of stack_a:\n");
                    print_stack(stack_a);
        
                    printf("Contents of stack_b:\n");
                    print_stack(stack_b);
    // Free the allocated memory
    while (stack_a)
    {
        t_list *tmp = stack_a;
        stack_a = stack_a->next;
        free(tmp->data);
        free(tmp);
    }
    while (stack_b)
    {
        t_list *tmp = stack_b;
        stack_b = stack_b->next;
        free(tmp->data);
        free(tmp);
    }
    return 0;
}
    
