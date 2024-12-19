/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enviro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:58:38 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/12/10 14:58:41 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_enviro(t_enviro *enviro, char *filename)
{
	init_enviro_aux(enviro);
	enviro->map = malloc(sizeof(t_map));
	if (!enviro->map)
	{
		perror("Error allocating memory for the map");
		destroy_mlx(enviro);
	}
	enviro->max_z = INT_MIN;
	enviro->min_z = INT_MAX;
	if (parse_file(filename, enviro->map, enviro) != 0)
	{
		ft_printf("Error: Failed to parse the file %s\n", filename);
		destroy_mlx(enviro);
	}
	enviro->ink = malloc(sizeof(t_color));
	if (!enviro->ink)
	{
		perror("Error allocating memory for ink");
		destroy_mlx(enviro);
	}
	enviro->ink->color1 = 0x0000FF;
	enviro->ink->color2 = 0xFF0000;
	return ;
}

void	init_enviro_aux(t_enviro *enviro)
{
	if (!enviro)
	{
		ft_printf("Error: Failed enviro structure.\n");
		exit(1);
	}
	enviro->scale = 5;
	enviro->x_offset = WIDTH / 2.5;
	enviro->y_offset = HEIGHT / 5;
	enviro->mlx_ptr = mlx_init();
	check_and_exit(!enviro->mlx_ptr, enviro,
		"Error: Failed to initialize MinilibX.\n");
	enviro->win_ptr = mlx_new_window(enviro->mlx_ptr, WIDTH, HEIGHT, "FDF");
	check_and_exit(!enviro->win_ptr, enviro,
		"Error: Failed to create a new window.\n");
	enviro->img_ptr = mlx_new_image(enviro->mlx_ptr, WIDTH, HEIGHT);
	check_and_exit(!enviro->img_ptr, enviro,
		"Error: Failed to create a new image.\n");
	enviro->img_data = mlx_get_data_addr(enviro->img_ptr,
			&enviro->bpp, &enviro->size_line, &enviro->endian);
	check_and_exit(!enviro->img_data, enviro,
		"Error: Failed to get image data address.\n");
	return ;
}

void	check_and_exit(int condition, t_enviro *enviro, char *error_message)
{
	if (condition)
	{
		perror(error_message);
		destroy_mlx(enviro);
	}
	return ;
}

void	destroy_mlx(t_enviro *enviro)
{
	if (enviro->map)
		free(enviro->map);
	if (enviro->ink)
		free(enviro->ink);
	mlx_destroy_image(enviro->mlx_ptr, enviro->img_ptr);
	mlx_destroy_window(enviro->mlx_ptr, enviro->win_ptr);
	mlx_destroy_display(enviro->mlx_ptr);
	exit(1);
}
