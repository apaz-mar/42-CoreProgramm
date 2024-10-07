/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:39:46 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/06/12 19:39:53 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "get_next_line.h"

static int  read_into_buffer(int fd, char *buffer)
{
	char    tmp[BUFFER_SIZE + 1];
	int     bytes_read;
	char    *new_buffer;

	bytes_read = read(fd, tmp, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	tmp[bytes_read] = '\0';
	if (*buffer != '\0')
	{
		new_buffer = ft_strjoin(*buffer, tmp);
		free(*buffer)
		*buffer = new_buffer;
	}
	else
		*buffer = strdup(tmp);
	return (bytes_read);
}

static int 	find_newline(int fd, char *buffer)
{
	int	pos_nl;

	pos_nl = 0;
	while (*buffer != '\0')
	{
		if (ft_strchr(buffer, '\n') == '\n')
			break ;
		buffer++;
		pos_nl++;
	}
	return (pos_nl);
}

static char	*get_line_from_buffer(int fd, char *buffer)
{
	char	*line;
	int		pos_nl;

	if (*buffer == NULL)
		return (NULL);
	pos_nl = 0;
	while (find_newline(fd, buffer) == NULL)
	{
		pos_nl++;
		*line = *buffer;
	}
	line[pos_nl] = '\n';
	return (line);
}

char    *get_next_line(int fd)
{
	static char		*buffer;
	int				bytes_read;
	char			*line;

	buffer = NULL;
	line = NULL;
	bytes_read = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (find_newline(fd, buffer) == NULL))
	{
		bytes_read = read_into_buffer(fd, &buffer);
		if (bytes_read <= 0)
			break ;
	}
	line = get_line_from_buffer(fd, &buffer);
	free(buffer);
	return (line);
}

int	main()
{
	fd = fopen(gnl.txt);
	BUFFER_SIZE = 42;
	get_next_line(fd);
	fclose(fd);
	return (0);
}