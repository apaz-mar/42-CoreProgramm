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

void	ft_swap(t_stacks *stacks, char c)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = stacks->head_a;
	head_b = stacks->head_b;
	if (c == 'a')
		ft_swap_a(head_a, 1);
	else if (c == 'b')
	{
		if (head_b == NULL || head_b->next == NULL)
			return ;
		ft_swap_b(head_b, 1);
	}
	else
	{
		if (head_a == NULL || head_a->next == NULL || 
			head_b == NULL || head_b->next == NULL)
			return ;
		ft_swap_a(head_a, 0);
		ft_swap_b(head_b, 0);
		ft_printf("ss\n");
	}
	return ;
}

void	ft_swap_a(t_stack *head_a, int print)
{
	int	tmp;

	tmp = *(head_a->data);
	*(head_a->data) = *(head_a->next->data);
	*(head_a->next->data) = tmp;
	if (print != 0)
		ft_printf("sa\n");
	return ;
}

void	ft_swap_b(t_stack *head_b, int print)
{
	int	tmp;

	tmp = *(head_b->data);
	*(head_b->data) = *(head_b->next->data);
	*(head_b->next->data) = tmp;
	if (print != 0)
		ft_printf("sb\n");
	return ;
}

void	ft_rotate(t_stacks *stacks, char c)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = stacks->head_a;
	head_b = stacks->head_b;
	if (c == 'a')
		ft_rotate_a(stacks, head_a, 1);
	else if (c == 'b')
	{
		if (head_b == NULL || head_b->next == NULL)
			return ;
		ft_rotate_b(stacks, head_b, 1);
	}
	else
	{
		if (head_a == NULL || head_a->next == NULL || 
			head_b == NULL || head_b->next == NULL)
			return ;
		ft_rotate_a(stacks, head_a, 0);
		ft_rotate_b(stacks, head_b, 0);
		ft_printf("rr\n");
	}
	return ;
}

void	ft_rotate_a(t_stacks *stacks, t_stack *head_a, int print)
{
	t_stack	*tmp_node;

	tmp_node = head_a;
	stacks->head_a = head_a->next;
	while (head_a->next != NULL)
		head_a = head_a->next;
	head_a->next = tmp_node;
	tmp_node->next = NULL;
	if (print != 0)
		ft_printf("ra\n");
	return ;
}
