

# include "push_swap.h"

// move the elements back to stack_a and ensuring the minimum element is at the top of stack_a previously

void    move_stack_a(t_stacks *stacks)
{
    while (stacks->head_b != NULL)
    {
        check_max_min_a(stacks);
        if (stacks->head_b->data < stacks->values->min_a)
            new_min_stack_a(stacks);
        else if (stacks->head_b->data > stacks->values->max_a)
            new_max_stack_a(stacks);
        else
            new_num_stack_a(stacks, stacks->head_b);
    }
    check_max_min_a(stacks);
    put_in_order(stacks);
    return ;
}

//child of move_stack_a, it updates the max and min values in stack_a
void	check_max_min_a(t_stacks *stacks)
{
	check_max_a(stacks, stacks->head_a);
	check_min_a(stacks, stacks->head_a);
    return ;
}

void	check_max_a(t_stacks *stacks, t_stack *head_a)
{
	int	i;
	int	len;

	i = 0;
	len = ft_listsize(head_a);
	stacks->values->max_a = head_a->data;
	while (i < len)
	{
		if (stacks->values->max_a < head_a->data)
			stacks->values->max_a = head_a->data;
		head_a = head_a->next;
		i++;
	}
    return ;
}

void	check_min_a(t_stacks *stacks, t_stack *head_a)
{
	int	i;
	int	len;

	i = 0;
	len = ft_listsize_a(head_a);
	stacks->values->min_a = head_a->data;
	while (i < size)
	{
		if (stacks->values->min_a > head_a->data)
			stacks->values->min_a = head_a->data;
		head_a = head_a->next;
		i++;
	}
    return ;
}

//child of move_stack_a, it counts the ops and transfers an element from stack_b to stack_a when the element
// is smaller than the current minimum of stack_a
void    new_min_stack_a(t_stacks *stacks)
{
    int     i;
    int     len;

    stacks->op_count->ra = 0;
    stacks->op_count->rra = 0;
    if (stacks->head_a->data != stacks->values->min_a)
    {
        i = find_index_stack_a(stacks, stacks->values->min_a);
        len = ft_listsize(stacks->head_a);
		if (len % 2 == 0)
		{
			if (i + 1 > len / 2)
				stacks->op_count->rra = (len - i);
			else
				stacks->op_count->ra = i;
		}
		else
		{
			if (i > len / 2)
				stacks->op_count->rra = (len - i);
			else
				stacks->op_count->ra = i;
		}        
    }
    do_moves_min_stack_a(stacks);
    return ;
}

// child of new_min_stack_a
int     find_index_stack_a(t_stacks *stacks, int nbr)
{
	t_stack     *head_a;
	int			len;
	int			i;

	i = 0;
	head_a = stacks->head_a;
	len = ft_listsize(stacks->head_a);
	while (i < len)
	{
		if (head_a->data == nbr)
			break ;
		head_a = head_a->next;
		i++;
	}
	return (i);
}

// child of new_min_stack_a
void    do_moves_min_stack_a(t_stacks *stacks)
{
    while (stacks->op_count->ra-- != 0)
        ft_rotate(stacks, 'a');
    while (stacks->op_count->rra-- != 0)
        ft_rev_rotate(stacks, 'a');
    ft_push(stacks, 'a');
    return ;
}

// child of move_stack_a. It counts the ops and transfers an element from stack_b to stack_a when the element
// is bigger than the current maximum of stack_a
void    new_max_stack_a(t_stacks *stacks)
{
    int     i;
    int     len;

    stacks->op_count->ra = 0;
    stacks->op_count->rra = 0;
    if (ft_lstlast(stacks->head_a)->data != stacks->values->max_a)
    {
        i = find_index_stack_a(stacks, stacks->values->max_a);
        len = ft_listsize(stacks->head_a);
		if (len % 2 == 0)
		{
			if (i + 1 > len / 2)
				stacks->op_count->rra = (len - i);
			else
				stacks->op_count->ra = i;
		}
		else
		{
			if (i > len / 2)
				stacks->op_count->rra = (len - i);
			else
				stacks->op_count->ra = i;
		}        
    }
    do_moves_max_stack_a(stacks);
    return ;
}

// child of new_max_stack_a
void    do_moves_max_stack_a(t_stacks *stacks)
{
	while (stacks->op_count->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->op_count->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	ft_push(stacks, 'a');
	ft_rotate(stacks, 'a');
    return ;
}

//child of move_stack_a
void    new_num_stack_a(t_stacks *stacks, t_stack *head_b)
{
	int	i;
	int	len;

	stacks->op_count->ra = 0;
	stacks->op_count->rra = 0;
	if (stacks->head_a->data != search_stack_a(stacks, head_b->data))
	{
		i = find_index_stack_a(stacks, search_stack_a(stacks, head_b->data));
		len = ft_listsize(stacks->head_a);
		if (len % 2 == 0)
		{
			if (i + 1 > len / 2)
				stacks->op_count->rra = (len - i);
			else
				stacks->op_count->ra = i;
		}
		else
		{
			if (i > len / 2)
				stacks->op_count->rra = (len - i);
			else
				stacks->op_count->ra = i;
		}
	}
	do_moves_elem_stack_a(stacks);
    return ;
}

// child of new_num_stack_a
int     search_stack_a(t_stacks *stacks, int nbr)
{
	t_stack     *head_a;
	int			len;
	int			flag;
	int			i;

	i = 0;
	flag = 0;
	head_a = stacks->head_a;
	len = ft_listsize(stacks->head_a);
	while (flag == 0)
	{
		i = 0;
		nbr++;
		head_a = stacks->head_a;
		while (i++ < len)
		{
			if (head_a->data == nbr)
				flag = 1;
			head_a = head_a->next;
		}
	}
	return (nbr);
}

//child of new_num_stack_a
void	do_moves_elem_stack_a(t_stacks *stacks)
{
	while (stacks->op_count->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->op_count->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	ft_push(stacks, 'a');
    return ;
}

//child of move_stack_a, so minimum to the top of stack_a
void	put_in_order(t_stacks *stacks)
{
	int	i;
	int	len;

	stacks->op_count->ra = 0;
	stacks->op_count->rra = 0;
	if (stacks->head_a->data != stacks->values->min_a)
	{
		i = find_index_stack_a(stacks, stacks->values->min_a);
		len = ft_listsize(stacks->head_a);
		if (len % 2 == 0)
		{
			if (i + 1 > len / 2)
				stacks->op_count->rra = (len - i);
			else
				stacks->op_count->ra = i;
		}
		else
		{
			if (i > len / 2)
				stacks->op_count->rra = (len - i);
			else
				stacks->op_count->ra = i;
		}
	}
	do_moves_order(stacks);
    return ;
}

//child of put_in_order
void	do_moves_order(t_stacks *stacks)
{
	while (stacks->op_count->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->op_count->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
    return ;
}