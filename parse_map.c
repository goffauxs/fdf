/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:20:45 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/21 16:09:31 by sgoffaux         ###   ########.fr       */
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
	while (get_next_line(fd, &line))
		height++;
	free(line);
	close(fd);
	return (height);
}

static int	ft_get_width(char *filename)
{
	int		fd;
	int		width;
	char	*line;
	int		in_word;
	int		i;
	
	in_word = 0;
	i = 0;
	fd = open(filename, O_RDONLY);
	width = 0;
	get_next_line(fd, &line);
	while (line[i])
	{
		if (ft_isspace(line[i]))
			in_word = 0;
		else
		{
			in_word = 1;
			width++;
		}
		i++;
	}
	free(line);
	close(fd);
	return (width);
}

int	ft_check_valid(char *filename, t_fdf *env)
{
	int		fd;
	char	**line;
	int		i;

	env->map_h = ft_get_height(filename);
	env->map_w = ft_get_width(filename);
	fd = open(filename, O_RDONLY);
	i = 0;
	line = malloc(sizeof(char *) * (11 + 1));
	if (!line)
		return (0);
	while (get_next_line(fd, &line[i]) > 0)
	{
		printf("line %d: %s\n", i, line[i]);
		i++;
	}
	line[i] = NULL;
	i = 0;
	while (line[i])
	{
		printf("%s\n", line[i]);
		i++;
	}
	close(fd);
	return (1);
}