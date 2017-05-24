/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:09:58 by alcornea          #+#    #+#             */
/*   Updated: 2017/03/14 14:11:00 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	height_hook(int keycode, t_graphics *fdf)
{
	if (keycode == KEY_HEIGHT_UP)
		fdf->hgt += 0.06;
	if (keycode == KEY_HEIGHT_DOWN)
		fdf->hgt -= 0.06;
	draw(fdf);
}

void	rotate_hook(int keycode, t_graphics *fdf)
{
	if (keycode == KEY_UP_ROTATE)
		fdf->sin += 5;
	if (keycode == KEY_DOWN_ROTATE)
		fdf->sin -= 5;
	if (keycode == KEY_LEFT_ROTATE)
		fdf->cos -= 5;
	if (keycode == KEY_RIGHT_ROTATE)
		fdf->cos += 5;
	draw(fdf);
}

void	scale_hook(int keycode, t_graphics *fdf)
{
	if (keycode == KEY_ZOOM_IN)
	{
		if (fdf->zoom < 3)
			fdf->zoom += 0.1;
	}
	if (keycode == KEY_ZOOM_OUT)
	{
		if (fdf->zoom > 0.1)
			fdf->zoom -= 0.1;
	}
	draw(fdf);
}

void	translate_hook(int keycode, t_graphics *fdf)
{
	if (keycode == KEY_MOVE_RIGHT)
		fdf->xm += 50;
	if (keycode == KEY_MOVE_LEFT)
		fdf->xm -= 50;
	if (keycode == KEY_MOVE_UP)
		fdf->ym -= 50;
	if (keycode == KEY_MOVE_DOWN)
		fdf->ym += 50;
	draw(fdf);
}

int		key_hook(int keycode, t_graphics *fdf)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit(0);
	if (keycode == KEY_UP_ROTATE || keycode == KEY_DOWN_ROTATE ||
		keycode == KEY_LEFT_ROTATE || keycode == KEY_RIGHT_ROTATE)
		rotate_hook(keycode, fdf);
	if (keycode == KEY_COLOR)
		color_hook(fdf);
	if (keycode == KEY_ZOOM_IN || keycode == KEY_ZOOM_OUT)
		scale_hook(keycode, fdf);
	if (keycode == KEY_MOVE_RIGHT || keycode == KEY_MOVE_LEFT ||
		keycode == KEY_MOVE_UP || keycode == KEY_MOVE_DOWN)
		translate_hook(keycode, fdf);
	if (keycode == KEY_HEIGHT_UP || keycode == KEY_HEIGHT_DOWN)
		height_hook(keycode, fdf);
	return (0);
}
