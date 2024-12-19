/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:39:46 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/12/10 13:39:49 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2d_point	project_isometric(int x, int y, int z, t_enviro *enviro)
{
	t_2d_point	p;
	double		angle;

	angle = M_PI / 6;
	p.x = (x - y) * cos(angle) * enviro->scale + enviro->x_offset;
	p.y = ((x + y) * sin(angle) - z) * enviro->scale + enviro->y_offset;
	return (p);
}

void	put_pixel(t_enviro *enviro, t_draw_ctx *ctx, t_2d_point p)
{
	int	pixel_offset;
	int	current_color;

	current_color = interpolate_color(*ctx->ink, ctx->ink->t);
	pixel_offset = (p.y * enviro->size_line)
		+ (p.x * (enviro->bpp / 8));
	*(int *)(enviro->img_data + pixel_offset) = current_color;
	return ;
}

//Bresenham's line algorithm
// line is more horizontal
// if the line is more vertical (dy/dx)
void	draw_line(t_2d_point p1, t_2d_point p2,
			t_enviro *enviro, t_draw_ctx *ctx)
{
	ctx->line.dx = abs(p2.x - p1.x);
	ctx->line.dy = abs(p2.y - p1.y);
	if (p1.x < p2.x)
		ctx->line.sx = 1;
	else
		ctx->line.sx = -1;
	if (p1.y < p2.y)
		ctx->line.sy = 1;
	else
		ctx->line.sy = -1;
	if (ctx->line.dx >= ctx->line.dy)
		draw_line_hor(p1, p2, enviro, ctx);
	else
		draw_line_ver(p1, p2, enviro, ctx);
	return ;
}

void	draw_line_hor(t_2d_point p1, t_2d_point p2,
			t_enviro *enviro, t_draw_ctx *ctx)
{
	ctx->line.e = 2 * ctx->line.dy - ctx->line.dx;
	while (p1.x != p2.x)
	{
		if (p1.x >= 0 && p1.x < WIDTH && p1.y >= 0 && p1.y < HEIGHT)
		{
			if (ctx->line.dx == 0)
				ctx->line.t = 0;
			else
				ctx->line.t = (double)(p1.x - p2.x) / ctx->line.dx;
			put_pixel(enviro, ctx, p1);
		}
		if (ctx->line.e < 0)
			ctx->line.e = ctx->line.e + 2 * ctx->line.dy;
		else
		{
			ctx->line.e = ctx->line.e + 2 * ctx->line.dy - 2 * ctx->line.dx;
			p1.y = p1.y + ctx->line.sy;
		}
		p1.x = p1.x + ctx->line.sx;
	}
	return ;
}

void	draw_line_ver(t_2d_point p1, t_2d_point p2,
			t_enviro *enviro, t_draw_ctx *ctx)
{
	ctx->line.e = 2 * ctx->line.dx - ctx->line.dy;
	while (p1.y != p2.y)
	{
		if (p1.x >= 0 && p1.x < WIDTH && p1.y >= 0 && p1.y < HEIGHT)
		{
			if (ctx->line.dy == 0)
				ctx->line.t = 0;
			else
				ctx->line.t = (double)(p1.y - p2.y) / ctx->line.dy;
			put_pixel(enviro, ctx, p1);
		}
		if (ctx->line.e < 0)
			ctx->line.e = ctx->line.e + 2 * ctx->line.dx;
		else
		{
			ctx->line.e = ctx->line.e + 2 * ctx->line.dx - 2 * ctx->line.dy;
			p1.x = p1.x + ctx->line.sx;
		}
		p1.y = p1.y + ctx->line.sy;
	}
	return ;
}
