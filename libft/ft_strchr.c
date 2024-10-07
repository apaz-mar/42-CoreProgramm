/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:24:49 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/04/22 20:44:23 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(s));
	return (NULL);
}

// int	main(void)
// {
// 	const char	s[] = "abcde";
// 	int		c;
//     char    *i;

// 	c = '\0';
// 	i = ft_strchr(s, c);
// 	printf("El pointer nuevo es: %s\n", i);
// 	return (0);
// }
