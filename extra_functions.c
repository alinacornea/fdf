/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:09:58 by alcornea          #+#    #+#             */
/*   Updated: 2017/03/14 14:11:00 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void	display_menu(t_graphics *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 5, 5, 0x6666FF, " <LEGEND>");
	mlx_string_put(fdf->mlx, fdf->win, 5, 20, 0x6666FF, " Rotate: UP, \
			RIGHT, DOWN, LEFT");
	mlx_string_put(fdf->mlx, fdf->win, 5, 35, 0x6666FF, " Translate: NB8, NB6, \
			NB2, NB4");
	mlx_string_put(fdf->mlx, fdf->win, 5, 50, 0x6666FF, " Scale: +, -");
	mlx_string_put(fdf->mlx, fdf->win, 5, 65, 0x6666FF, " Height: H, J");
	mlx_string_put(fdf->mlx, fdf->win, 5, 80, 0x6666FF, " Color: C");
	mlx_string_put(fdf->mlx, fdf->win, 5, 110, 0x6666FF, " Exit: ESC or Q");
}

void	color_hook(t_graphics *fdf)
{
	if (fdf->color_index == 8)
		fdf->color_index = 0;
	else
		fdf->color_index++;
	draw(fdf);
}

void	print_error_and_exit(int error)
{
	char	**txt;

	txt = (char**)malloc(sizeof(char*) * 5);
	txt[0] = "Usage: ./fdf... choose a map";
	txt[1] = "Error: no file opened";
	txt[2] = "Error: different number of values on lines";
	txt[3] = "Error: the file is empty";
	txt[4] = "Error: invalid color";
	ft_putstr(txt[error]);
	ft_putchar('\n');
	exit(0);
}

void	clear_mem(char ***src)
{
	int		i;

	i = 0;
	while (*src[i])
	{
		free(*src[i]);
		i++;
	}
}

int		count_digits(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str)
		{
			count++;
			while (*str && *str != ' ')
				str++;
		}
	}
	return (count);
}
