/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:04:21 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/06/09 16:12:02 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>
# include <limits.h>
# include <ctype.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
char	*ft_itoa_base(unsigned long long n, int size_base, 
			const char *base, const char *p);
int		ft_pr_char(va_list args);
int		ft_pr_hexa(va_list args, const char *p);
int		ft_pr_number(va_list args, const char *p);
int		ft_pr_pointer(va_list args, const char *p);
int		ft_pr_string(va_list args);
int		ft_printf(const char *format, ...);
size_t	ft_strlen(char *str);

#endif /* FT_PRINTF_H*/
