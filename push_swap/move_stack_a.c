/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:38:30 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/10/19 16:38:33 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// move the elements back to stack_a and ensuring the... 
// ...minimum element is at the top of stack_a previously

void	move_stack_a(t_stacks *stacks)
{
	while (stacks->head_b != NULL)
	{
		check_max_min_a(stacks);
		if (*(stacks->head_b->data) < stacks->values->min_a)
			new_min_stack_a(stacks);
		else if (*(stacks->head_b->data) > stacks->values->max_a)
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
	stacks->values->max_a = *(head_a->data);
	while (i < len)
	{
		if (stacks->values->max_a < *(head_a->data))
			stacks->values->max_a = *(head_a->data);
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
	len = ft_listsize(head_a);
	stacks->values->min_a = *(head_a->data);
	while (i < len)
	{
		if (stacks->values->min_a > *(head_a->data))
			stacks->values->min_a = *(head_a->data);
		head_a = head_a->next;
		i++;
	}
	return ;
}

//child of move_stack_a, it counts the ops and transfers an element... 
// ...from stack_b to stack_a when the element...
// ...is smaller than the current minimum of stack_a
void	new_min_stack_a(t_stacks *stacks)
{
	int	i;
	int	len;

	stacks->op_count->ra = 0;
	stacks->op_count->rra = 0;
	if (*(stacks->head_a->data) != stacks->values->min_a)
	{
		i = find_index_stack_a(stacks, stacks->values->min_a);
		len = ft_listsize(stacks->head_a);
		count_a(i, len, stacks);
	}
	do_moves_min_stack_a(stacks);
	return ;
}
