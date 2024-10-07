
#include "push_swap.h"

int main(int ac, char **av)
{
    if(ac < 2)
        return (0);
            
    int op_count = 0;
    int i = 1;
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;

    fill_stack(ac, av, &stack_a);
    
    printf("Contents of stack_a:\n");
    print_stack(stack_a);

    int len_a = ft_lstsize(stack_a);
    int len_b = ft_lstsize(stack_b);
    printf("la longitud de la lista es %d\n", len_a);

    // Transfer the half with the minimum to stack_b
    int pos_min = find_minimum(&stack_a);
    printf("la posicion del minimo inicial es %d\n", pos_min);

    if(pos_min > len_a / 2)
    {
        while(pos_min <= len_a)
        {
            //swap before rotating in the initial transfer
            if(*(stack_a->data) > *(stack_a->next->data))
            {
                swap(&stack_a);
                op_count++;
                ft_printf("sa %d\n", op_count);
                            //check
                printf("Contents of stack_a:\n");
                print_stack(stack_a);
            }
            ft_rev_rotate(&stack_a);
            op_count++;
            ft_printf("rra %d\n", op_count);
            pos_min++;
        }
    }
    i = 1;
    while(i <= len_a / 2)
    {
        ft_push(&stack_a, &stack_b);
        op_count++;
        i++;
        ft_printf("pb %d\n", op_count);
    }
    
        len_a = ft_lstsize(stack_a);
        len_b = ft_lstsize(stack_b);
        printf("Check longitud de a tras transfer de chunk: %d \n", len_a);
        printf("Check longitud de b tras transfer de chunk: %d \n", len_b);
            //check
                printf("Contents of stack_a:\n");
                print_stack(stack_a);
    
                printf("Contents of stack_b:\n");
                print_stack(stack_b);

    int pos_max = find_maximum(&stack_b);

    // Find minimum in stack_a and maximum in stack_b and transfer to each other stack
    // This loop works until the medium nodes are confronted
    while(!(is_sorted_asc(stack_a) && is_sorted_desc(stack_b)))
    {
        pos_min = find_minimum(&stack_a);
        printf("la posicion del minimo en a es %d\n", pos_min);
        pos_max = find_maximum(&stack_b);
        printf("la posicion del maximo en b es %d\n", pos_max);

        // if min and max are in the upper half
        if(pos_min <= len_a / 2 && pos_max <= len_b /2)
        {
            int double_op = MIN(pos_min, pos_max) - 1;
            printf("El numero de rotaciones comunes es: %d\n", double_op);
            while(double_op >= 1)
            {
                //swap before rotating 
                if(pos_min !=2 && pos_max !=2 && *(stack_a->data) > *(stack_a->next->data) && *(stack_b->data) < *(stack_b->next->data))
                {
                    swap(&stack_a);
                    swap(&stack_b);
                    op_count++;
                    ft_printf("ss %d\n", op_count);
                            //check
                            printf("Contents of stack_a after double swap:\n");
                            print_stack(stack_a);
                            printf("Contents of stack_b after double swap:\n");
                            print_stack(stack_b);
                }
                else if(pos_min !=2 && *(stack_a->data) > *(stack_a->next->data))
                {
                    swap(&stack_a);
                    op_count++;
                    ft_printf("sa %d\n", op_count);
                            //check
                            printf("Contents of stack_a after swap:\n");
                            print_stack(stack_a);
                }
                else if(pos_max !=2 && *(stack_b->data) < *(stack_b->next->data))
                {
                    swap(&stack_b);
                    op_count++;
                    ft_printf("sb %d\n", op_count);
                            //check
                            printf("Contents of stack_b after swap:\n");
                            print_stack(stack_b);    
                }
                // rotate after the swaps
                ft_rotate(&stack_a);
                pos_min--;
                ft_rotate(&stack_b);
                pos_max--;
                op_count++;
                ft_printf("rr %d\n", op_count);
                double_op--;
            }
                        //check
                    printf("Contents of stack_a:\n");
                    print_stack(stack_a);
        
                    printf("Contents of stack_b:\n");
                    print_stack(stack_b);
            // rotaciones del stack pendiente
            if(pos_min != 0)
            {
                while(pos_min > 1)
                {
                    //swap before rotating 
                    if(pos_min != 2 && pos_max != 2 && *(stack_a->data) > *(stack_a->next->data) && *(stack_b->data) < *(stack_b->next->data))
                    {
                        swap(&stack_a);
                        swap(&stack_b);
                        op_count++;
                        ft_printf("ss %d\n", op_count);
                                //check
                                printf("Contents of stack_a after double swap:\n");
                                print_stack(stack_a);
                                printf("Contents of stack_b after double swap:\n");
                                print_stack(stack_b);
                    }
                    else if(pos_min != 2 && *(stack_a->data) > *(stack_a->next->data))
                    {
                        swap(&stack_a);
                        op_count++;
                        ft_printf("sa %d\n", op_count);
                                //check
                                printf("Contents of stack_a after swap:\n");
                                print_stack(stack_a);
                    }
                    else if(pos_max != 2 && *(stack_b->data) < *(stack_b->next->data))
                    {
                        swap(&stack_b);
                        op_count++;
                        ft_printf("sb %d\n", op_count);
                                //check
                                printf("Contents of stack_b after swap:\n");
                                print_stack(stack_b);    
                    }
                    // rotate after the swaps
                    ft_rotate(&stack_a);
                    op_count++;
                    ft_printf("ra %d\n", op_count);
                    pos_min--;
                }
            }    
            if(pos_max != 0)
            {
                while(pos_max > 1)
                {
                    //swap before rotating 
                    if(pos_min != 2 && pos_max != 2 && *(stack_a->data) > *(stack_a->next->data) && *(stack_b->data) < *(stack_b->next->data))
                    {
                        swap(&stack_a);
                        swap(&stack_b);
                        op_count++;
                        ft_printf("ss %d\n", op_count);
                                //check
                                printf("Contents of stack_a after double swap:\n");
                                print_stack(stack_a);
                                printf("Contents of stack_b after double swap:\n");
                                print_stack(stack_b);
                    }
                    else if(pos_min != 2 && *(stack_a->data) > *(stack_a->next->data))
                    {
                        swap(&stack_a);
                        op_count++;
                        ft_printf("sa %d\n", op_count);
                                //check
                                printf("Contents of stack_a after swap:\n");
                                print_stack(stack_a);
                    }
                    else if(pos_max != 2 && *(stack_b->data) < *(stack_b->next->data))
                    {
                        swap(&stack_b);
                        op_count++;
                        ft_printf("sb %d\n", op_count);
                                //check
                                printf("Contents of stack_b after swap:\n");
                                print_stack(stack_b);    
                    }
                    // rotate after the swaps
                    ft_rotate(&stack_b);
                    op_count++;
                    ft_printf("rb %d\n", op_count);
                    pos_max--;
                }
            }    
                        //check
                    printf("Contents of stack_a before push:\n");
                    print_stack(stack_a);
        
                    printf("Contents of stack_b before push:\n");
                    print_stack(stack_b);
            //push the min at the top of a & the max at the top of b, but swap the first receiving
            printf("stack_a->data: %d, stack_b->data: %d\n", *(stack_a->data), *(stack_b->data));
            if(*(stack_a->data) < *(stack_b->data))
            {
                ft_push(&stack_a, &stack_b);
                op_count++;
                ft_printf("pb %d\n", op_count);
                swap(&stack_b);
                op_count++;
                ft_printf("sb %d\n", op_count);
                ft_push(&stack_b, &stack_a);
                op_count++;
                ft_printf("pa %d\n", op_count);
            } 
                //check
                    printf("Contents of stack_a:\n");
                    print_stack(stack_a);
        
                    printf("Contents of stack_b:\n");
                    print_stack(stack_b);
        }
        else if(pos_min > len_a / 2 && pos_max > len_b /2)
        {
            int double_op = len_a - MAX(pos_min, pos_max) + 1;
            printf("El numero de rotaciones comunes por abajo es: %d\n", double_op);
            while(double_op >= 1)
            {
                //swap before rotating 
                if(pos_min != 2 && pos_max != 2 && *(stack_a->data) > *(stack_a->next->data) && *(stack_b->data) < *(stack_b->next->data))
                {
                    swap(&stack_a);
                    swap(&stack_b);
                    op_count++;
                    ft_printf("ss %d\n", op_count);
                            //check
                            printf("Contents of stack_a after double swap:\n");
                            print_stack(stack_a);
                            printf("Contents of stack_b after double swap:\n");
                            print_stack(stack_b);
                }
                else if(pos_min != 2 && *(stack_a->data) > *(stack_a->next->data))
                {
                    swap(&stack_a);
                    op_count++;
                    ft_printf("sa %d\n", op_count);
                            //check
                            printf("Contents of stack_a after swap:\n");
                            print_stack(stack_a);
                }
                else if(pos_max != 2 && *(stack_b->data) < *(stack_b->next->data))
                {
                    swap(&stack_b);
                    op_count++;
                    ft_printf("sb %d\n", op_count);
                            //check
                            printf("Contents of stack_b after swap:\n");
                            print_stack(stack_b);    
                }
                // rotate after the swaps
                ft_rev_rotate(&stack_a);
                pos_min++;
                ft_rev_rotate(&stack_b);
                pos_max++;
                op_count++;
                ft_printf("rrr %d\n", op_count);
                double_op--;
            }
                        //check
                    printf("Contents of stack_a:\n");
                    print_stack(stack_a);
        
                    printf("Contents of stack_b:\n");
                    print_stack(stack_b);
            // rotaciones del stack pendiente
            int diff_pos_min = len_a - pos_min - double_op + 1;
            int diff_pos_max = len_a - pos_max - double_op + 1;
            if(diff_pos_min != 0)
            {
                while(diff_pos_min > 1)
                {
                    //swap before rotating 
                    if(pos_min != 2 && pos_max != 2 && *(stack_a->data) > *(stack_a->next->data) && *(stack_b->data) < *(stack_b->next->data))
                    {
                        swap(&stack_a);
                        swap(&stack_b);
                        op_count++;
                        ft_printf("ss %d\n", op_count);
                                //check
                                printf("Contents of stack_a after double swap:\n");
                                print_stack(stack_a);
                                printf("Contents of stack_b after double swap:\n");
                                print_stack(stack_b);
                    }
                    else if(pos_min != 2 && *(stack_a->data) > *(stack_a->next->data))
                    {
                        swap(&stack_a);
                        op_count++;
                        ft_printf("sa %d\n", op_count);
                                //check
                                printf("Contents of stack_a after swap:\n");
                                print_stack(stack_a);
                    }
                    else if(pos_max != 2 && *(stack_b->data) < *(stack_b->next->data))
                    {
                        swap(&stack_b);
                        op_count++;
                        ft_printf("sb %d\n", op_count);
                                //check
                                printf("Contents of stack_b after swap:\n");
                                print_stack(stack_b);    
                    }
                    // rotate after the swaps
                    ft_rev_rotate(&stack_a);
                    op_count++;
                    ft_printf("rra %d\n", op_count);
                    diff_pos_min--;
                }
            }    
            if(diff_pos_max != 0)
            {
                while(diff_pos_max > 1)
                {
                    //swap before rotating 
                    if(pos_min != 2 && pos_max != 2 && *(stack_a->data) > *(stack_a->next->data) && *(stack_b->data) < *(stack_b->next->data))
                    {
                        swap(&stack_a);
                        swap(&stack_b);
                        op_count++;
                        ft_printf("ss %d\n", op_count);
                                //check
                                printf("Contents of stack_a after double swap:\n");
                                print_stack(stack_a);
                                printf("Contents of stack_b after double swap:\n");
                                print_stack(stack_b);
                    }
                    else if(pos_min != 2 && *(stack_a->data) > *(stack_a->next->data))
                    {
                        swap(&stack_a);
                        op_count++;
                        ft_printf("sa %d\n", op_count);
                                //check
                                printf("Contents of stack_a after swap:\n");
                                print_stack(stack_a);
                    }
                    else if(pos_max != 2 && *(stack_b->data) < *(stack_b->next->data))
                    {
                        swap(&stack_b);
                        op_count++;
                        ft_printf("sb %d\n", op_count);
                                //check
                                printf("Contents of stack_b after swap:\n");
                                print_stack(stack_b);    
                    }
                    // rotate after the swaps
                    ft_rev_rotate(&stack_b);
                    op_count++;
                    ft_printf("rrb %d\n", op_count);
                    diff_pos_max--;
                }
            }    
                        //check
                    printf("Contents of stack_a:\n");
                    print_stack(stack_a);
        
                    printf("Contents of stack_b:\n");
                    print_stack(stack_b);
            //push the min at the top of a & the max at the top of b, but swap the first receiving
            if(*(stack_a->data) < *(stack_b->data))
            {
                ft_push(&stack_a, &stack_b);
                op_count++;
                ft_printf("pb %d\n", op_count);
                swap(&stack_b);
                op_count++;
                ft_printf("sb %d\n", op_count);
                ft_push(&stack_b, &stack_a);
                op_count++;
                ft_printf("pa %d\n", op_count);
            } 
                //check
                    printf("Contents of stack_a:\n");
                    print_stack(stack_a);
        
                    printf("Contents of stack_b:\n");
                    print_stack(stack_b);
        }
        else if(pos_min <= len_a / 2 && pos_max > len_b / 2)
        {
            while(pos_min > 1)
            {
                //swap before rotating 
                if(pos_min != 2 && pos_max != 2 && *(stack_a->data) > *(stack_a->next->data) && *(stack_b->data) < *(stack_b->next->data))
                {
                    swap(&stack_a);
                    swap(&stack_b);
                    op_count++;
                    ft_printf("ss %d\n", op_count);
                            //check
                            printf("Contents of stack_a after double swap:\n");
                            print_stack(stack_a);
                            printf("Contents of stack_b after double swap:\n");
                            print_stack(stack_b);
                }
                else if(pos_min != 2 && *(stack_a->data) > *(stack_a->next->data))
                {
                    swap(&stack_a);
                    op_count++;
                    ft_printf("sa %d\n", op_count);
                            //check
                            printf("Contents of stack_a after swap:\n");
                            print_stack(stack_a);
                }
                else if(pos_max != 2 && *(stack_b->data) < *(stack_b->next->data))
                {
                    swap(&stack_b);
                    op_count++;
                    ft_printf("sb %d\n", op_count);
                            //check
                            printf("Contents of stack_b after swap:\n");
                            print_stack(stack_b);    
                }
                // rotate after the swaps
                ft_rotate(&stack_a);
                op_count++;
                ft_printf("ra %d\n", op_count);
                pos_min--;
            }
            while(pos_max <= len_a)
            {
                //swap before rotating 
                if(pos_min != 2 && pos_max != 2 && *(stack_a->data) > *(stack_a->next->data) && *(stack_b->data) < *(stack_b->next->data))
                {
                    swap(&stack_a);
                    swap(&stack_b);
                    op_count++;
                    ft_printf("ss %d\n", op_count);
                            //check
                            printf("Contents of stack_a after double swap:\n");
                            print_stack(stack_a);
                            printf("Contents of stack_b after double swap:\n");
                            print_stack(stack_b);
                }
                else if(pos_min != 2 && *(stack_a->data) > *(stack_a->next->data))
                {
                    swap(&stack_a);
                    op_count++;
                    ft_printf("sa %d\n", op_count);
                            //check
                            printf("Contents of stack_a after swap:\n");
                            print_stack(stack_a);
                }
                else if(pos_max != 2 && *(stack_b->data) < *(stack_b->next->data))
                {
                    swap(&stack_b);
                    op_count++;
                    ft_printf("sb %d\n", op_count);
                            //check
                            printf("Contents of stack_b after swap:\n");
                            print_stack(stack_b);    
                }
                // rotate after the swaps
                ft_rev_rotate(&stack_b);
                op_count++;
                ft_printf("rrb %d\n", op_count);
                pos_max++;
            }
                        //check
                    printf("Contents of stack_a:\n");
                    print_stack(stack_a);
        
                    printf("Contents of stack_b:\n");
                    print_stack(stack_b);
            //push the min at the top of a & the max at the top of b, but swap the first receiving
            if(*(stack_a->data) < *(stack_b->data))
            {
                ft_push(&stack_a, &stack_b);
                op_count++;
                ft_printf("pb %d\n", op_count);
                swap(&stack_b);
                op_count++;
                ft_printf("sb %d\n", op_count);
                ft_push(&stack_b, &stack_a);
                op_count++;
                ft_printf("pa %d\n", op_count);
            } 
                //check
                    printf("Contents of stack_a:\n");
                    print_stack(stack_a);
        
                    printf("Contents of stack_b:\n");
                    print_stack(stack_b);
        }
        else if(pos_min > len_a / 2 && pos_max <= len_b / 2)
        {
            while(pos_min <= len_a)
            {
                //swap before rotating 
                if(pos_min != 2 && pos_max != 2 && *(stack_a->data) > *(stack_a->next->data) && *(stack_b->data) < *(stack_b->next->data))
                {
                    swap(&stack_a);
                    swap(&stack_b);
                    op_count++;
                    ft_printf("ss %d\n", op_count);
                            //check
                            printf("Contents of stack_a after double swap:\n");
                            print_stack(stack_a);
                            printf("Contents of stack_b after double swap:\n");
                            print_stack(stack_b);
                }
                else if(pos_min != 2 && *(stack_a->data) > *(stack_a->next->data))
                {
                    swap(&stack_a);
                    op_count++;
                    ft_printf("sa %d\n", op_count);
                            //check
                            printf("Contents of stack_a after swap:\n");
                            print_stack(stack_a);
                }
                else if(pos_max != 2 && *(stack_b->data) < *(stack_b->next->data))
                {
                    swap(&stack_b);
                    op_count++;
                    ft_printf("sb %d\n", op_count);
                            //check
                            printf("Contents of stack_b after swap:\n");
                            print_stack(stack_b);    
                }
                // rotate after the swaps
                ft_rev_rotate(&stack_a);
                op_count++;
                ft_printf("rra %d\n", op_count);
                pos_min++;
            }
            while(pos_max > 1)
            {
                //swap before rotating 
                if(pos_min != 2 && pos_max != 2 && *(stack_a->data) > *(stack_a->next->data) && *(stack_b->data) < *(stack_b->next->data))
                {
                    swap(&stack_a);
                    swap(&stack_b);
                    op_count++;
                    ft_printf("ss %d\n", op_count);
                            //check
                            printf("Contents of stack_a after double swap:\n");
                            print_stack(stack_a);
                            printf("Contents of stack_b after double swap:\n");
                            print_stack(stack_b);
                }
                else if(pos_min != 2  &&*(stack_a->data) > *(stack_a->next->data))
                {
                    swap(&stack_a);
                    op_count++;
                    ft_printf("sa %d\n", op_count);
                            //check
                            printf("Contents of stack_a after swap:\n");
                            print_stack(stack_a);
                }
                else if(pos_max != 2 && *(stack_b->data) < *(stack_b->next->data))
                {
                    swap(&stack_b);
                    op_count++;
                    ft_printf("sb %d\n", op_count);
                            //check
                            printf("Contents of stack_b after swap:\n");
                            print_stack(stack_b);    
                }
                // rotate after the swaps
                ft_rotate(&stack_b);
                op_count++;
                ft_printf("rb %d\n", op_count);
                pos_max--;
            }
                        //check
                    printf("Contents of stack_a:\n");
                    print_stack(stack_a);
        
                    printf("Contents of stack_b:\n");
                    print_stack(stack_b);
            //push the min at the top of a & the max at the top of b, but swap the first receiving
            if(*(stack_a->data) < *(stack_b->data))
            {
                ft_push(&stack_a, &stack_b);
                op_count++;
                ft_printf("pb %d\n", op_count);
                swap(&stack_b);
                op_count++;
                ft_printf("sb %d\n", op_count);
                ft_push(&stack_b, &stack_a);
                op_count++;
                ft_printf("pa %d\n", op_count);
            } 
                //check
                    printf("Contents of stack_a:\n");
                    print_stack(stack_a);
        
                    printf("Contents of stack_b:\n");
                    print_stack(stack_b);
        }
        if(!is_sorted_asc(stack_a) && !is_sorted_desc(stack_b) && find_minimum(&stack_a) == 1 && find_maximum(&stack_b) == 1)
            break ;
    }
    // sort each stack after stop of transfer between stacks
    pos_min = find_minimum(&stack_a);
    while(!is_sorted_asc(stack_a))
    {
        printf("la posicion del minimo en a es %d\n", pos_min);
        len_a = ft_lstsize(stack_a);
        printf("la nueva longitud de a es %d\n", len_a);
        if(pos_min <= len_a / 2 && pos_min > 1)
        {
            while(pos_min > 1)
            {
                ft_rotate(&stack_a);
                pos_min--;
                op_count++;
                ft_printf("ra %d\n", op_count);
            }
                        //check
                    printf("Contents of stack_a:\n");
                    print_stack(stack_a);
        }
        else if(pos_min > len_a / 2)
        {
            while(pos_min <= len_a)
            {
                ft_rev_rotate(&stack_a);
                pos_min++;
                op_count++;
                ft_printf("rra %d\n", op_count);
            }
                        //check
                    printf("Contents of stack_a:\n");
                    print_stack(stack_a);
        }
        else if(pos_min == 1)
        {
            ft_push(&stack_a, &stack_b);
            op_count++;
            ft_printf("pb %d\n", op_count);
        }
        pos_min = find_minimum(&stack_a);
        ft_printf("La posicion del next min es %d\n", pos_min);
                                //check
                    printf("Contents of stack_a:\n");
                    print_stack(stack_a);
        
                    printf("Contents of stack_b:\n");
                    print_stack(stack_b);
    }
    while(!is_sorted_desc(stack_b))
    {
        pos_max = find_maximum(&stack_b);
        len_b = ft_lstsize(stack_b);
        printf("la posicion del maximo en b es %d\n", pos_max);
        
        if(pos_max <= len_b / 2 && pos_max > 1)
        {
            while(pos_max > 1)
            {
                ft_rotate(&stack_b);
                pos_max--;
                op_count++;
                ft_printf("rb %d\n", op_count);
            }
                        //check
                    printf("Contents of stack_b:\n");
                    print_stack(stack_b);
        }
        else if(pos_max > len_b / 2)
        {
            while(pos_max <= len_b)
            {
                ft_rev_rotate(&stack_b);
                pos_max++;
                op_count++;
                ft_printf("rrb %d\n", op_count);
            }
                        //check
                    printf("Contents of stack_b:\n");
                    print_stack(stack_b);
        }
        else if(pos_max == 1)
        {
            ft_push(&stack_b, &stack_a);
            op_count++;
            ft_printf("pa %d\n", op_count);
            pos_max = find_maximum(&stack_b);
        }
                                //check
                    printf("Contents of stack_a:\n");
                    print_stack(stack_a);
        
                    printf("Contents of stack_b:\n");
                    print_stack(stack_b);
    }
    //push the remaining numbers from stack_b
    while(stack_b != NULL)
    {
            ft_push(&stack_b, &stack_a);
            op_count++;
            ft_printf("pa %d\n", op_count);         
    }
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
    