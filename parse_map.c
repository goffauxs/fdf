/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:20:45 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/23 11:17:35 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int ft_get_height(char *filename)
{
	int		fd;
	int 	height;
	char	*line;

	fd = open(filename, O_RDONLY);
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		free(line);
	}
	close(fd);
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
	width = 0;
	get_next_line(fd, &line);
	while (line[i])
	{
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
		i++;
	}
	free(line);
	close(fd);
	return (width);
}

static void ft_fill_table(int *n, char *line)
{
	char	**num;
	int		i;

	i = 0;
	num = ft_split(line, ' ');
	while (num[i])
	{
		n[i] = ft_atoi(num[i]);
		i++;
		free(num[i]);
	}
	free(num);
}

int	ft_check_valid(char *filename, t_map *map, t_fdf *env)
{
	int		fd;
	char	*line;
	int		i;

	map->width = ft_get_width(filename);
	map->height = ft_get_height(filename);
	fd = open(filename, O_RDONLY);
	i = 0;
	env->map = malloc(sizeof(int *) * (map->height + 1));
	if (!env->map)
		return (0);
	while (get_next_line(fd, &line))
	{
		map->map[i] = malloc(sizeof(int) * (map->width + 1));
		if (!map->map[i])
			return (0);
		ft_fill_table(map->map[i], line);
		i++;
		free(line);
	}
	map->map[i] = NULL;
	close(fd);
	return (1);
}