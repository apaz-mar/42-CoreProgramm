/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:02:33 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/12/10 15:02:36 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	main(int ac, char **av)
{
	t_enviro	*enviro;

	if (ac != 2)
	{
		ft_printf("Usage: ./fdf <file.fdf>\n");
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
	mlx_key_hook(enviro->win_ptr, handle_keypress_bonus, enviro);
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
