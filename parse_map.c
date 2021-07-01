/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:20:45 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/07/01 11:17:13 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static void ft_fill_table(int **n, char *line, int *z_max)
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
			return ;
		n[i][0] = ft_atoi(num[i]);
		if (n[i][0] > *z_max)
			*z_max = n[i][0];
		j = 0;
		while (num[i][j] && num[i][j] != ',')
			j++;
		if (num[i][j] == ',')
			n[i][1] = ft_atoi_base(&num[i][++j], "0123456789ABCDEF");
		else
			n[i][1] = 0;
		free(num[i]);
		i++;
	}
	free(num);
}

int	ft_check_valid(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	map->width = ft_get_width(filename);
	map->height = ft_get_height(filename);
	fd = open(filename, O_RDONLY);
	i = 0;
	map->array = malloc(sizeof(int **) * (map->height + 1));
	if (!map->array)
		return (0);
	while (get_next_line(fd, &line))
	{
		map->array[i] = malloc(sizeof(int *) * (map->width + 1));
		if (!map->array[i])
			return (0);
		ft_fill_table(map->array[i], line, &map->z_max);
		i++;
		free(line);
	}
	map->array[i] = NULL;
	close(fd);
	return (1);
}