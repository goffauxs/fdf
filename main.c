/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:09:55 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/07/01 12:04:36 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static char *ft_get_title(const char *str)
{
	int		i;
	int		len;
	char	*tmp;
	
	i = 0;
	tmp = ft_strrchr(str, '/');
	tmp++;
	len = ft_strlen(tmp);
	while(&str[i] != tmp)
		i++;
	return (ft_substr(str, i, len - 4));
}

static t_fdf	*ft_init(t_map *map, const char *title)
{
	t_fdf	*env;
	
	env = malloc(sizeof(t_fdf));
	if (!env)
		return NULL;
	env->mlx = mlx_init();
	if (!env->mlx)
		return NULL;
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, ft_get_title(title));
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
	env->alt_down = 0;
	return (env);
}

static void	ft_camera_init(t_fdf *env)
{
	env->camera = malloc(sizeof(t_camera));
	if (!env->camera)
		return ;
	env->camera->zoom = ft_min(WIDTH / env->map->width / 2, HEIGHT / env->map->height / 2);
	env->camera->x_angle = -0.523599;
	env->camera->y_angle = -0.261799;
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
	env = ft_init(map, argv[1]);
	env->iso = 0;
	ft_check_valid(argv[1], map);
	ft_camera_init(env);
	ft_hook_controls(env);
	ft_draw(env->map, env);
	mlx_loop(env->mlx);
}
