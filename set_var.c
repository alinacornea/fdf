
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:09:58 by alcornea          #+#    #+#             */
/*   Updated: 2017/03/14 14:11:00 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_points_right(t_points *pts, t_graphics *fdf, int i, int j)
{
	pts->x0 = fdf->map->matrix[i][j].x;
	pts->y0 = fdf->map->matrix[i][j].y;
	pts->x1 = fdf->map->matrix[i][j + 1].x;
	pts->y1 = fdf->map->matrix[i][j + 1].y;
}

void	init_points_left(t_points *pts, t_graphics *fdf, int i, int j)
{
	pts->x0 = fdf->map->matrix[i][j].x;
	pts->y0 = fdf->map->matrix[i][j].y;
	pts->x1 = fdf->map->matrix[i + 1][j].x;
	pts->y1 = fdf->map->matrix[i + 1][j].y; 
}

void	init_colors(t_graphics  *fdf)
{
	if (fdf->def_color)
		fdf->colors[0] = fdf->def_color;
	else{
		fdf->colors[0] = WHITE;
		fdf->colors[1] = RED;
		fdf->colors[2] = YELLOW;
		fdf->colors[3] = BLUE;
		fdf->colors[4] = AQUA_BLUE;
		fdf->colors[5] = GREEN;
		fdf->colors[6] = LIME_GREEN;
		fdf->colors[7] = PINK;
		fdf->colors[8] = PURPLE;
	}
}

void	init(t_graphics  *fdf)
{
	fdf->zoom = 0.75;
	fdf->hgt = 0.1;
	fdf->sin = 40;
	fdf->cos = 30;
	fdf->xm = 0;
	fdf->ym = 0;
	fdf->color_index = 0;
	fdf->legend = 1;
	init_colors(fdf);
}

void	start_mlx(t_graphics  *fdf)
{
	init(fdf);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "42 fdf");
	mlx_expose_hook(fdf->win, draw, fdf);
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_loop(fdf->mlx);
}
