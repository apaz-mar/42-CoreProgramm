/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:01:33 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/04/21 14:52:15 by apaz-mar         ###   ########.fr       */
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

int	*ft_range(int min, int max)
{
	int	size;
	int	*range;
	int	i;

	i = 0;
	size = max - min + 1;
	range = (int *)malloc((size + 1) * (sizeof(int)));
	if (min >= max)
	{
		range = NULL;
		return (range);
	}
	while (min + i < max) 
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
//
//int	main(void)
//{
//	int	min;
//	int	max;
//	int	*range;
//	int	i;
//	int	size;

//	i = 0;
//	min = 3;
//	max = 5;
//	size = max - min + 1;
//	range = (int *)malloc((size + 1) * (sizeof(int)));
//	range = ft_range(min, max);
//	while (range [i] != '\0')
//	{
//		printf("Los enteros en el rango son %d\n", range[i]);
//		i++;
//	}
//	free(range);
//	return (0);
//}
