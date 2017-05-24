/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:09:58 by alcornea          #+#    #+#             */
/*   Updated: 2017/03/14 14:11:00 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_conversion(t_graphics *fdf)
{
	double		sin_angle;
	double		cos_angle;
	double		spacing;
	int			i;
	int			j;

	sin_angle = sin(fdf->sin * M_PI / 180);
	cos_angle = cos(fdf->cos * M_PI / 180);
	spacing = fdf->zoom * (WIDTH / (fdf->map->height / 2 + fdf->map->width));
	i = -1;
	while (++i < fdf->map->height)
	{
		j = -1;
		while (++j < fdf->map->width)
		{
			fdf->map->matrix[i][j].x = (i - fdf->map->height / 2) * spacing
				* -cos_angle + (j - fdf->map->width / 2) * spacing * cos_angle 
				+ WIDTH / 2 + fdf->xm;		
			fdf->map->matrix[i][j].y = (i - fdf->map->height / 2) * spacing
				* sin_angle - (j - fdf->map->width / 2) * spacing * -sin_angle
				- fdf->map->matrix[i][j].z * fdf->hgt  * spacing
				+ HEIGHT / 2 + fdf->ym;
		}
	}
}

void	draw_from_beginning(t_graphics  *fdf, int i, int j)
{
	t_points	pts;
	t_draw		draw;

	if (j < fdf->map->width - 1)
	{
		init_points_right(&pts, fdf, i, j);
		init_draw_var(&draw, pts);
		draw_line(pts, draw, fdf);
	}
	if (i < fdf->map->height - 1)
	{
		init_points_left(&pts, fdf, i, j);
		init_draw_var(&draw, pts);
		draw_line(pts, draw, fdf);
	}
}

int		draw(t_graphics  *fdf)
{
	int			i;
	int			j;

	i = 0;
	mlx_clear_window(fdf->mlx, fdf->win);
	isometric_conversion(fdf);
	while (i < fdf->map->height)
	{
		j = 0;
		while (j < fdf->map->width)
		{
			draw_from_beginning(fdf, i, j);
			j++;
		}
		i++;
	}
	if (fdf->legend)
		display_menu(fdf);
	return (0);
}

void	draw_line(t_points pts, t_draw draw, t_graphics *fdf)
{
	while (1)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, pts.x0, pts.y0,
				fdf->colors[fdf->color_index]);
		if (pts.x0 == pts.x1 && pts.y0 == pts.y1)
			return ;
		draw.e2 = draw.err; 
		if (draw.e2 > -draw.dx)
		{
			draw.err -= draw.dy;
			pts.x0 += draw.sx;
		}
		mlx_pixel_put(fdf->mlx, fdf->win, pts.x0, pts.y0,  fdf->colors[3]);
		if (draw.e2 < draw.dy)
		{
			draw.err += draw.dx;
			pts.y0 += draw.sy;
		}
	}
}

void	init_draw_var(t_draw *draw, t_points pts)
{
	draw->dx = abs(pts.x1 - pts.x0);
	draw->dy = abs(pts.y1 - pts.y0);
	if (pts.x0 < pts.x1) 
		draw->sx = 1;
	else
		draw->sx = -1;
	if (pts.y0 < pts.y1)
		draw->sy = 1;
	else
		draw->sy = -1;
	if (draw->dx > draw->dy)
		draw->err = draw->dx / 2;
	else
		draw->err = -draw->dy / 2;
	draw->e2 = 0;
}
