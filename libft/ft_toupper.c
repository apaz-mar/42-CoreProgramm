/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:07:08 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/04/24 18:35:27 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c == EOF || (c >= 0 && c <= 255))
	{
		if ((c >= 97) && (c <= 122))
			c = c - 32;
	}
	return (c);
}

// int	main(void)
// {
// 	int	c;
// 	int	i;

// 	c = 'a';
// 	i = ft_toupper(c);
// 	printf("Convertido en mayuscula %d\n", i);
// 	return (0);
// }
