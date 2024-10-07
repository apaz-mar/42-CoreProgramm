
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

long long int product_of_group(t_list *start, int size)
{
    long long int product = 1;
    int i = 0;

    // Debugging: Ensure the group size is valid
    if (size == 0)
    {
        printf("Error: Group size is 0, cannot compute product.\n");
        return 0;
    }

    while (start != NULL && i < size)
    {

        if (start->data == NULL)  // Check if the data pointer is valid
        {
            printf("Error: Encountered NULL data in list at position %d.\n", i);
            return 0;  // Return 0 or handle the error appropriately
        }

        // Debugging: Print each value being multiplied for verification
        printf("Multiplying with: %d\n", *(start->data));
        product = product * *(start->data);
        start = start->next;
        i++;
    }
    return (product);
}

void divide_and_sort(t_list **stack_a, int len_a, int *op_count)
{
    int div = 2;
    int group_size = len_a / div;
    printf("Group size: %d\n", group_size);
    t_list *cur;
    int j;
    long long int pieces[div];

    // Calculate the product of each divided group
    cur = *stack_a;
    j = 0;
    while (j < div)
    {      
        pieces[j] = product_of_group(cur, group_size);
        printf("El producto de esta mitad es %lld\n", pieces[j]);
        int i = 0;
        while (i < group_size && cur != NULL)
        {
            cur = cur->next;
            i++;
        }
        j++;
    }
    // Sort groups based on their products
    if (pieces[1] < pieces[0])
    {
        int rotate_count = group_size;
        while (rotate_count > 0)
        {
            ft_rotate(stack_a);
            (*op_count)++;
            ft_printf("ra %d\n", *op_count);
            rotate_count--;
        }
    }      
}

int find_minimum(t_list **stack_a)
{
    int pos = 1;
    int i = 1;
    t_list *cur = *stack_a;
    int minimum = *cur->data;
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

void    minimum_up(t_list **stack_a, int pos_min, int len_a, int *op_count)
{
    if(pos_min == 1 && len_a == 1)
        return ;
    if(pos_min <= len_a / 2)
    {
        while(pos_min > 1)
        {
            //printf("Top elements: %d, %d\n", *(*stack_a)->data, *(*stack_a)->next->data);
            //if(pos_min != 2 && (*stack_a) && (*stack_a)->next && *(*stack_a)->data > *(*stack_a)->next->data)
            //{
             //   printf("hay que hacer un swap\n");
             //   swap(stack_a);
             //   (*op_count)++;
             //   ft_printf("sa %d\n", *op_count);
            //}
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

            //printf("Top elements: %d, %d\n", *(*stack_a)->data, *(*stack_a)->next->data);
            //if(pos_min != 2 && (*stack_a) && (*stack_a)->next && *(*stack_a)->data > *(*stack_a)->next->data)
            //{
              //  printf("hay que hacer un swap\n");
                //swap(stack_a);
                //(*op_count)++;
                //ft_printf("sa %d\n", *op_count);
           // }
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

    t_list *stack_a = NULL;
    t_list *stack_b = NULL;
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
        if(!stack_a)
            stack_a = new_node;
        else
        {
            t_list *temp = stack_a;
            while(temp->next)
                temp = temp->next;
            temp->next = new_node;
        }
        //printf("Inserted: %d\n", *(new_node->data));
        i++;
    }

printf("Contents of stack_a:\n");
t_list *temp = stack_a;
while (temp != NULL)
{
    printf("%d ", *(temp->data));
    temp = temp->next;
}

printf("\n");

    int len_a = ft_lstsize(stack_a);
    printf("la longitud de la lista es %d\n", len_a);
    //divide_and_sort(&stack_a, len_a, &op_count);

    while(len_a > 0)
    {
        int pos_min = find_minimum(&stack_a);
        //printf("la posicion del minimo es %d\n", pos_min);
        minimum_up(&stack_a, pos_min, len_a, &op_count);
        ft_push(&stack_a, &stack_b);
        op_count++;
        ft_printf("pb %d\n", op_count);
        len_a = ft_lstsize(stack_a);
    }
    // Print the sorted stack_a for testing purposes
    t_list *cur = stack_a;
    //printf("La lista a es \n");
    while (cur)
    {
        //printf("%d\n", *(cur->data));
        cur = cur->next;
    }
    // Print the sorted stack_b (which holds sorted elements in reverse)
    t_list *cur_b = stack_b;
    //printf("La lista b es \n");
    while (cur_b)
    {
        //printf("%d\n", *(cur_b->data));
        cur_b = cur_b->next;
    }

    // Push elements back to stack_a
    int len_b = ft_lstsize(stack_b);
    while(len_b > 0)
    {
        ft_push(&stack_b, &stack_a);
        op_count++;
        ft_printf("pa %d\n", op_count);
        len_b = ft_lstsize(stack_b);
    }

    // Print the sorted stack_a for testing purposes
    cur = stack_a;
    printf("La lista a es \n");
    while (cur)
    {
        printf("%d\n", *(cur->data));
        cur = cur->next;
    }
    // Print the sorted stack_b for testing purposes
    cur = stack_b;
    //printf("La lista b es \n");
    while (cur_b)
    {
        //printf("%d\n", *(cur_b->data));
        cur_b = cur_b->next;
    }
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
    