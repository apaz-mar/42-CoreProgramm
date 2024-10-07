/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:41:30 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/03 18:15:46 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char	my_function(unsigned int i, char c)
// {
// 	if (c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	else
// 	{
// 		i = 10;
// 		return (c);
// 	}
// }

// int main(void)
// {
// 	char	*str = "";
// 	char	*transf = ft_strmapi(str, &my_function);
// 	printf("El string transformado por f es %s\n", transf);
// 	return (0);
// }
