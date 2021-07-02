/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:20:45 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/07/02 11:17:27 by sgoffaux         ###   ########.fr       */
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
		ft_return_error("open error");
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		free(line);
	}
	if (close(fd) == -1)
		ft_return_error("close error");
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
		ft_return_error("open error");
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
		ft_return_error("close error");
	return (width);
}

static void	ft_fill_table(int **n, char *line, int *z_max)
{
	char	**num;
	int		i;
	int		j;

	i = 0;
	num = ft_split(line, ' ');
	while (num[i])
	{
		n[i] = malloc(sizeof(int) * 2);
		if (!n[i])
			ft_return_error("malloc error");
		n[i][0] = ft_atoi(num[i]);
		if (n[i][0] > *z_max)
			*z_max = n[i][0];
		j = 0;
		while (num[i][j] && num[i][j] != ',')
			j++;
		if (num[i][j] == ',')
			n[i][1] = ft_atoi_base(&num[i][++j], "0123456789ABCDEF");
		else
			n[i][1] = -1;
		free(num[i]);
		i++;
	}
	free(num);
}

static void	ft_get_z_min(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->z_min = map->array[0][0][0];
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->array[i][j][0] < map->z_min)
				map->z_min = map->array[i][j][0];
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
		ft_return_error("open error");
	i = 0;
	map->array = malloc(sizeof(int **) * map->height);
	if (!map->array)
		ft_return_error("malloc error");
	while (get_next_line(fd, &line))
	{
		map->array[i] = malloc(sizeof(int *) * map->width);
		if (!map->array[i])
			ft_return_error("malloc error");
		ft_fill_table(map->array[i], line, &map->z_max);
		i++;
		free(line);
	}
	ft_get_z_min(map);
	close(fd);
}
