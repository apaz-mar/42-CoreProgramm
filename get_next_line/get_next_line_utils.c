/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:40:07 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/06/12 19:40:10 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sj;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	sj = (char *)malloc(len_s1 + len_s2 + 1);
	if (sj == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		sj[i] = s1[i];
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		sj[i] = s2[i - len_s1];
		i++;
	}
	sj[i] = '\0';
	return (sj);
}

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