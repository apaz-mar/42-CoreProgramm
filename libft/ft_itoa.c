/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:25:48 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/10 17:10:04 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_i_zero(void)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*ft_i_neg(int n, int counter)
{
	char	*str;

	str = (char *)malloc((counter + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '-';
	str[counter + 1] = '\0';
	while (counter > 0)
	{
		str[counter] = '0' - (n % 10);
		n = n / 10;
		counter--;
	}
	return (str);
}

static char	*ft_i_pos(int n, int counter)
{
	char	*str;

	str = (char *)malloc((counter + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[counter] = '\0';
	while (counter > 0)
	{
		str[counter - 1] = (n % 10) + '0';
		n = n / 10;
		counter--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				counter;
	int				temp;

	temp = n;
	counter = 0;
	while (temp != 0)
	{
		temp = temp / 10;
		counter++;
	}
	if (n == 0)
		str = ft_i_zero();
	if (n < 0)
		str = ft_i_neg(n, counter);
	else if (n > 0)
		str = ft_i_pos(n, counter);
	return (str);
}

// int main(void)
// {
// 	//int n = -1350;
// 	int n = -2147483648;
// 	char *str = ft_itoa(n);
// 	printf("El entero como string es %s\n", str);
// 	//printf("El entero minimo es %d", INT_MIN);
// 	// free(str);
// 	return (0);
// }
