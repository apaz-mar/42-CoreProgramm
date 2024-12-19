/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:24:27 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/12/10 14:24:29 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_enviro	*enviro;

	if (ac != 2)
	{
		ft_printf("Error. Usage: ./fdf <file.fdf>\n");
		return (1);
	}
	enviro = malloc(sizeof(t_enviro));
	if (!enviro)
	{
		ft_printf("Error: Memory allocation for enviro failed.\n");
		free(enviro);
		return (1);
	}
	init_enviro(enviro, av[1]);
	mlx_key_hook(enviro->win_ptr, handle_keypress, enviro);
	mlx_loop_hook(enviro->mlx_ptr, render_wrapper, enviro);
	mlx_hook(enviro->win_ptr, 17, 0, close_window, enviro);
	mlx_loop(enviro->mlx_ptr);
	cleanup_enviro(enviro);
	return (0);
}

void	cleanup_enviro(t_enviro *enviro)
{
	int	i;

	i = 0;
	if (enviro->map)
	{
		while (i < enviro->map->height)
		{
			free(enviro->map->points[i]);
			i++;
		}
		free(enviro->map->points);
		free(enviro->map);
	}
	if (enviro->ink)
		free(enviro->ink);
	if (enviro->img_ptr)
		mlx_destroy_image(enviro->mlx_ptr, enviro->img_ptr);
	if (enviro->win_ptr)
		mlx_destroy_window(enviro->mlx_ptr, enviro->win_ptr);
	if (enviro->mlx_ptr)
		mlx_destroy_display(enviro->mlx_ptr);
	free(enviro);
	return ;
}

// If a private colormap was created, free it
// Close the X11 display connection
// Finally, free the allocated xvar structure
// substitute destroy display by mlx_cleanup(enviro->mlx_ptr); 
	//and add mlx_init.h to fdf.h
// void	mlx_cleanup(t_xvar *xvar)
// {
// 	if (!xvar)
// 		return ;
// 	if (xvar->private_cmap)
// 		XFreeColormap(xvar->display, xvar->cmap);
// 	if (xvar->display)
// 		XCloseDisplay(xvar->display);
// 	free(xvar);
// 	return ;
// }

int	close_window(t_enviro *enviro)
{
	cleanup_enviro(enviro);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_enviro *enviro)
{
	if (keycode == ESC_KEY)
		close_window(enviro);
	return (0);
}
