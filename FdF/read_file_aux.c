/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:20:03 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/12/13 14:20:06 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_rows(t_point **points, int rows)
{
	while (rows >= 0)
	{
		free(points[rows]);
		rows--;
	}
	free(points);
	return ;
}

int	fill_map(char *filename, t_map *map, t_enviro *enviro)
{
	int			fd;
	int			status;
	t_row_ctx	context;

	fd = open_file(filename);
	if (fd < 0)
		return (1);
	context.width = map->width;
	context.enviro = enviro;
	status = process_file(fd, map, &context);
	close(fd);
	return (status);
}

int	process_file(int fd, t_map *map, t_row_ctx *context)
{
	char	*line;
	int		x;

	x = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		context->x = x;
		if (handle_line(map, context, line, x) != 0)
		{
			free_rows(map->points, x);
			free(line);
			return (1);
		}
		free(line);
		x++;
	}
	return (0);
}

int	handle_line(t_map *map, t_row_ctx *context, char *line, int x)
{
	map->points[x] = parse_line(line, context->width, *context);
	if (!map->points[x])
		return (1);
	return (0);
}

t_point	*parse_line(char *line, int width, t_row_ctx context)
{
	t_point	*points_row; 
	char	**values;

	points_row = (t_point *)calloc(width, sizeof(t_point));
	if (!points_row)
	{
		perror("Failed to allocate memory for row");
		free(points_row);
		return (NULL);
	}
	values = ft_split(line, ' ');
	if (!values)
	{
		perror("Failed to parse the line");
		free(points_row);
		return (NULL);
	}
	if (fill_points_row(points_row, values, context) != 0)
	{
		free_values(values, width - 1);
		free(points_row);
		return (NULL);
	}
	free_values(values, width - 1);
	return (points_row);
}
