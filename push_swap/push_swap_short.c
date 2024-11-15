/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:35:07 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/09/28 11:35:15 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stacks *stacks)
{
	ft_swap(stacks, 'a');
	ft_clearnodes(&stacks->head_a);
	exit(0);
}

//Case 1: [3, 2, 1] ------ Case 2: [3, 1, 2]----- Case 3: [2, 3, 1]
//Case 4: [2, 1, 3] ------ Case 5: [1, 3, 2]----- Case 6: [1, 2, 3]
void	sort_three(t_stacks *stacks, int flag)
{
	t_stack	*head_a;
	int		num1;
	int		num2;
	int		num3;

	head_a = stacks->head_a;
	num1 = *(head_a->data);
	num2 = *(head_a->next->data);
	num3 = *(head_a->next->next->data);
	if (num1 > num2 && num2 > num3)
	{
		ft_swap(stacks, 'a');
		ft_rev_rotate(stacks, 'a');
	}
	else
		sort_three_aux(stacks, num1, num2, num3);
	if (flag == 1)
	{
		ft_clearnodes(&stacks->head_a);
		exit(0);
	}
	return ;
}

void	sort_three_aux(t_stacks *stacks, int num1, int num2, int num3)
{
	if (num1 > num3 && num3 > num2)
		ft_rotate(stacks, 'a');
	else if (num1 < num2 && num1 > num3)
		ft_rev_rotate(stacks, 'a');
	else if (num2 < num1 && num1 < num3)
		ft_swap(stacks, 'a');
	else if (num1 < num3 && num3 < num2)
	{
		ft_rev_rotate(stacks, 'a');
		ft_swap(stacks, 'a');
	}
	return ;
}

void	sort_four(t_stacks *stacks)
{
	t_op_count	*op_count;
	t_cheap		*cheap;
	t_values	*values;

	{
		op_count = ft_calloc(1, sizeof(t_op_count));
		stacks->op_count = op_count;
		cheap = ft_calloc(1, sizeof(t_cheap));
		stacks->cheap = cheap;
		values = ft_calloc(1, sizeof(t_values));
		stacks->values = values;
		ft_push(stacks, 'b');
		sort_three(stacks, 0);
		move_stack_a(stacks);
		free_for_all(stacks);
		exit(0);
	}
	return ;
}
