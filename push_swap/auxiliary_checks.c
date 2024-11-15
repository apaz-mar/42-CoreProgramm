/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:16:01 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/10/15 16:16:05 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_list_order(t_stacks *stacks)
{
	t_stack		*head_a;
	int			num;
	int			i;

	i = 1;
	head_a = stacks->head_a;
	num = *(head_a->data);
	while (i < ft_listsize(stacks->head_a))
	{
		head_a = head_a->next;
		if (num > *(head_a->data))
			return (0);
		num = *(head_a->data);
		i++;
	}
	ft_clearnodes(&stacks->head_a);
	exit (0);
}

void	ft_clearnodes(t_stack **lst)
{
	t_stack	*ptr;

	while (*lst != NULL)
	{
		ptr = *lst;
		*lst = ptr->next;
		if (ptr->data)
			free(ptr->data);
		free(ptr);
	}
	return ;
}

void	free_for_all(t_stacks *stacks)
{
	ft_clearnodes(&stacks->head_a);
	ft_clearnodes(&stacks->head_b);
	free(stacks->values);
	free(stacks->op_count);
	free(stacks->cheap);
	return ;
}

int	ft_listsize(t_stack *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

t_stack	*ft_lstnew(void *data)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}
