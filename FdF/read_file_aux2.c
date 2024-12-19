/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_aux2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:05:33 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/12/13 15:05:35 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fill_points_row(t_point *points_row, char **values,
		t_row_ctx context)
{
	int	j;

	j = 0;
	while (j < context.width)
	{
		if (!values[j])
		{
			perror("Invalid or incomplete values in line");
			return (1);
		}
		points_row[j].x = j;
		points_row[j].y = context.x;
		points_row[j].z = ft_atoi(values[j]);
		if (points_row[j].z > context.enviro->max_z)
			context.enviro->max_z = points_row[j].z;
		if (points_row[j].z < context.enviro->min_z)
			context.enviro->min_z = points_row[j].z;
		j++;
	}
	return (0);
}

void	free_values(char **values, int j)
{
	while (j >= 0)
	{
		free(values[j]);
		j--;
	}
	free(values);
	return ;
}
