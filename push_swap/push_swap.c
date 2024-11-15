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

void	fill_stack(int ac, char **av, t_stack **stack)
{
	int		i;
	t_stack	*new_node;
	int		*value;

	i = 1;
	value = NULL;
	new_node = NULL;
	while (i < ac)
	{
		fill_stack_aux(&value, av, i, &new_node);
		if (value == NULL)
		{
			ft_clearnodes(stack);
			exit (0);
		}
		ft_lstadd_back(stack, new_node);
		i++;
	}
	return ;
}

void	fill_stack_aux(int **value, char **av, int i, t_stack **new_node)
{
	long	num;

	num = ft_atol(av[i]);
	if (num > INT_MAX || num < INT_MIN)
	{
		ft_putstr_fd("Error\n", 2);
		*value = NULL;
		return ;
	}
	*value = (int *)malloc(sizeof(int));
	if (!*value)
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	**value = (int)num;
	*new_node = ft_lstnew((void *)(*value));
	if (!new_node)
	{
		ft_putstr_fd("Error\n", 2);
		free(*value);
		*value = NULL;
		return ;
	}
	return ;
}

// void	print_stacks(t_stacks *stacks)
// {
// 	t_stack	*tmp_a = stacks->head_a;
// 	t_stack	*tmp_b = stacks->head_b;

// 	printf("Stack A: \n");
// 	if (tmp_a == NULL)
// 		printf("Empty");
// 	while (tmp_a)
// 	{
// 		printf("%d \n", *(tmp_a->data));  // Assuming data is stored in the node
// 		tmp_a = tmp_a->next;
// 	}
// 	printf("Stack B: \n");
// 	if (tmp_b == NULL)
// 		printf("Empty");
// 	while (tmp_b)
// 	{
// 		printf("%d \n", *(tmp_b->data));  // Assuming data is stored in the node
// 		tmp_b = tmp_b->next;
// 	}
// }

void	sorting(t_stacks *stacks)
{
	if (check_list_order(stacks) == 1)
		return ;
	if (ft_listsize(stacks->head_a) == 2)
		sort_two(stacks);
	else if (ft_listsize(stacks->head_a) == 3)
		sort_three(stacks, 1); 
	else if (ft_listsize(stacks->head_a) == 4)
		sort_four(stacks);
	ft_push(stacks, 'b');
	ft_push(stacks, 'b');
	move_cheapest(stacks);
	sort_three(stacks, 0);
	move_stack_a(stacks);
	return ;
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	input_error(ac, av);
	stacks.head_a = NULL;
	stacks.head_b = NULL;
	fill_stack(ac, av, &stacks.head_a);
	check_for_doubles(stacks.head_a);
	sorting(&stacks);
	free_for_all(&stacks);
	return (0);
}
