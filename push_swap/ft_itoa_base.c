/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:25:48 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/06/09 16:22:42 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_i_zero_base(const char *base)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = base[0];
	str[1] = '\0';
	return (str);
}

static char	*ft_i_pos_base(unsigned long long n, int counter, 
		int size_base, const char *base)
{
	char	*str;

	str = (char *)malloc((counter + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[counter] = '\0';
	while (counter > 0)
	{
		str[counter - 1] = base[n % size_base];
		n = n / size_base;
		counter--;
	}
	return (str);
}

char	*ft_itoa_base(unsigned long long n, int size_base, 
		const char *base, const char *p)
{
	unsigned long long	temp;
	char				*str;
	int					counter;

	str = NULL;
	if (*p == 'x' || *p == 'X')
		n = (unsigned int)n;
	temp = n;
	counter = 0;
	while (temp != 0)
	{
		temp = temp / size_base;
		counter++;
	}
	if (n == 0)
		str = ft_i_zero_base(base);
	else if (n > 0)
		str = ft_i_pos_base(n, counter, size_base, base);
	return (str);
}
