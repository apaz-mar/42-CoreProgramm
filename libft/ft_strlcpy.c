/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:09:43 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/04/22 19:39:08 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while ((src[i] != '\0') && (i < size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

// int	main(void)
// {
// 	char	src[] = "abcde";
// 	size_t		i;
// 	int		size;
//     char    dst[3];

// 	size = 3;
// 	i = ft_strlcpy(dst, src, size);
// 	printf("El string destino es %s\n", dst);
// 	printf("El ultimo character de dst es %c\n", dst[2]);
// 	printf("El resultado de strlcpy es el tamano de src %zu\n", i);
// 	return (0);
// }
