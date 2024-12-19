/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:54:07 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/12/10 14:54:09 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	calculate_centroid(t_enviro *enviro, double *cx, double *cy, double *cz)
{
	double sum_x;
	double	sum_y;
	double	sum_z;
	int 	i;
	int		j;
	int		total_points;

	sum_x = 0;
	sum_y = 0;
	sum_z = 0;
	i = 0;
	total_points = enviro->map->height * enviro->map->width;
	while (i < enviro->map->height)
	{
		j = 0;
		while (j < enviro->map->width)
		{
			sum_x = sum_x + enviro->map->points[i][j].x;
			sum_y = sum_y + enviro->map->points[i][j].y;
			sum_z = sum_z + enviro->map->points[i][j].z;
			j++;
		}
		i++;
	}
	*cx = sum_x / total_points;
	*cy = sum_y / total_points;
	*cz = sum_z / total_points;
	return ;
}

void	rotate_z(t_enviro *enviro, double angle)
{
	double		x;
	double		y;
	double	temp_x;
	double	temp_y;
	int		i;
	int		j;
	double	cx;
	double	cy;
	double	cz;

	calculate_centroid(enviro, &cx, &cy, &cz);
	i = 0;
	while (i < enviro->map->height)
	{
		j = 0;
		while (j < enviro->map->width)
		{
			x = enviro->map->points[i][j].x - cx;
			y = enviro->map->points[i][j].y - cy;
			temp_x = x * cos(angle) - y * sin(angle);
			temp_y = x * sin(angle) + y * cos(angle);
			enviro->map->points[i][j].x = temp_x + cx;
			enviro->map->points[i][j].y = temp_y + cy;
			j++;
		}
		i++;
	}
	return ;
}

void	rotate_y(t_enviro *enviro, double angle)
{
	int		x;
	int		z;
	double	temp_x;
	double	temp_z;
	int		i;
	int		j;

	i = 0;
	while (i < enviro->map->height)
	{
		j = 0;
		while (j < enviro->map->width)
		{
			x = enviro->map->points[i][j].x;
			z = enviro->map->points[i][j].z;
			temp_x = x * cos(angle) + z * sin(angle);
			temp_z = -x * sin(angle) + z * cos(angle);
			enviro->map->points[i][j].x = temp_x;
			enviro->map->points[i][j].z = temp_z;
			j++;
		}
		i++;
	}
	return ;
}

void	rotate_x(t_enviro *enviro, double angle)
{
	int		y;
	int		z;
	double	temp_y;
	double	temp_z;
	int		i;
	int		j;

	i = 0;
	while (i < enviro->map->height)
	{
		j = 0;
		while (j < enviro->map->width)
		{
			y = enviro->map->points[i][j].y;
			z = enviro->map->points[i][j].z;
			temp_y = y * cos(angle) - z * sin(angle);
			temp_z = y * sin(angle) + z * cos(angle);
			enviro->map->points[i][j].y = temp_y;
			enviro->map->points[i][j].z = temp_z;
			j++;
		}
		i++;
	}
	return ;
}
