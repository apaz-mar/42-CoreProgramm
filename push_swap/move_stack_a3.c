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

//child of move_stack_a
void	new_num_stack_a(t_stacks *stacks, t_stack *head_b)
{
	int	i;
	int	len;

	stacks->op_count->ra = 0;
	stacks->op_count->rra = 0;
	if (*(stacks->head_a->data) != search_stack_a(stacks, *(head_b->data)))
	{
		i = find_index_stack_a(stacks, search_stack_a(stacks, *(head_b->data)));
		len = ft_listsize(stacks->head_a);
		count_a(i, len, stacks);
	}
	do_moves_num_stack_a(stacks);
	return ;
}

// child of new_num_stack_a
int	search_stack_a(t_stacks *stacks, int nbr)
{
	t_stack	*head_a;
	int		closest_larger_value;
	int		i;
	int		current_value;

	head_a = stacks->head_a;
	closest_larger_value = stacks->values->max_a; 
	i = 0;
	while (i < ft_listsize(stacks->head_a))
	{
		current_value = *(head_a->data);
		if (current_value > nbr && current_value < closest_larger_value) 
			closest_larger_value = current_value;
		head_a = head_a->next;
		i++;
	}
	return (closest_larger_value);
}

//child of new_num_stack_a
void	do_moves_num_stack_a(t_stacks *stacks)
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
	if (*(stacks->head_a->data) != stacks->values->min_a)
	{
		i = find_index_stack_a(stacks, stacks->values->min_a);
		len = ft_listsize(stacks->head_a);
		count_a(i, len, stacks);
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
