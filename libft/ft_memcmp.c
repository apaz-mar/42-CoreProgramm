/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:34:19 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/07 17:51:10 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*ptr_s1;
	const unsigned char		*ptr_s2;
	size_t					i;

	i = 0;
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (ptr_s1[i] > ptr_s2[i])
			return (1);
		else if (ptr_s1[i] < ptr_s2[i])
			return (-1);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	s1[] = "abcd";
// 	char	s2[] = "abcd";
// 	size_t	n = 0;
// 	int	result = ft_memcmp(s1, s2, n);
// 	printf("La comparacion es %d\n", result);
// 	return (0);
// }
