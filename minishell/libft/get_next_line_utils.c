/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshapkin <lshapkin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:12:47 by lshapkin          #+#    #+#             */
/*   Updated: 2024/08/09 14:51:07 by lshapkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_append(char *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = 0;
	while (s2[len2])
		len2++;
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i = -1;
	while (s2[++i] && s2[i - 1] != '\n')
	{
		str[len1] = s2[i];
		len1++;
	}
	str[len1] = '\0';
	free (s1);
	return (str);
}
