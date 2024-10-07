/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:40:34 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/04/24 19:12:00 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (little[j] != '\0' && big[i + j] != '\0' && (i + j) < len)
			{
				if (big[i + j] == little[j])
					j++;
				else
					break ;
			}
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*big;
// 	char	*little;
// 	int		len;
// 	char	*c;

// 	big = "abcde";
// 	little = "cde";
// 	len = 5;
// 	c = ft_strnstr(big, little, len);
// 	printf("el primer caracter donde aparece es: %s\n", c);
// 	return (0);
// }
