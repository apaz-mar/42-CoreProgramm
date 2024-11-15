/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_checks2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:53:05 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/10/19 19:53:07 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_error(int ac, char **av)
{
	if (ac == 1)
		exit(0);
	check_integers(ac, av);
	return ;
}

void	check_integers(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '\0')
			print_error_and_exit();
		while (j < (int)ft_strlen(av[i]))
		{
			if (!ft_isdigit(av[i][j]))
			{
				if (j == 0 && ft_strlen(av[i]) != 1 && \
					(av[i][j] == '-' || av[i][j] == '+'))
				{
					j++;
					continue ;
				}
				print_error_and_exit();
			}
			j++;
		}
		i++;
	}
}

void	check_for_doubles(t_stack *head_a)
{
	t_stack		*tmp;
	t_stack		*ptr;
	int			num;

	ptr = head_a;
	while (ptr != NULL)
	{
		tmp = ptr;
		num = *(tmp->data);
		tmp = tmp->next;
		while (tmp != NULL)
		{
			if (num == *(tmp->data))
			{
				ft_putstr_fd("Error\n", 2);
				ft_clearnodes(&head_a);
				exit(0);
			}
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
	return ;
}
