/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:24:48 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/09 18:44:12 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;
	char	*ini_ptr;
	size_t	i;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (size * nmemb > SIZE_MAX)
		return (NULL);
	total_size = size * nmemb;
	ptr = (void *)malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ini_ptr = (char *)ptr;
	i = 0;
	while (i < nmemb * size)
	{
		ini_ptr[i] = 0;
		i++;
	}
	return (ptr);
}

// int main(void)
// {
// 	size_t nmemb = 0;
// 	size_t size = 10;
// 	size_t i = 0;
// 	char *ptr = ft_calloc(nmemb, size);
// 	while (i < nmemb * size)
// 	{
// 		printf("El array inicializado es %d\n", ptr[i]);
// 		i++;
// 	}
// 	free(ptr);
// 	return (0);
// }
