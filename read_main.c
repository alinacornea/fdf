/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:09:58 by alcornea          #+#    #+#             */
/*   Updated: 2017/03/14 14:11:00 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	*read_line(char *str, int size)
{
	int		i;
	t_coord	*tab;
	char	**temp;

	i = 0;
	tab = (t_coord*)malloc(sizeof(tab) * size * 2);
	temp = ft_strsplit(str, ' ');
	while (temp[i])
	{
		tab[i].x = 0;
		tab[i].y = 0;
		tab[i].z = ft_atoi(temp[i]);
		i++;
	}
	clear_mem(&temp);
	return (tab);
}

void	read_map(t_map **map, int fd, char *filename)
{
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (!((*map)->matrix = (t_coord**)malloc(sizeof(t_coord*) * (*map)->height)))
		return ;
	while (get_next_line(fd, &line))
	{
		(*map)->matrix[i] = read_line(line, (*map)->width);
		i++;
	}
	close(fd);
}

void	get_map_size(t_map **map, int fd)
{
	int		get_height;
	int		get_width;
	int 	temp;
	char	*line;

	get_height = 0;
	get_width = 0;
	temp = 0;
	while (get_next_line(fd, &line))
	{
		if (line == NULL)
			print_error_and_exit(1);
		if (get_height == 0)
			get_width = count_digits(line);
		temp = count_digits(line);
		if (get_width != temp)
			print_error_and_exit(2);
		get_height++;
	}
	free(line);
	if (get_height == 0)
		print_error_and_exit(3);
	(*map)->height = get_height;
	(*map)->width = get_width;
	close(fd);
}

t_map	*get_map(char *filename)
{
	int		fd;
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	if ((fd = open(filename, O_RDONLY)) == -1)
		print_error_and_exit(1);
	get_map_size(&map, fd);
	read_map(&map, fd, filename);

	return (map);
}

int		main(int argc, char **argv)
{
	t_graphics	fdf;

	if (argc < 2 || argc > 3)
		print_error_and_exit(0);
	else
	{
		fdf.def_color = 0;
		fdf.map = get_map(argv[1]);
		start_mlx(&fdf);
	}
	return (0);
}
