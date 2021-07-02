/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:09:55 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/07/02 15:36:57 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_get_title(const char *str)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	tmp = ft_strrchr(str, '/');
	if (tmp)
		tmp++;
	len = ft_strlen(tmp);
	while (str[i] && &str[i] != tmp)
		i++;
	return (ft_substr(str, i, len - 4));
}

static t_fdf	*ft_init(const char *path)
{
	t_fdf	*env;
	char	*title;

	title = ft_get_title(path);
	env = malloc(sizeof(t_fdf));
	if (!env)
		ft_return_error("malloc error");
	env->mlx = mlx_init();
	if (!env->mlx)
		ft_return_error("error connecting to graphics server");
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, title);
	if (!env->win)
		ft_return_error("error initializing window");
	free(title);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img)
		ft_return_error("error initializing image");
	env->data_addr = mlx_get_data_addr(env->img, &env->bpp, &env->size_line,
			&env->endian);
	env->map = NULL;
	env->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!env->mouse)
		ft_return_error("error initializing mouse");
	env->alt_down = 0;
	return (env);
}

static void	ft_camera_init(t_fdf *env)
{
	env->camera = malloc(sizeof(t_camera));
	if (!env->camera)
		ft_return_error("error initializing camera");
	env->camera->zoom = ft_min(WIDTH / env->map->width / 2,
			HEIGHT / env->map->height / 2);
	env->camera->x_angle = -0.523599;
	env->camera->y_angle = -0.261799;
	env->camera->z_angle = 0;
	env->camera->z_height = 1;
	env->camera->x_offset = 0;
	env->camera->y_offset = 0;
}

static t_map	*ft_map_init(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_return_error("error initializing map");
	map->height = 0;
	map->width = 0;
	map->array = NULL;
	map->z_max = 0;
	map->z_min = 0;
	return (map);
}

int	main(int argc, char *argv[])
{
	t_fdf	*env;

	if (argc == 2)
	{
		env = ft_init(argv[1]);
		env->map = ft_map_init();
		env->iso = 0;
		ft_check_valid(argv[1], env->map);
		ft_camera_init(env);
		ft_hook_controls(env);
		ft_draw(env->map, env);
		mlx_loop(env->mlx);
	}
	else
		ft_return_error("Usage: ./fdf <filename>");
}
