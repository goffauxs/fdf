/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:09:55 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/25 12:35:40 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

*/

#include "fdf.h"
#include <stdio.h>

static t_fdf	*ft_init(t_map *map)
{
	t_fdf	*env;
	
	env = malloc(sizeof(t_fdf));
	if (!env)
		return NULL;
	env->mlx = mlx_init();
	if (!env->mlx)
		return NULL;
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "test");
	if (!env->win)
		return NULL;
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img)
		return NULL;
	env->data_addr = mlx_get_data_addr(env->img, &env->bpp, &env->size_line,
										&env->endian);
	env->map = map;
	return (env);
}

static t_map	*ft_map_init()
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (!map)
		return NULL;
	map->height = 0;
	map->width = 0;
	map->array = NULL;
	return (map);
}

t_point	iso(int x, int y, t_map *map, int zoom)
{
	t_point	point;
	int	z;
	
	z = map->array[y][x];
	if (z == 0)
		point.color = 0xFF;
	else
		point.color = 0xFF0000;
	x *= zoom;
	y *= zoom;
	z *= zoom;
	x -= (map->width * zoom) / 2;
	y -= (map->height * zoom) / 2;
	point.x = (x - y) * cos(0.523599);
	point.y = -z + (x + y) * sin(0.523599);
	point.x += WIDTH / 2;
	point.y += (HEIGHT + map->height * zoom) / 2;
	point.reverse = 0;
	return (point);
}

static int	close_win(t_fdf *env)
{
	(void)env;
	exit(0);
}

int main(int argc, char *argv[])
{
	t_fdf	*env;
	t_map	*map;
	
	(void)argc;
	map = ft_map_init();
	env = ft_init(map);
	mlx_hook(env->win, 17, 0, close_win, &env);
	ft_check_valid(argv[1], map);
	ft_draw(env->map, env);
	mlx_loop(env->mlx);
}
