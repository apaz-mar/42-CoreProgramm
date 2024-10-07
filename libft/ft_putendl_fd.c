/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:36:10 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/05/03 19:38:35 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
	return ;
}

// int main(void)
// {
//     int fd;
//     char s[] = "hello";
//     int i;

//     fd = 0;
//     i = 0;
//     FILE *file = fopen("example.txt", "w");
//     if (fd == -1)
//         return (1);
//     fd = fileno(file);
//     ft_putendl_fd(s, fd);
//     fclose(file);
//     file = fopen("example.txt", "r");
//     printf("El contenido del file es: ");
//     while ((s[i] = fgetc(file)) != EOF)
//     {    
//         putchar(s[i]);
//         i++;
//     }
//     fclose(file);
//     return (0);
// }
