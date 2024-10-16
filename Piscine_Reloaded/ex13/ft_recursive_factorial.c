/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:13:46 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/04/23 19:25:42 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
		return (0);
	if (nb > 0)
	{
		result = nb * ft_recursive_factorial(nb - 1);
		nb--;
	}
	return (result);
}

//int	main(void)
//{
//	int	nb;
//	int	factorial;

//	nb = 5;
//	factorial = 0;
//	factorial = ft_recursive_factorial(nb);
//	printf("The factorial of %d is %d\n", nb, factorial);
//	return (0);
//}
