/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest_check_ops_1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:42:32 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/10/19 19:44:46 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_ops(t_stacks *stacks)
{
	int			i;
	int			len;
	t_stack		*head_a;

	i = 0;
	head_a = stacks->head_a;
	len = ft_listsize(stacks->head_a);
	while (i < len)
	{
		get_top_stack_a(stacks, head_a, i);
		if (*(head_a->data) > stacks->values->max_b || 
			*(head_a->data) < stacks->values->min_b)
			new_max_or_min_stack_b(stacks);
		else
			new_num_in_stack_b(stacks, *(head_a->data));
		check_double_moves(stacks);
		check_cost(stacks, i);
		head_a = head_a->next;
		i++;
	}
	return ;
}

//child of check_ops.
//Checking op_counts to shift the respective value to the top of stack_a 
//(it is in a loop checking all positions in stack_a):
void	get_top_stack_a(t_stacks *stacks, t_stack *head_a, int i)
{
	int		len;

	stacks->op_count->pb = 1;
	stacks->op_count->ra = 0;
	stacks->op_count->rra = 0;
	if (stacks->head_a->data == head_a->data)
		return ;
	len = ft_listsize(stacks->head_a);
	if (len % 2 == 0)
	{
		if ((i + 1) > len / 2)
			stacks->op_count->rra = len - i;
		else
			stacks->op_count->ra = i;
	}
	else
	{
		if (i > len / 2)
			stacks->op_count->rra = len - i;
		else
			stacks->op_count->ra = i;
	}
	return ;
}

//child of check_ops.
//Checking op_counts to shift the max_b to the top of stack_b:
void	new_max_or_min_stack_b(t_stacks *stacks)
{
	int		i;
	int		len;

	stacks->op_count->rb = 0;
	stacks->op_count->rrb = 0;
	if (*(stacks->head_b->data) == stacks->values->max_b)
		return ;
	i = find_index_stack_b(stacks, stacks->values->max_b);
	len = ft_listsize(stacks->head_b);
	if (len % 2 == 0)
	{
		if ((i + 1) > len / 2)
			stacks->op_count->rrb = len - i;
		else
			stacks->op_count->rb = i;
	}
	else
	{
		if (i > len / 2)
			stacks->op_count->rrb = len - i;
		else
			stacks->op_count->rb = i;
	}
	return ;
}

//child of new_max_or_min_stack_b, which comes from check_ops
//Checking op_counts to shift the max_b to the top of stacks_b,
// for that it is necessary to obtain the index of the max_b:
int	find_index_stack_b(t_stacks *stacks, int nbr)
{
	t_stack		*head_b;
	int			len;
	int			i;

	i = 0;
	head_b = stacks->head_b;
	len = ft_listsize(stacks->head_b);
	while (i < len)
	{
		if (*(head_b->data) == nbr)
			break ;
		head_b = head_b->next;
		i++;
	}
	return (i);
}

//child of check_ops.
//Checking op_counts to shift the corresponding value to the top 
//of stack_b (for preparing the case that not a max or a min 
//is going to be transferred to stack_b):
void	new_num_in_stack_b(t_stacks *stacks, int num)
{
	int		i;
	int		len;
	int		nbr;

	stacks->op_count->rb = 0;
	stacks->op_count->rrb = 0;
	nbr = search_num_stack_b(stacks, num);
	i = find_index_stack_b(stacks, nbr);
	len = ft_listsize(stacks->head_b);
	if (len % 2 == 0)
	{
		if ((i + 1) > len / 2)
			stacks->op_count->rrb = len - i;
		else
			stacks->op_count->rb = i;
	}
	else
	{
		if (i > len / 2)
			stacks->op_count->rrb = len - i;
		else
			stacks->op_count->rb = i;
	}
	return ;
}
