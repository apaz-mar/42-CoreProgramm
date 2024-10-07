/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:16:09 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/04/24 18:28:36 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*ptr;
	size_t					i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	s[] = "abcde";
// 	int		c = 100;
// 	size_t	n = 5;
// 	char *result = ft_memchr(s, c, n);
// 	printf("El caracter '%c' se encuentra en la posicion %c\n", c, *result);
// 	return (0);
// }
