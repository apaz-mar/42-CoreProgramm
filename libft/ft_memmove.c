/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:58:32 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/04/25 19:17:21 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;

	i = 0;
	if ((dest == NULL && src == NULL) && n > 0)
		return ((void *) NULL);
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char	dest[] = "abcde";
// 	//char	src[] = "xyz";
// 	size_t	n;

// 	n = 2;
// 	//ft_memmove(dest, src, n);
// 	//ft_memmove(dest + 3, dest + 1, n);
// 	//printf("La posicion es %s\n", dest);
// 	printf("la builtin es %s\n", (char *)memmove(dest + 3, dest + 1, n));
// 	//printf("la builtin es %s\n", (char *)memmove(dest, src, n));
// 	return (0);
// }
