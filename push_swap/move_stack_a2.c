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

// child of new_min_stack_a
int	find_index_stack_a(t_stacks *stacks, int nbr)
{
	t_stack	*head_a;
	int		len;
	int		i;

	i = 0;
	head_a = stacks->head_a;
	len = ft_listsize(stacks->head_a);
	while (i < len)
	{
		if (*(head_a->data) == nbr)
			break ;
		head_a = head_a->next;
		i++;
	}
	return (i);
}

// child of new_min_stack_a
void	do_moves_min_stack_a(t_stacks *stacks)
{
	while (stacks->op_count->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->op_count->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	ft_push(stacks, 'a');
	return ;
}

// child of move_stack_a. It counts the ops and transfers an ...
// ...element from stack_b to stack_a when the element...
// is bigger than the current maximum of stack_a
void	new_max_stack_a(t_stacks *stacks)
{
	int	i;
	int	len;

	stacks->op_count->ra = 0;
	stacks->op_count->rra = 0;
	if (*(ft_lstlast(stacks->head_a)->data) != stacks->values->max_a)
	{
		i = find_index_stack_a(stacks, stacks->values->max_a);
		len = ft_listsize(stacks->head_a);
		count_a_max(i, len, stacks);
	}
	do_moves_max_stack_a(stacks);
	return ;
}

void	count_a_max(int i, int len, t_stacks *stacks)
{
	if (len % 2 == 0)
	{
		if (i + 1 > len / 2)
			stacks->op_count->rra = (len - i - 1);
		else
			stacks->op_count->ra = i;
	}
	else
	{
		if (i > len / 2)
			stacks->op_count->rra = (len - i - 1);
		else
			stacks->op_count->ra = i;
	}
	return ;
}

// child of new_max_stack_a
void	do_moves_max_stack_a(t_stacks *stacks)
{
	while (stacks->op_count->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->op_count->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	ft_push(stacks, 'a');
	return ;
}
