/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest_check_ops_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:44:55 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/10/19 19:44:58 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//child of new_num_in_stack_b, which belongs to check_ops.
//it searches the next smaller number in stack_b 
//in respect of the number in stack_a being analysed
int	search_num_stack_b(t_stacks *stacks, int nbr)
{
	t_stack		*head_b;
	int			closest_smaller;
	int			i;
	int			len;

	i = 0;
	closest_smaller = stacks->values->min_b;
	head_b = stacks->head_b;
	len = ft_listsize(stacks->head_b);
	while (i < len)
	{
		if (*(head_b->data) < nbr && *(head_b->data) > closest_smaller)
			closest_smaller = *(head_b->data);
		head_b = head_b->next;
		i++;
	}
	return (closest_smaller);
}

//Child of check_ops, after counting possible ops... 
//...of a max, a min or a num, check doubles:
void	check_double_moves(t_stacks *stacks)
{
	stacks->op_count->rr = 0;
	stacks->op_count->rrr = 0;
	while (stacks->op_count->ra != 0 && stacks->op_count->rb != 0)
	{
		stacks->op_count->ra--;
		stacks->op_count->rb--;
		stacks->op_count->rr++;
	}
	while (stacks->op_count->rra != 0 && stacks->op_count->rrb != 0)
	{
		stacks->op_count->rra--;
		stacks->op_count->rrb--;
		stacks->op_count->rrr++;
	}
	return ;
}

//Total sum of the previous ops and comparison to the cheapest case
void	check_cost(t_stacks *stacks, int i)
{
	stacks->op_count->cost = stacks->op_count->pb + stacks->op_count->ra
		+ stacks->op_count->rb + stacks->op_count->rr + stacks->op_count->rra
		+ stacks->op_count->rrb + stacks->op_count->rrr;
	if (i == 0 || (stacks->cheap->cost > stacks->op_count->cost))
	{
		stacks->cheap->cost = stacks->op_count->cost;
		stacks->cheap->pb = stacks->op_count->pb;
		stacks->cheap->ra = stacks->op_count->ra;
		stacks->cheap->rb = stacks->op_count->rb;
		stacks->cheap->rr = stacks->op_count->rr;
		stacks->cheap->rra = stacks->op_count->rra;
		stacks->cheap->rrb = stacks->op_count->rrb;
		stacks->cheap->rrr = stacks->op_count->rrr;
	}
	return ;
}

//Execute the cheapest according to check_cost
void	do_cheap_ops(t_stacks *stacks)
{
	while (stacks->cheap->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->cheap->rb-- != 0)
		ft_rotate(stacks, 'b');
	while (stacks->cheap->rr-- != 0)
		ft_rotate(stacks, 'r');
	while (stacks->cheap->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	while (stacks->cheap->rrb-- != 0)
		ft_rev_rotate(stacks, 'b');
	while (stacks->cheap->rrr-- != 0)
		ft_rev_rotate(stacks, 'r');
	while (stacks->cheap->pb-- != 0)
		ft_push(stacks, 'b');
	return ;
}
