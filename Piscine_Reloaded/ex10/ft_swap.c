/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:26:07 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/04/17 16:55:51 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = 0;
	c = *a;
	*a = *b;
	*b = c;
}

//int	main(void)
//{
//	int	*a;
//	int	*b;
//	int	c;
//	int	d;

//	c = 2;
//	d = 4;
//	a = &c;
//	b = &d;
//	printf("Del derecho %d %d\n", *a, *b);
//	ft_swap(a, b);
//	printf("Del reves %d %d\n", *a, *b);
//	return (0);
//}
