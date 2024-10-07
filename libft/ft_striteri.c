/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:16:42 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/03 18:43:31 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}

// void	my_function(unsigned int i, char *c)
// {
// 	if (*c >= 'a' && *c <= 'z')
// 		*c = *c - 32;
// 	else
// 	{
// 		i = 10;
// 	}
// 	return ;
// }

// int main(void)
// {
// 	char	str[] = "hello";
//     ft_striteri(str, &my_function);
// 	printf("El string transformado por f es %s\n", str);
// 	return (0);
// }
