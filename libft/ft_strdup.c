/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:19:03 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/04/21 12:59:14 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sdup;
	int		size;
	int		i;

	i = 0;
	size = 0;
	size = ft_strlen(s);
	sdup = (char *)malloc((size + 1) * sizeof(char));
	if (sdup == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		sdup[i] = s[i];
		i++;
	}
	sdup[i] = '\0';
	return (sdup);
}

// int	main(void)
// {
// 	char	*s;
// 	char	*sdup;

// 	s = "hello";
// 	sdup = ft_strdup(s);
// 	printf("El duplicado de %s es %s\n", s, sdup);
// 	return (0);
// }
