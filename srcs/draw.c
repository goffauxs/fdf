/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:17:05 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/07/01 16:38:39 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_fdf *env, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * env->bpp / 8) + (y * env->size_line);
		env->data_addr[i] = color;
		env->data_addr[++i] = color >> 8;
		env->data_addr[++i] = color >> 16;
	}
}

static void	ft_background(t_fdf *env)
{
	int	*image;
	int	i;

	i = 0;
	ft_bzero(env->data_addr, WIDTH * HEIGHT * (env->bpp / 8));
	image = (int *)env->data_addr;
	while (i < WIDTH * HEIGHT)
	{
		image[i] = 0;
		i++;
	}
}

void	ft_draw(t_map *map, t_fdf *env)
{
	int	x;
	int	y;
	int	zoom;

	zoom = ft_min((int)(WIDTH / map->width / 2.f),
			(int)(HEIGHT / map->height / 2.f));
	ft_background(env);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != map->width - 1)
				ft_draw_line(project(x, y, env), project(x + 1, y, env), env);
			if (y != map->height - 1)
				ft_draw_line(project(x, y, env), project(x, y + 1, env), env);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
