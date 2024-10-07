
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int             *data;
    struct s_list   *next;
}                   t_list;

t_list *stack_a = NULL;

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

int product_of_group(t_list *start, int size)
{
    int product = 1;
    int i = 0;
    while (start != NULL && i < size)
    {
        product = product * *(start->data);
        start = start->next;
        i++;
    }
    return (product);
}

void divide_and_sort(t_list **stack_a, int len_a)
{
    //t_list *stack_b = NULL;
    int div = 2;

    // Dividing and sorting by groups of two, three, five, etc.
    while (div <= len_a)
    {
        int group_size = len_a / div;
        int remainder = len_a % div;

        int pieces[div];
        t_list *cur = *stack_a;
        int j = 0;
        
        // Calculate product of each divided group, beware the remainders
        while (j < div)
        {
            int current_group_size = group_size;
            if(j == div - 1 && remainder > 0)
                current_group_size = current_group_size + remainder;
            printf("current group size es %d\n", current_group_size);

            pieces[j] = product_of_group(cur, current_group_size);
            printf("el producto del grupo %d es %d\n", j, pieces[j]);
            int i = 0;
            while(i < current_group_size && cur != NULL)
            {
                cur = cur->next;
                i++;
            }
            j++;
        }

        // Sort groups based on their products
        int i = 0;
        int safety_counter = 0; // To avoid infinite loop
        while(i < div - 1)
        {
            // Safety mechanism to prevent infinite loops
            if (safety_counter > len_a * div) 
            {
                printf("Infinite loop detected, breaking out...\n");
                break;
            }
            if (pieces[i + 1] < pieces[i])
            {
                // Rotate the group to sort them
                int rotate_count = group_size;
                //if(rotate_count == 1)
                //    return ;
                printf("rotate_count es %d\n", rotate_count);
                if(i == div - 2 && remainder > 0)
                    rotate_count = rotate_count + remainder;
                while (rotate_count > 0)
                {
                    ft_rotate(stack_a);
                    rotate_count--;
                }
                // After rotation, recalculate the product of groups since the list order has changed
                cur = *stack_a;
                j = 0;
                while (j < div)
                {
                    int current_group_size = group_size;

                    if (j == div - 1 && remainder > 0)
                        current_group_size += remainder;

                    pieces[j] = product_of_group(cur, current_group_size);

                    int k = 0;
                    while (k < current_group_size && cur != NULL)
                    {
                        cur = cur->next;
                        k++;
                    }
                    j++;
                }
                i = 0;
            }
            else
                i++;
            safety_counter++;
        }
        div++;  // Divide into more groups in next iteration
    }
}

int main(int ac, char **av)
{
    if(ac < 2)
        return (0);
        // Initialize stack_a with the input values
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
        printf("el digito es %d\n", atoi(av[i]));
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
        printf("Inserted: %d\n", *(new_node->data));
        i++;
    }
    //check if it has been initialized
    t_list *temp = stack_a;
    while (temp)
    {
        printf("%d\n", *(temp->data));
        temp = temp->next;
    }
    // Call the divide and sort function
    int len_a = ft_lstsize(stack_a);
    printf("Longitud lista: %d\n", len_a);

    divide_and_sort(&stack_a, len_a);

    // Print the sorted stack for testing purposes
    t_list *cur = stack_a;
    while (cur)
    {
        printf("%d\n", *(cur->data));
        cur = cur->next;
    }

    // Free the allocated memory
    while (stack_a)
    {
        t_list *tmp = stack_a;
        stack_a = stack_a->next;
        free(tmp->data);
        free(tmp);
    }
    return 0;
}
    