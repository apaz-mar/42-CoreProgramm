/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliaries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:35:26 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/09/28 11:35:28 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_empty_b(t_stacks *stacks)
{
	stacks->head_b = stacks->head_a;
	stacks->head_a = stacks->head_a->next;
	stacks->head_b->next = NULL;
	ft_printf("pb\n");
	return ;
}

void	ft_push_b(t_stacks *stacks)
{
	t_stack	*tmp_node;

	tmp_node = stacks->head_b;
	stacks->head_b = stacks->head_a;
	stacks->head_a = stacks->head_a->next;
	stacks->head_b->next = tmp_node;
	ft_printf("pb\n");
	return ;
}

void	ft_last_push_a(t_stacks *stacks)
{
	t_stack	*tmp_node;

	tmp_node = stacks->head_a;
	stacks->head_a = stacks->head_b;
	stacks->head_a->next = tmp_node;
	stacks->head_b = NULL;
	ft_printf("pa\n");
	return ;
}

void	ft_push_a(t_stacks *stacks)
{
	t_stack	*tmp_node;

	tmp_node = stacks->head_a;
	stacks->head_a = stacks->head_b;
	stacks->head_b = stacks->head_b->next;
	stacks->head_a->next = tmp_node;
	ft_printf("pa\n");
	return ;
}
