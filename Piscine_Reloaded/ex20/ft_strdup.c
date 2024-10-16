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

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*sdup;
	int		size;
	int		i;

	i = 0;
	size = 0;
	size = ft_strlen(src);
	sdup = (char *)malloc(size + 1);
	if (sdup == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		sdup[i] = src[i];
		i++;
	}
	return (sdup);
}

//int	main(void)
//{
//	char	*src;
//	char	*sdup;

//	src = "hello";
//	sdup = ft_strdup(src);
//	printf("El duplicado de %s es %s\n", src, sdup);
//	return (0);
//}
