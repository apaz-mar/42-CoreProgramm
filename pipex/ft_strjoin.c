/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:03:14 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/04/25 20:14:31 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char *s1, char *s2)
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

// int	main(void)
// {
// 	char	*s1 = "a";
// 	char    *s2 = "";
// 	char	*sj = ft_strjoin(s1, s2);
// 	printf("El string concatenado es %s\n", sj);
// 	return (0);
// }
