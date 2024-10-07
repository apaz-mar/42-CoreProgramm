/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:42:18 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/06/09 13:04:40 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pr_number(va_list args, const char *p)
{
	char	*i_as_c;
	int		len;

	i_as_c = NULL;
	if (*p == 'u')
		i_as_c = ft_itoa_base(va_arg(args, unsigned int), 10, "0123456789", p);
	else if (*p == 'd' || *p == 'i')
		i_as_c = ft_itoa(va_arg(args, int));
	if (!i_as_c)
		return (-1);
	len = ft_strlen(i_as_c);
	write(1, i_as_c, len);
	free(i_as_c);
	return (len);
}
