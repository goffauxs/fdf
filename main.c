/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:09:55 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/29 13:14:30 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	env->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!env->mouse)
		return NULL;
	return (env);
}

static void	ft_camera_init(t_fdf *env)
{
	env->camera = malloc(sizeof(t_camera));
	if (!env->camera)
		return ;
	env->camera->zoom = ft_min(WIDTH / env->map->width / 2, HEIGHT / env->map->height / 2);
	env->camera->x_angle = 0;
	env->camera->y_angle = 0;
	env->camera->z_angle = 0;
	env->camera->z_height = 1;
	env->camera->x_offset = 0;
	env->camera->y_offset = 0;
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
	map->z_max = 0;
	return (map);
}

int main(int argc, char *argv[])
{
	t_fdf	*env;
	t_map	*map;
	
	(void)argc;
	map = ft_map_init();
	env = ft_init(map);
	env->iso = 1;
	ft_hook_controls(env);
	ft_check_valid(argv[1], map);
	ft_camera_init(env);
	env->camera->zoom--;
	ft_draw(env->map, env);
	printf("z_max: %d\n", map->z_max);
	mlx_loop(env->mlx);
}
