/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:40:43 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/03 19:44:43 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_recursive(int n, int fd)
{
	char	digit;

	if (n == 0)
		return ;
	ft_putnbr_recursive(n / 10, fd);
	digit = '0' + (n % 10);
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	if (n == INT_MIN)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = n * (-1);
		}
		ft_putnbr_recursive(n, fd);
	}
}

// int main(void)
// {
//     int fd;
//     //int n = 2147483648;
// 	int n = 0;
//     int i;
// 	int	c;

//     fd = 0;
//     i = 0;
//     FILE *file = fopen("example.txt", "w");
//     if (fd == -1)
//         return (1);
//     fd = fileno(file);
//     ft_putnbr_fd(n, fd);
//     fclose(file);
//     file = fopen("example.txt", "r");
// 	while ((c = fgetc(file)) != EOF)
// 	    printf("%c", c);
// 	fclose(file);
//     return (0);
// }
