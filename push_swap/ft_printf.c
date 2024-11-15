/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:35:43 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/06/09 13:36:14 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_specifier(va_list args, const char *p)
{
	if (*p == 'c')
		return (ft_pr_char(args));
	else if (*p == 's')
		return (ft_pr_string(args));
	else if (*p == 'd' || *p == 'i' || *p == 'u')
		return (ft_pr_number(args, p));
	else if (*p == 'p')
		return (ft_pr_pointer(args, p));
	else if (*p == 'x' || *p == 'X')
		return (ft_pr_hexa(args, p));
	else if (*p == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	const char	*p;
	va_list		args;
	int			printed_len;

	p = format;
	printed_len = 0;
	va_start(args, format);
	while (*p != '\0')
	{
		if (*p == '%' && (*p + 1 != '\0'))
		{
			p++;
			printed_len += handle_specifier(args, p);
		}
		else
		{
			write(1, p, 1);
			printed_len++;
		}
		p++;
	}
	va_end(args);
	return (printed_len);
}

// int main(void)
// {
// 	//ft_printf("My function char is: %c\n", 'a');
// 	//ft_printf("My function string is: %s\n", "abcde");
// 	//ft_printf("My function string is: %s\n", (char *)NULL);
// 	ft_printf("My function digit is: %d\n", -42);
// 	//ft_printf("My function digit is: %u\n", -42);
// 	//ft_printf("My function hexadecimal is: %x.\n", -0x3abc);
// 	//ft_printf("My function hexadecimal is: %X.\n", -0x3ABC);
// 	//ft_printf("My function pointer address is: %p\n", (void *)0x3abc);
// 	//ft_printf(" %p %p ", (void *)LONG_MIN, (void *)LONG_MAX);
// 	//ft_printf("My function after percentage is: %%%c\n", 'a');
// 	//printf("Builtin printf: The char is %c\n", 'a');
// 	//printf("Builtin printf: The string is %s\n", "abcde");
// 	//printf("Builtin printf: The string is %s\n", (char *)NULL);
// 	printf("Builtin printf: The number is %d\n", -42);
// 	//printf("Builtin printf: The number is %u\n", -42);
// 	//printf("Builtin printf: The hexadecimal is %x.\n", -0x3abc);
// 	//printf("Builtin printf: The hexadecimal is %X.\n", -0x3ABC);
// 	//printf("Builtin printf: The pointer address is %p\n", (void *)0x3abc);
// 	//printf(" %p %p ", (void *)LONG_MIN, (void *)(LONG_MAX));
// 	//printf("Builtin printf: After percentage is %%%c\n", 'a');
//     //ft_printf("Myprintf: Hello %s! The number is %d\n", "world", 42);
//     //printf("Builtin printf: Hello %s! The number is %d\n", "world", 42);
// 	// ft_printf("My function pointer address is: %p\n", (void *)0x3abc);
// 	// ft_printf(" %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
// 	// printf("Builtin printf: %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
// 	return (0);
// }
