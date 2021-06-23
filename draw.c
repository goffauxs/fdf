/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:17:05 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/23 11:26:54 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_put_pixel(t_fdf *env, int x, int y, int color)
{
	int	i;
	
	if (x >= 0 && x < 800 && y >=0 && y < 600)
	{
		i = (x * env->bpp / 8) + (y * env->size_line);
		env->data_addr[i] = color;
		env->data_addr[++i] = color >> 8;
		env->data_addr[++i] = color >> 16;
	}
}

// static void ft_background(t_fdf *env)
// {
// 	int	*image;
// 	int	i;

// 	i = 0;
// 	ft_bzero(env->data_addr, 800 * 600 * (env->bpp / 8));
// 	image = (int *)env->data_addr;
// 	while (i < 800 * 600)
// 	{
// 		image[i] = 0;
// 		i++;
// 	}
// }

void	ft_draw(t_map *map, t_fdf *env)
{
	// int	x;
	// int	y;
	
	(void)map;
	//ft_background(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}