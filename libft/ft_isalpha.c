/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:19:12 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/04/22 18:28:10 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || ((c >= 97) && (c <= 122)))
		return (1);
	else
		return (0);
}
//
//int	main(void)
// {
// 	int	c;
// 	int	i;

// 	c = '?';
// 	i = ft_isalpha(c);
// 	printf("Uno si es del alfabeto, 0 si no %d\n", i);
// 	return (0);
// }
