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

void	ft_rotate_b(t_stacks *stacks, t_stack *head_b, int print)
{
	t_stack	*tmp_node;

	tmp_node = head_b;
	stacks->head_b = head_b->next;
	while (head_b->next != NULL)
		head_b = head_b->next;
	head_b->next = tmp_node;
	tmp_node->next = NULL;
	if (print != 0)
		ft_printf("rb\n");
	return ;
}

void	ft_rev_rotate(t_stacks *stacks, char c)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = stacks->head_a;
	head_b = stacks->head_b;
	if (c == 'a')
		ft_rev_rotate_a(stacks, 1);
	else if (c == 'b')
	{
		if (head_b == NULL || head_b->next == NULL)
			return ;
		ft_rev_rotate_b(stacks, 1);
	}
	else
	{
		if (head_a == NULL || head_a->next == NULL || 
			head_b == NULL || head_b->next == NULL)
			return ;
		ft_rev_rotate_a(stacks, 0);
		ft_rev_rotate_b(stacks, 0);
		ft_printf("rrr\n");
	}
	return ;
}

void	ft_rev_rotate_a(t_stacks *stacks, int print)
{
	t_stack	*current;

	current = stacks->head_a;
	while (current->next->next != NULL)
		current = current->next;
	current->next->next = stacks->head_a;
	stacks->head_a = current->next;
	current->next = NULL;
	if (print != 0)
		ft_printf("rra\n");
	return ;
}

void	ft_rev_rotate_b(t_stacks *stacks, int print)
{
	t_stack	*current;

	current = stacks->head_b;
	while (current->next->next != NULL)
		current = current->next;
	current->next->next = stacks->head_b;
	stacks->head_b = current->next;
	current->next = NULL;
	if (print != 0)
		ft_printf("rrb\n");
	return ;
}

void	ft_push(t_stacks *stacks, char c)
{
	t_stack	*head_b;

	head_b = stacks->head_b;
	if (c == 'a')
	{
		if (head_b == NULL)
			return ;
		else if (head_b->next == NULL)
			ft_last_push_a(stacks);
		else 
			ft_push_a(stacks);
	}
	else if (c == 'b')
	{
		if (head_b == NULL)
			ft_push_empty_b(stacks);
		else
			ft_push_b(stacks);
	}
	return ;
}
