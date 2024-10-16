/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:31:23 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/06 12:54:19 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	j;
	int	count;

	count = 0;
	j = 0;
	while (tab[j] != NULL)
	{
		if (f(tab[j]) == 1)
			count++;
		j++;
	}
	return (count);
}
