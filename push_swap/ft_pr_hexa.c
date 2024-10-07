/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:56:06 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/06/09 16:25:16 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pr_hexa(va_list args, const char *p)
{
	int		i;
	char	*base;
	char	*i_as_c;
	int		len;

	i = va_arg(args, unsigned int);
	i_as_c = NULL;
	if (*p == 'x')
		base = "0123456789abcdef";
	else if (*p == 'X')
		base = "0123456789ABCDEF";
	i_as_c = ft_itoa_base(i, 16, base, p);
	len = ft_strlen(i_as_c);
	write(1, i_as_c, len);
	free(i_as_c);
	return (len);
}

int	ft_pr_pointer(va_list args, const char *p)
{
	unsigned long long	ptr_value;
	void				*ptr;
	char				*base;
	char				*i_as_c;
	int					len;

	i_as_c = NULL;
	ptr = va_arg(args, void *);
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ptr_value = (unsigned long long)ptr;
	base = "0123456789abcdef";
	i_as_c = ft_itoa_base(ptr_value, ft_strlen(base), base, p);
	if (!i_as_c)
		return (0);
	write(1, "0x", 2);
	len = ft_strlen(i_as_c);
	write(1, i_as_c, len);
	free(i_as_c);
	return (2 + len);
}
