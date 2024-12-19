/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:51:39 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/12/10 14:51:40 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	zoom(t_enviro *enviro, int zoom_in)
{
	if (zoom_in == 1)
		enviro->scale = enviro->scale * 1.1;
	else if (zoom_in == 0)
		enviro->scale = enviro->scale / 1.1;
	return ;
}

void	translate(t_enviro *enviro, int dx, int dy)
{
	enviro->x_offset = enviro->x_offset + dx;
	enviro->y_offset = enviro->y_offset + dy;
	return ;
}

// sudo apt install x11-utils
//xev
// add 	handle_keypress_rotate(keycode, enviro); if rotate is included
int	handle_keypress_bonus(int keycode, t_enviro *enviro)
{
	if (keycode == ESC_KEY)
		close_window(enviro);
	if (keycode == MOVE_UP_KEY)
		translate(enviro, 0, -10);
	if (keycode == MOVE_DOWN_KEY)
		translate(enviro, 0, 10);
	if (keycode == MOVE_RIGHT_KEY)
		translate(enviro, 10, 0);
	if (keycode == MOVE_LEFT_KEY)
		translate(enviro, -10, 0);
	if (keycode == ZOOM_IN_KEY)
		zoom(enviro, 1);
	if (keycode == ZOOM_OUT_KEY)
		zoom(enviro, 0);
	mlx_clear_window(enviro->mlx_ptr, enviro->win_ptr);
	render(enviro);
	return (0); 
}

// int	handle_keypress_rotate(int keycode, t_enviro *enviro)
// {
// 	if (keycode == ROTATE_Z_KEY_CO)
// 		rotate_z(enviro, M_PI / 18);
// 	if (keycode == ROTATE_Z_KEY_CL)
// 		rotate_z(enviro, -M_PI / 18);
// 	if (keycode == ROTATE_Y_KEY_CO)
// 		rotate_y(enviro, M_PI / 18);
// 	if (keycode == ROTATE_Y_KEY_CL)
// 		rotate_y(enviro, -M_PI / 18);
// 	if (keycode == ROTATE_X_KEY_CO)
// 		rotate_x(enviro, M_PI / 18);
// 	if (keycode == ROTATE_X_KEY_CL)
// 		rotate_x(enviro, -M_PI / 18);
// 	return (0);
// }
