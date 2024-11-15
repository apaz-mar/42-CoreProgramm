/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:25:37 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/07/15 18:25:45 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*line;
	//int fd = open("gnl1.txt", O_RDONLY);
	//int fd = open("gnl2.txt", O_RDONLY);
	int fd = open("gnl3.txt", O_RDONLY);
	// //int fd = open("gnl4.txt", O_RDONLY);
	// //int fd = open("gnl5.txt", O_RDONLY);
	// //int fd = open("gnl6.txt", O_RDONLY);
	// //int fd = open("gnl7.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("error abriendo el archivo");
	 	return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	//while ((line = get_next_line(0)) != NULL)
	{
		printf("%s", line);
        free(line);
	}
	close(fd);
	return (0);
}

