/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:20:45 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/07/08 15:51:43 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_get_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("open error", 1);
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		free(line);
	}
	free(line);
	if (close(fd) == -1)
		ft_return_error("close error", 1);
	return (height);
}

static int	ft_get_width(char *filename)
{
	int		fd;
	int		width;
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("open error", 1);
	width = 0;
	get_next_line(fd, &line);
	while (line[i])
	{
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
		i++;
	}
	free(line);
	if (close(fd) == -1)
		ft_return_error("close error", 1);
	return (width);
}

static void	ft_fill_table(int **n, char *line, int width)
{
	char	**num;
	int		i;
	int		j;

	num = ft_split(line, ' ');
	i = -1;
	while (num[++i] && i < width)
	{
		n[i] = malloc(sizeof(int) * 2);
		if (!n[i])
			ft_return_error("malloc error", 1);
		n[i][0] = ft_atoi(num[i]);
		j = 0;
		while (num[i][j] && num[i][j] != ',')
			j++;
		if (num[i][j] == ',')
			n[i][1] = ft_atoi_base(&num[i][++j], "0123456789ABCDEF");
		else
			n[i][1] = -1;
		free(num[i]);
	}
	if (i != width || num[i])
		ft_return_error("error: fdf file has irregular width", 0);
	free(num);
}

static void	ft_get_z_min_max(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->z_min = map->array[0][0][0];
	map->z_max = map->array[0][0][0];
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->array[i][j][0] < map->z_min)
				map->z_min = map->array[i][j][0];
			if (map->array[i][j][0] > map->z_max)
				map->z_max = map->array[i][j][0];
			j++;
		}
		i++;
	}
}

void	ft_check_valid(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	map->width = ft_get_width(filename);
	map->height = ft_get_height(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("open error", 1);
	i = 0;
	map->array = malloc(sizeof(int **) * map->height);
	if (!map->array)
		ft_return_error("malloc error", 1);
	while (get_next_line(fd, &line) > 0)
	{
		map->array[i] = malloc(sizeof(int *) * map->width);
		if (!map->array[i])
			ft_return_error("malloc error", 1);
		ft_fill_table(map->array[i], line, map->width);
		i++;
		free(line);
	}
	free(line);
	ft_get_z_min_max(map);
	if (close(fd) == -1)
		ft_return_error("close error", 1);
}
