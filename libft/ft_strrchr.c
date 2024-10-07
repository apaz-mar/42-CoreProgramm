/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:45:05 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/04/22 21:02:41 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			j = i;
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(&s[i]));
	if (s[j] == (unsigned char)c)
		return ((char *)(&s[j]));
	else
		return (NULL);
}

// int	main(void)
// {
// 	char	s[] = "abcdc";
// 	int		c;
//     char    *i;

// 	c = 'c';
// 	i = ft_strrchr(s, c);
// 	printf("El pointer desde la ultima ocurrencia de c es: %s\n", i);
// 	return (0);
// }
