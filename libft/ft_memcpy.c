/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:32:08 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/10 16:52:41 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*ptr_src;
	unsigned char		*ptr_dest;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	ptr_src = (unsigned char *)src;
	ptr_dest = (unsigned char *)dest;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	s[] = "abcdc";
// 	char	d[5];
// 	size_t	n = 3;
// 	ft_memcpy(d, s, n);
// 	printf("El string destino es %s\n", d);
// 	return (0);
// }
