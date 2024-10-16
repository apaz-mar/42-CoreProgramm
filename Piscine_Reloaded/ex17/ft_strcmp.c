/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:05:35 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/04/19 18:40:49 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		if (s1[i] > s2[i])
		{
			i = 1;
			return (i);
		}
		if (s1[i] < s2[i])
		{
			i = -1;
			return (-1);
		}
	}
	return (0);
}
//
//int	main(void)
//{
//	char	*s1;
//	char	*s2;
//	int		i;

//	s1 = "abc";
//	s2 = "ab";
//	i = ft_strcmp(s1, s2);
//	printf("La comparacion es %d\n", i);
//	return (0);
//}
