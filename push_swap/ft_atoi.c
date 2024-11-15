/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:27:31 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/07 17:20:25 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_div_mod(const char *nptr, int i, long int num)
{
	while (nptr[i] != '\0')
	{
		if (nptr[i] >= 48 && nptr[i] <= 57)
		{
			num = (num * 10) + (nptr[i] - '0');
			i++;
		}
		else
			break ;
	}
	return (num);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	long int	num;
	int			neg;

	i = 0;
	num = 0;
	neg = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	if (nptr[i] > '9' || nptr[i] < '0')
		return (0);
	num = ft_div_mod(nptr, i, num);
	if (num * neg > INT_MAX || num * neg < INT_MIN)
		return (0);
	else
		return ((int)(num * neg));
}

void	print_error_and_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	count_a(int i, int len, t_stacks *stacks)
{
	if (len % 2 == 0)
	{
		if (i + 1 > len / 2)
			stacks->op_count->rra = (len - i);
		else
			stacks->op_count->ra = i;
	}
	else
	{
		if (i > len / 2)
			stacks->op_count->rra = (len - i);
		else
			stacks->op_count->ra = i;
	}
	return ;
}

// int	main(void) 
// {
// 	//char *str = "   2147483647";
// 	//char	*str = "0";
// 	char *str = "546:5";
// 	int result = ft_atoi(str);
// 	printf("Result: %d\n", result);
// 	printf("Result de la built-in function: %d\n", atoi(str));
// 	// printf("El minimo int es: %d\n", INT_MIN);
// 	return (0);
// }
