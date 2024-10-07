
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

    int chunk_size = len_a / 5;
    int remaining = len_a % 5;
    
    int chunk;
    chunk = 0;
    while(chunk < 5)
    {
        int chunk_start = chunk * chunk_size + 1;
        int chunk_end = chunk_start + chunk_size - 1;
        if(chunk == 4)
            chunk_end = chunk_end + remaining;
        
        printf("Filling chunk %d:\n", chunk);
        fill_chunk(&stack_a, &stack_b, chunk_start, chunk_end, &op_count);
        
        len_b = ft_lstsize(stack_b);
        printf("Check longitud de b tras transfer de chunk: %d \n", len_b);
            //check
                printf("Contents of stack_a:\n");
                print_stack(stack_a);

                printf("Contents of stack_b:\n");
                print_stack(stack_b);

        int pos_max = find_maximum(&stack_b);

        int sorted_position = 1;
        // Find minimum in stack_a and maximum in stack_b and transfer to each other stack
        // This loop works until the medium nodes are confronted
        while(!(is_sorted_desc(stack_b)) && stack_b != NULL)
        {
            pos_max = find_maximum(&stack_b);
            printf("la posicion del maximo en b es %d\n", pos_max);

            // Check if the positions are valid before proceeding
            len_b = ft_lstsize(stack_b);
            if (pos_max > len_b)
                break ; // Exit if positions are out of range

            if(pos_max > len_b / 2)
            {
                while(pos_max <= len_b)
                {
                    ft_rev_rotate(&stack_b);
                    op_count++;
                    ft_printf("rrb %d\n", op_count);
                    pos_max++;
                }
                            //check
                        printf("Contents of stack_b:\n");
                        print_stack(stack_b);
            }
            else if (pos_max <= len_b / 2)
            {
                while(pos_max > 1)
                {
                    ft_rotate(&stack_b);
                    op_count++;
                    ft_printf("rb %d\n", op_count);
                    pos_max--;
                }
            }
            // The maximum is now at the top of stack_b. 
            // To keep it in place, perform `sorted_position - 1` rotations to push it down.

            int rotations = sorted_position - 1;  // Track the number of rotations needed
            while (rotations > 0)
            {
                ft_rotate(&stack_b);  // Rotates down so the next max can be placed
                op_count++;
                ft_printf("rb %d\n", op_count);
                rotations--;
            }

            sorted_position++;  // Move the sorted position deeper for the next max
            if (is_sorted_desc(stack_b)) break;
            //check        
            printf("Contents of stack_a:\n");
            print_stack(stack_a);

            printf("Contents of stack_b:\n");
            print_stack(stack_b);
        }
        chunk++;
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
    