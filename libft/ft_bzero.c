/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:05:04 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/07 17:47:31 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char		*ptr;
	size_t				i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
	return ;
}

// int	main(void)
// {
// 	char	*s;
// 	size_t	n;
// 	size_t	i = 0;
// 	size_t len = 5;

// 	n = 6;
// 	s = (char *)malloc((len + 1) * sizeof(char));
// 	while (i < len)
// 	{
// 		s[i] = 'a' + i;
// 		i++;
// 	}
// 	s[i] = '\0';
// 	printf("El string original es %s\n", s);
// 	ft_bzero(s, n);
// 	i = 0;
// 	while (i < n)
// 	{
// 		s++;
// 		i++;
// 	}
// 	printf("El string transformado es %s\n", s);
// 	free(s);
// 	return (0);
// }
