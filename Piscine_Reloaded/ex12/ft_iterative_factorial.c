/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:51:05 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/06 12:45:55 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	n;

	n = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		n = n * nb;
		nb--;
	}
	return (n);
}

//int	main(void)
//{
//	int	nb;
//	int	factorial;
//
//	nb = 0;
//	factorial = ft_iterative_factorial(nb);
//	printf("El factorial es %d\n", factorial);
//	return (0);
//}
