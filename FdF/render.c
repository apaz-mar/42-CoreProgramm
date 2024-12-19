/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:46:11 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/12/10 14:46:13 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render(t_enviro *enviro)
{
	t_draw_ctx			ctx;

	if (enviro->img_data)
		ft_bzero(enviro->img_data, WIDTH * HEIGHT * (enviro->bpp / 8));
	else
	{
		enviro->img_ptr = mlx_new_image(enviro->mlx_ptr, WIDTH, HEIGHT);
		enviro->img_data = mlx_get_data_addr(enviro->img_ptr,
				&enviro->bpp, &enviro->size_line, &enviro->endian);
	}
	ctx.i = 0;
	ctx.ink = enviro->ink; 
	while (ctx.i < enviro->map->height)
	{
		ctx.j = 0;
		while (ctx.j < enviro->map->width)
		{
			draw_map(enviro, &ctx);
			ctx.j++;
		}
		ctx.i++;
	}
	mlx_put_image_to_window(enviro->mlx_ptr, enviro->win_ptr,
		enviro->img_ptr, 0, 0);
	return ;
}

void	draw_map(t_enviro *enviro, t_draw_ctx *ctx)
{
	ctx->p1 = project_isometric(enviro->map->points[ctx->i][ctx->j].x,
			enviro->map->points[ctx->i][ctx->j].y,
			enviro->map->points[ctx->i][ctx->j].z, enviro);
	ctx->ink->color1 = calc_color(enviro->map->points[ctx->i][ctx->j].z,
			enviro, *ctx->ink);
	if (ctx->j < enviro->map->width - 1)
	{
		ctx->p2 = project_isometric(enviro->map->points[ctx->i][ctx->j + 1].x,
				enviro->map->points[ctx->i][ctx->j + 1].y,
				enviro->map->points[ctx->i][ctx->j + 1].z, enviro);
		ctx->ink->color2 = calc_color(enviro->map->points[ctx->i][ctx->j + 1].z,
				enviro, *ctx->ink);
		draw_line(ctx->p1, ctx->p2, enviro, ctx);
	}
	if (ctx->i < enviro->map->height - 1)
	{
		ctx->p2 = project_isometric(enviro->map->points[ctx->i + 1][ctx->j].x,
				enviro->map->points[ctx->i + 1][ctx->j].y,
				enviro->map->points[ctx->i + 1][ctx->j].z, enviro);
		ctx->ink->color2 = calc_color(enviro->map->points[ctx->i + 1][ctx->j].z,
				enviro, *ctx->ink);
		draw_line(ctx->p1, ctx->p2, enviro, ctx);
	}
	return ;
}

int	render_wrapper(void *param)
{
	render((t_enviro *)param);
	return (0);
}
