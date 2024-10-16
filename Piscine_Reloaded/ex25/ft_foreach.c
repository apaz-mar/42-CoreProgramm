/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:55:52 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/05 12:11:59 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
	return ;
}

// void    my_function(int n)
// {
//     n = n * 2;
//     return ;
// }

// int     main(void)
// {
//     int *tab = malloc(10 * sizeof(int));
//     int     length = 10;
//     int     i = 0;
//     for (int i = 0; i < 10; i++)
//     {
//         tab[i] = i;
//     }
//     ft_foreach(tab, length, &my_function);
//     while (i < length)
//     {
//         printf("El array trasformado for f es %d\n", tab[i]);
//         i++;
//     }
//     free(tab);
//     return (0);
// }
