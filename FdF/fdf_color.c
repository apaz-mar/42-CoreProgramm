/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:43:42 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/12/10 14:43:44 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	interpolate_color(t_color ink, double t)
{
	ink.red1 = (ink.color1 >> 16) & 0xFF;
	ink.green1 = (ink.color1 >> 8) & 0xFF;
	ink.blue1 = ink.color1 & 0xFF;
	ink.red2 = (ink.color2 >> 16) & 0xFF;
	ink.green2 = (ink.color2 >> 8) & 0xFF;
	ink.blue2 = ink.color2 & 0xFF;
	ink.red = ink.red1 + t * (ink.red2 - ink.red1);
	ink.green = ink.green1 + t * (ink.green2 - ink.green1);
	ink.blue = ink.blue1 + t * (ink.blue2 - ink.blue1);
	return (ink.red << 16 | ink.green << 8 | ink.blue);
}

int	calc_color(int z, t_enviro *enviro, t_color ink)
{
	int		min_color;
	int		max_color;
	double	t;

	min_color = 0x0000FF;
	max_color = 0xFF0000;
	if (enviro->max_z == enviro->min_z)
		t = 0;
	else
		t = (double)(z - enviro->min_z) / (enviro->max_z - enviro->min_z);
	ink.color1 = min_color;
	ink.color2 = max_color;
	return (interpolate_color(ink, t));
}
