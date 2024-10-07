/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:15:22 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/10 17:09:06 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	ft_is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (true);
		i++;
	}
	return (false);
}

static char	*ft_copy_trimmed(char const *s1, char *sj, size_t i, size_t j)
{
	size_t	k;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	k = 0;
	while (k < len_s1 - i - j)
	{
		sj[k] = s1[i + k];
		k++;
	}
	sj[k] = '\0';
	return (sj);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*sj;
	size_t	i;
	size_t	j;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	i = 0;
	j = 0;
	while (s1[i] != '\0' && ft_is_in_set(s1[i], set))
		i++;
	if (i == len_s1)
	{
		sj = (char *)malloc(1 * sizeof(char));
		return (ft_copy_trimmed(s1, sj, i, j));
	}
	while (s1[len_s1 - j - 1] != '\0' && ft_is_in_set(s1[len_s1 - j -1], set))
		j++;
	if (i > len_s1 - j)
		return (NULL);
	sj = (char *)malloc((len_s1 - i - j + 1) * sizeof(char));
	if (sj == NULL)
		return (NULL);
	return (ft_copy_trimmed(s1, sj, i, j));
}

// int	main(void)
// {
// 	char const	*s1 = "hhhhhh";
// 	char const	*set = "  h";
// 	char	*sj = ft_strtrim(s1, set);
// 	printf("El string recortado es %s\n", sj);
// 	free(sj);
// 	return (0);
// }
