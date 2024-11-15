/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:36:34 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/09/28 11:37:33 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cheapest(t_stacks *stacks)
{
	t_op_count	*op_count;
	t_cheap		*cheap;
	t_values	*values;

	op_count = ft_calloc(1, sizeof(t_op_count));
	stacks->op_count = op_count;
	cheap = ft_calloc(1, sizeof(t_cheap));
	stacks->cheap = cheap;
	values = ft_calloc(1, sizeof(t_values));
	stacks->values = values;
	while (ft_listsize(stacks->head_a) != 3)
	{
		check_max_min_b(stacks);
		check_ops(stacks);
		do_cheap_ops(stacks);
	}
	return ;
}

void	check_max_min_b(t_stacks *stacks)
{
	if (stacks->head_b != NULL)
	{
		check_min_b(stacks, stacks->head_b);
		check_max_b(stacks, stacks->head_b);
	}
	return ;
}

void	check_min_b(t_stacks *stacks, t_stack *head_b)
{
	int		i;
	int		len;

	if (stacks->head_b != NULL)
	{
		i = 0;
		len = ft_listsize(head_b);
		stacks->values->min_b = *(head_b->data);
		while (i < len)
		{
			if (stacks->values->min_b > *(head_b->data))
				stacks->values->min_b = *(head_b->data);
			head_b = head_b->next;
			i++;
		}
	}
	return ;
}

void	check_max_b(t_stacks *stacks, t_stack *head_b)
{
	int		i;
	int		len;

	if (stacks->head_b != NULL)
	{
		i = 0;
		len = ft_listsize(head_b);
		stacks->values->max_b = *(head_b->data);
		while (i < len)
		{
			if (stacks->values->max_b < *(head_b->data))
				stacks->values->max_b = *(head_b->data);
			head_b = head_b->next;
			i++;
		}
	}
	return ;
}
