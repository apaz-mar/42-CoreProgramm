/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:57:41 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/04/17 17:06:37 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

//int	main(void)
//{
//	int	a;
//	int	b;
//	int	*div;
//	int	*mod;

//	a = 100;
//	b = 3;
//	div = &a;
//	mod = &b;
//	printf("Numerador y denominador %d %d\n", a, b);
//	ft_div_mod(a, b, div, mod);
//	printf("Division y resto %d %d\n", *div, *mod);
//	return (0);
//}
