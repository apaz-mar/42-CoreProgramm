/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:45:28 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/03 19:20:44 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}

// int main(void)
// {
//     int fd;
//     char c;

//     fd = 0;
//     FILE *file = fopen("example.txt", "w");
//     if (fd == -1)
//         return (1);
//     fd = fileno(file);
//     ft_putchar_fd('A', fd);
//     fclose(file);
//     file = fopen("example.txt", "r");
//     printf("El contenido del file es: ");
//     while ((c = fgetc(file)) != EOF)
//         putchar(c);
//     fclose(file);
//     return (0);
// }
