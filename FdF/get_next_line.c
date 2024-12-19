/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:39:46 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/07/14 15:59:39 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*read_into_buffer(int fd, char *tmp, char *buffer)
{
	int		bytes_read;
	char	*new_buffer;

	bytes_read = 1;
	new_buffer = NULL;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		tmp[bytes_read] = '\0';
		if (!buffer)
			buffer = ft_strdup("");
		new_buffer = ft_strjoin(buffer, tmp);
		free(buffer);
		if (!new_buffer)
			return (NULL);
		buffer = new_buffer;
		new_buffer = NULL;
		if (ft_strchr (tmp, '\n'))
			break ;
	}
	return (buffer);
}

static char	*extract_from_line(char *line)
{
	size_t	count;
	char	*buffer;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0')
		return (0);
	buffer = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*buffer == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	line[count + 1] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*tmp;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	line = read_into_buffer(fd, tmp, buffer);
	free(tmp);
	tmp = NULL;
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = extract_from_line(line);
	return (line);
}
