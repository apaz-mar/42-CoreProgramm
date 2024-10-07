#include "push_swap.h"

void fill_stack(int ac, char **av, t_list **stack)
{
    int i;
    i = 1;
    while(i < ac)
    {
        t_list *new_node = (t_list *)malloc(sizeof(t_list));
        if (!new_node)
        {
            perror("Failed to allocate memory for new_node");
            new_node = NULL;
            free(new_node);
        }
        //printf("el digito es %d\n", atoi(av[i]));
        new_node->data = (int *)malloc(sizeof(int));
        if (!new_node->data)
        {
            perror("Failed to allocate memory for new_node->data");
            new_node->data = NULL;
            free(new_node->data);
        }
        *(new_node->data) = atoi(av[i]);
        new_node->next = NULL;
        if(!*stack)
            *stack = new_node;
        else
        {
            t_list *temp = *stack;
            while(temp->next)
                temp = temp->next;
            temp->next = new_node;
        }
        //printf("Inserted: %d\n", *(new_node->data));
        i++;
    }
    return ;
}

void print_stack(t_list *stack)
{
    t_list *temp = stack;
    while (temp != NULL)
    {
        printf("%d ", *(temp->data));
    temp = temp->next;
    }
    printf("\n");    
    return ;
}

int is_sorted_desc(t_list *stack)
{
    if (!stack || !(stack->next))
        return (1); // A single element or empty stack is trivially sorted

    while (stack->next)
    {
        if (*(stack->data) <= *(stack->next->data))
            return (0); // Found an element out of order
        stack = stack->next;
    }
    return (1); // Stack is sorted
}

int is_sorted_asc(t_list *stack)
{
    if (!stack || !(stack->next))
        return (1); // A single element or empty stack is trivially sorted

    while (stack->next)
    {
        if (*(stack->data) >= *(stack->next->data))
            return (0); // Found an element out of order
        stack = stack->next;
    }
    return (1); // Stack is sorted
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

int    fill_chunk(t_list **stack_a, t_list **stack_b, int chunk_start, int chunk_end, int *op_count)
{
    t_list *cur = *stack_a;
    int len_a = ft_lstsize(*stack_a);
    int i = 1;
    while(i <= len_a)
    {
        int value = *(cur->data);
        ft_printf("El digito de la lista es: %d\n", value);
        if(value >= chunk_start && value <= chunk_end)
        {
            while (*((*stack_a)->data) != value && i <= ft_lstsize(*stack_a) / 2) 
            {
                ft_rotate(stack_a);  
                (*op_count)++;
                ft_printf("ra %d\n", *op_count);
                cur = *stack_a;
            }
            while (*((*stack_a)->data) != value && i > ft_lstsize(*stack_a) / 2) 
            {
                ft_rev_rotate(stack_a);  
                (*op_count)++;
                ft_printf("rra %d\n", *op_count);
                cur = *stack_a;
            }
            ft_push(stack_a, stack_b);  
            (*op_count)++;
            ft_printf("pb %d\n", *op_count);
            cur = *stack_a;
        }
        else 
            cur = cur->next;
        i++;
    }
    printf("Contents after chunk transfer from stack_a:\n");
    print_stack(*stack_a);

    printf("Contents after chunk transfer into stack_b:\n");
    print_stack(*stack_b);
    return (*op_count);
}

void	sort_three(t_list **stack_a, int *op_count)
{
	t_list	*cur_a;
	int num1;
	int	num2;
	int	num3;

	cur_a = *stack_a;
        if (cur_a == NULL || cur_a->next == NULL || cur_a->next->next == NULL) {
        printf("Not enough elements to sort.\n");
        return; // Exit early if there are not enough elements
    }
	num1 = *(cur_a->data);
	num2 = *(cur_a->next->data);
	num3 = *(cur_a->next->next->data);
	if (num1 > num2 && num1 < num3 && num2 < num3)
    {
		swap(stack_a);
        (*op_count)++;
        ft_printf("sa %d\n", *op_count);
    }
	else if (num1 > num2 && num1 > num3 && num2 < num3)
    {
		ft_rotate(stack_a);
        (*op_count)++;
        ft_printf("ra %d\n", *op_count);
    }
	else if (num1 < num2 && num1 > num3 && num2 > num3)
    {
		ft_rev_rotate(stack_a);
        (*op_count)++;
        ft_printf("rra %d\n", *op_count);
    }
	else if (num1 > num2 && num1 > num3 && num2 > num3)
	{
		swap(stack_a);
        (*op_count)++;
        ft_printf("sa %d\n", *op_count);
		ft_rev_rotate(stack_a);
        (*op_count)++;
        ft_printf("rra %d\n", *op_count);
	}
	else if (num1 < num2 && num1 < num3 && num2 > num3)
	{
		swap(stack_a);
        (*op_count)++;
        ft_printf("sa %d\n", *op_count);
		ft_rotate(stack_a);
        (*op_count)++;
        ft_printf("ra %d\n", *op_count);
	}
                                        //check
                        printf("Contents of stack_a:\n");
                        print_stack(*stack_a);
            
    return ;
}

void	move_stack_a(t_list **stack_a, t_list **stack_b, int *op_count)
{
	t_list	*cur_a;
	int num1;
	int	num2;
	int	num3;

	cur_a = *stack_a;
        if (cur_a == NULL || cur_a->next == NULL || cur_a->next->next == NULL) {
        printf("Not enough elements to sort.\n");
        return; // Exit early if there are not enough elements
    }
	num1 = *(cur_a->data);
	num2 = *(cur_a->next->data);
	num3 = *(cur_a->next->next->data);
    while (*stack_b != NULL)
	{ 
        if(*(*stack_b)->data < num1)
        {
            ft_push(stack_b, stack_a);
            (op_count)++;
            ft_printf("pa %d\n", *op_count);  
        }
        else if(*(*stack_b)->data > num3)
        {
            ft_push(stack_b, stack_a);
            (op_count)++;
            ft_printf("pa %d\n", *op_count);
            ft_rotate(stack_a);
            (*op_count)++;
            ft_printf("ra %d\n", *op_count);   
        }
        else if(*(*stack_b)->data > num1 && *(*stack_b)->data < num2)
        {
            ft_rotate(stack_a);
            (*op_count)++;
            ft_printf("ra %d\n", *op_count);  
            ft_push(stack_b, stack_a);
            (op_count)++;
            ft_printf("pa %d\n", *op_count); 
            ft_rev_rotate(stack_a);
            (*op_count)++;
            ft_printf("rra %d\n", *op_count);  
        }
        else if(*(*stack_b)->data > num2 && *(*stack_b)->data < num3)
        {
            ft_rev_rotate(stack_a);
            (*op_count)++;
            ft_printf("rra %d\n", *op_count);  
            ft_push(stack_b, stack_a);
            (op_count)++;
            ft_printf("pa %d\n", *op_count); 
            ft_rotate(stack_a);
            (*op_count)++;
            ft_printf("ra %d\n", *op_count);  
            ft_rotate(stack_a);
            (*op_count)++;
            ft_printf("ra %d\n", *op_count); 
        }  
                                            //check
                        printf("Contents of stack_a:\n");
                        print_stack(*stack_a);
            
                        printf("Contents of stack_b:\n");
                        print_stack(*stack_b);  
	}
    return ;
}

