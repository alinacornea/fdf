/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:09:58 by alcornea          #+#    #+#             */
/*   Updated: 2017/03/14 14:11:00 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <stdio.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"

# define WIDTH 1200
# define HEIGHT 1200
# define BUFF_SIZE 32
# define MAX_FD 200

# define KEY_ESC 53
# define KEY_Q 12
# define KEY_LEFT_ROTATE 123
# define KEY_RIGHT_ROTATE 124
# define KEY_DOWN_ROTATE 125
# define KEY_UP_ROTATE 126
# define KEY_ZOOM_IN 69
# define KEY_ZOOM_OUT 78
# define KEY_COLOR 8
# define KEY_HEIGHT_UP 4
# define KEY_HEIGHT_DOWN 38
# define KEY_MOVE_UP 91
# define KEY_MOVE_DOWN 84
# define KEY_MOVE_RIGHT 88
# define KEY_MOVE_LEFT 86
# define KEY_LEGEND 37

# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define BLUE 0x0000FF
# define AQUA_BLUE 0x00FFFF
# define GREEN 0x33CC33
# define LIME_GREEN 0x00FF00
# define PINK 0xFF3399
# define PURPLE 0x9900FF

typedef struct	s_coord
{
	int		x;
	int		y;
	int		z;
}				t_coord;

typedef struct	s_points
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
}				t_points;

typedef struct	s_draw
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
}				t_draw;

typedef struct	s_map
{
	t_coord	**matrix;
	int		width;
	int		height;
}				t_map;

typedef struct	s_graphics
{
	void	*mlx;
	void	*win;
	t_map	*map;
	double	zoom;
	double	hgt;
	int		sin;
	int		cos;
	int		xm;
	int		ym;
	int		colors[10];
	int		color_index;
	int		def_color;
	int		legend;
}				t_graphics;

t_coord			*read_line(char *str, int size);
void			read_map(t_map **map, int fd, char *filename);
void			get_map_size(t_map **map, int fd);
t_map			*get_map(char *filename);

void			init_drawing(t_graphics *fdf, int i, int j);
int				draw(t_graphics *fdf);
void			init_colors(t_graphics *fdf);
void			init(t_graphics *fdf);
void			start_mlx(t_graphics *fdf);

void			display_menu(t_graphics *fdf);
void			draw_line(t_points pts, t_draw draw, t_graphics *fdf);
void			init_draw_var(t_draw *draw, t_points pts);
void			init_points_right(t_points *pts, t_graphics *fdf, int i, int j);
void			init_points_left(t_points *pts, t_graphics *fdf, int i, int j);
void			isometric_projection(t_graphics *fdf);

void			rotate_hook(int keycode, t_graphics *fdf);
void			scale_hook(int keycode, t_graphics *fdf);
void			translate_hook(int keycode, t_graphics *fdf);
void			color_hook(t_graphics *fdf);
int				key_hook(int keycode, t_graphics *fdf);
void			height_hook(int keycode, t_graphics *fdf);

void			print_error_and_exit(int error);
void			clear_mem(char ***src);
int				count_digits(char *str);
int 			get_next_line(const int fd, char **line);

#endif
