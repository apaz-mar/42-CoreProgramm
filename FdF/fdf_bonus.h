/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:35:18 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/12/10 14:35:21 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "ft_printf.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <limits.h>
//# include "mlx_int.h"

# define WIDTH	1800
# define HEIGHT	1000

# define ESC_KEY			65307
# define ROTATE_X_KEY_CO   	97 // 'x' counterclockwise A
# define ROTATE_X_KEY_CL	100 // 'x' clockwise D
# define ROTATE_Y_KEY_CO	119 // 'y' counterclockwise W
# define ROTATE_Y_KEY_CL	120 // 'y' clockwise X
# define ROTATE_Z_KEY_CO	113 // 'z' counterclockwise Q
# define ROTATE_Z_KEY_CL	101 // 'z' clockwise E
# define MOVE_LEFT_KEY		65361 // Left arrow
# define MOVE_RIGHT_KEY		65363 // Right arrow
# define MOVE_UP_KEY		65362 // Up arrow
# define MOVE_DOWN_KEY		65364 // Down arrow
# define ZOOM_IN_KEY		65451    // '+'
# define ZOOM_OUT_KEY		65453    // '-'

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	t_point	**points;
}	t_map;

typedef struct s_iso_point
{
	int	x;
	int	y;
}	t_2d_point;

typedef struct s_line
{
	int		dx;
	int		dy;
	int		e;
	int		sx;
	int		sy;
	int		pixel_offset;
	double	t;
}	t_line;

typedef struct s_color
{
	int		red1;
	int		red2;
	int		green1;
	int		green2;
	int		blue1;
	int		blue2;
	int		red;
	int		green;
	int		blue;
	int		color1;
	int		color2;
	double	t;
}	t_color;

typedef struct s_enviro
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
	t_map	*map;
	double	scale;
	int		x_offset;
	int		y_offset;
	int		max_z;
	int		min_z;
	t_color	*ink;
}	t_enviro;

typedef struct s_draw_ctx
{
	t_enviro			*enviro;
	t_line				line;
	int					i;
	int					j;
	t_2d_point			p1;
	t_2d_point			p2;
	t_color				*ink;
}	t_draw_ctx;

typedef struct s_row_ctx
{
	int			width;
	int			x;
	t_enviro	*enviro;
}	t_row_ctx;

//initialize
void		init_enviro(t_enviro *enviro, char *filename);
void		init_enviro_aux(t_enviro *enviro);

// read file and fill map
int			parse_file(char *filename, t_map *map, t_enviro *enviro);
int			fill_map(char *filename, t_map *map, t_enviro *enviro);
int			process_file(int fd, t_map *map, t_row_ctx *context);
int			handle_line(t_map *map, t_row_ctx *context, char *line, int x);
void		free_rows(t_point **points, int rows);
int			allocate_map(t_map *map);
int			count_map_dimensions(int fd, t_map *map);
int			count_columns(char *line);
int			open_file(char *filename);

// parse line and fill rows
t_point		*parse_line(char *line, int width, t_row_ctx context);
char		**ft_split(char const *s, char c);
int			fill_points_row(t_point *points_row, char **values,
				t_row_ctx context);
void		free_values(char **values, int j);

// draw lines
t_2d_point	project_isometric(int x, int y, int z, t_enviro *enviro);
void		put_pixel(t_enviro *enviro, t_draw_ctx *ctx, t_2d_point p);
void		draw_line(t_2d_point p1, t_2d_point p2,
				t_enviro *enviro, t_draw_ctx *ctx);
void		draw_line_hor(t_2d_point p1, t_2d_point p2,
				t_enviro *enviro, t_draw_ctx *ctx);
void		draw_line_ver(t_2d_point p1, t_2d_point p2,
				t_enviro *enviro, t_draw_ctx *ctx);

// render
void		ft_bzero(void *s, size_t n);
void		render(t_enviro *enviro);
void		draw_map(t_enviro *enviro, t_draw_ctx *ctx);
int			render_wrapper(void *param);
int			close_window(t_enviro *enviro);
void		cleanup_enviro(t_enviro *enviro);

// color
int			interpolate_color(t_color ink, double t);
int			calc_color(int z, t_enviro *enviro, t_color ink);

// bonus: rotate, zoom, translate
// void		rotate_z(t_enviro *enviro, double angle);
// void		rotate_y(t_enviro *enviro, double angle);
// void		rotate_x(t_enviro *enviro, double angle);
// void		calculate_centroid(t_enviro *enviro,
				//double *cx, double *cy, double *cz);
int			handle_keypress_bonus(int keycode, t_enviro *enviro);
//int			handle_keypress_rotate(int keycode, t_enviro *enviro);
void		translate(t_enviro *enviro, int dx, int dy);
void		zoom(t_enviro *enviro, int zoom_in);

//void		mlx_cleanup(t_xvar *xvar);
void		destroy_mlx(t_enviro *enviro);
void		check_and_exit(int condition,
				t_enviro *enviro, char *error_message);
int			handle_keypress(int keycode, t_enviro *enviro);

#endif /* FDF_BONUS*/
