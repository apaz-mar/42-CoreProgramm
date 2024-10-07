/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:52:14 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/04/22 20:18:19 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (len_src + size);
	if (size > 0)
	{
		while ((src[i] != '\0') && (i < size - len_dst - 1))
		{
			dst[len_dst + i] = src[i];
			i++;
		}
		if (len_dst < size)
			dst[len_dst + i] = '\0';
	}
	return (len_dst + ft_strlen(src));
}

// int	main(void)
// {
// 	char	src[] = "abcdef";
// 	size_t		i;
// 	size_t		size;
//     char    dst[10] = {'h', 'h', 'h', '\0'};

// 	size = 11;
// 	i = ft_strlcat(dst, src, size);
// 	printf("El tamano de los string concatenados es: %zu\n", i);
// 	printf("El string concatenado es: %s\n", dst);
// 	//printf("El tamano con la built-in es: %d\n", strlcat(dst, src, size));
// 	printf("El ultimo caracter en dst es: %c\n", dst[9]);
// 	return (0);
// }
