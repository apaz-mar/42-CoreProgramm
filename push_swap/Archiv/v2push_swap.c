
#include "push_swap.h"

int ft_swap(int *first, int *second)
{
    int swap;
    if(!second)
        return (0);
    swap = *first;
    *first = *second;
    *second = swap;
    return (0);
}

void ft_rotate(t_list **stack)
{
    if (!(*stack) || !((*stack)->next))
        return ;
    t_list *first = *stack;
    t_list *last = *stack;

    while (last->next)
        last = last->next;

    *stack = first->next;
    last->next = first;
    first->next = NULL;
}

void swap(t_list **stack)
{
    if (!(*stack) || !((*stack)->next))
        return ;
    t_list *first = *stack;
    t_list *second = first->next;

    first->next = second->next;
    second->next = first;
    *stack = second;
    return ;
}

void ft_rev_rotate(t_list **stack)
{
    if (!(*stack) || !((*stack)->next))
        return ;

    t_list *prev = NULL;
    t_list *last = *stack;

    while (last->next)
    {
        prev = last;
        last = last->next;
    }

    last->next = *stack;
    *stack = last;

    prev->next = NULL;
}

void ft_push(t_list **src, t_list **dest)
{
    if (!(*src))
        return;
    t_list *tmp = *src;
    *src = (*src)->next;
    tmp->next = *dest;
    *dest = tmp;
}

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

int find_minimum(t_list **stack_a)
{
    if(stack_a == NULL || *stack_a == NULL)
        return (-1);
    int pos = 1;
    int i = 1;
    t_list *cur = *stack_a;
    int minimum = *(cur->data);
    while(cur != NULL)
    {
        if(*(cur->data) < minimum)
        {
            minimum = *(cur->data);
            pos = i;
        }
        i++;
        cur = cur->next;
    }
    return (pos);
}

int find_maximum(t_list **stack_a)
{
    int pos = 1;
    int i = 1;
    t_list *cur = *stack_a;
    int maximum = *cur->data;
    while(cur != NULL)
    {
        if(*(cur->data) > maximum)
        {
            maximum = *(cur->data);
            pos = i;
        }
        i++;
        cur = cur->next;
    }
    return (pos);
}

void    minimum_up(t_list **stack_a, int pos_min, int len_a, int *op_count)
{
    if(pos_min == 1 && len_a == 1)
        return ;
    if(pos_min <= len_a / 2)
    {
        while(pos_min > 1)
        {
            if(pos_min != 1)
            {
                ft_rotate(stack_a);
                (*op_count)++;
                ft_printf("ra %d\n", *op_count);
                pos_min--;
            }
            //check
                printf("Contents of stack_a:\n");
                t_list *temp = *stack_a;
                while (temp != NULL)
                {
                printf("%d ", *(temp->data));
                temp = temp->next;
                }
                printf("\n");
        }  
    }
    else
    {
        while(pos_min <= len_a)
        {
            ft_rev_rotate(stack_a);
            (*op_count)++;
            ft_printf("rra %d\n", *op_count);
            pos_min++;
        }
                    //check
                printf("Contents of stack_a:\n");
                t_list *temp = *stack_a;
                while (temp != NULL)
                {
                printf("%d ", *(temp->data));
                temp = temp->next;
                }
                printf("\n");
    }
    return ;
}

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
            int diff_pos_min = pos_min - double_op;
            int diff_pos_max = pos_max - double_op;
            if(diff_pos_min != 0)
            {
                while(diff_pos_min > 1)
                {
                    ft_rotate(&stack_a);
                    op_count++;
                    ft_printf("ra %d\n", op_count);
                    diff_pos_min--;
                }
            }    
            if(diff_pos_max != 0)
            {
                while(diff_pos_max > 1)
                {
                    ft_rotate(&stack_b);
                    op_count++;
                    ft_printf("rb %d\n", op_count);
                    diff_pos_max--;
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
                swap(&stack_a);
                op_count++;
                ft_printf("sa %d\n", op_count);
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
                swap(&stack_a);
                op_count++;
                ft_printf("sa %d\n", op_count);
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
                ft_rotate(&stack_a);
                op_count++;
                ft_printf("ra %d\n", op_count);
                pos_min--;
            }
            while(pos_max <= len_a)
            {
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
                swap(&stack_a);
                op_count++;
                ft_printf("sa %d\n", op_count);
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
                ft_rev_rotate(&stack_a);
                op_count++;
                ft_printf("rra %d\n", op_count);
                pos_min++;
            }
            while(pos_max > 1)
            {
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
                swap(&stack_a);
                op_count++;
                ft_printf("sa %d\n", op_count);
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
    