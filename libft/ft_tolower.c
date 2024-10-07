/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:36:20 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/04/24 18:36:23 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c == EOF || (c >= 0 && c <= 255))
	{
		if ((c >= 65) && (c <= 90))
			c = c + 32;
	}
	return (c);
}

// int	main(void)
// {
// 	int	c;
// 	int	i;

// 	c = 'a';
// 	i = ft_tolower(c);
// 	printf("Convertido en minuscula %d\n", i);
// 	return (0);
// }
