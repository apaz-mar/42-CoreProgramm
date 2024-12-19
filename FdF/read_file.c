/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:40:22 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/12/10 14:40:24 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	open_file(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	return (fd);
}

int	count_map_dimensions(int fd, t_map *map)
{
	char	*line;

	map->height = 0;
	map->width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		if (map->width == 0)
			map->width = count_columns(line);
		map->height++;
		free(line);
	}
	return (map->width == 0 || map->height == 0);
}

int	count_columns(char *line)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (line[i] != 0)
	{
		while (line[i] == ' ')
			i++;
		if (line[i] != '\0')
		{
			count++;
			while (line[i] != ' ' && line[i] != '\0')
				i++;
		}
	}
	return (count);
}

int	allocate_map(t_map *map)
{
	map->points = (t_point **)malloc(sizeof(t_point *) * map->height);
	if (!map->points)
	{
		perror("Failed to allocate memory for points array");
		free(map->points);
		return (1);
	}
	return (0);
}

int	parse_file(char *filename, t_map *map, t_enviro *enviro)
{
	int		fd;

	fd = open_file(filename);
	if (fd < 0)
		return (1);
	if (count_map_dimensions(fd, map))
	{
		fprintf(stderr, "Error: Map file is empty or invalid\n");
		close(fd);
		return (1);
	}
	close(fd);
	if (allocate_map(map))
		return (1);
	return (fill_map(filename, map, enviro));
}
