/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:27:09 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/04/25 20:01:09 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	len_s;

	len_s = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	if (s[0] == '\0' && start > 0)
		len = 0;
	substr = (char *)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while ((s[start + i] != '\0') && (i < len))
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// int	main(void)
// {
// 	char	*s = "";
// 	int	start = 1;
// 	int	len = 1;
// 	char	*substr = ft_substr(s, start, len);
// 	printf("El substring es %s\n", substr);
// 	return (0);
// }
