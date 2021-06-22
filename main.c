/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:09:55 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/22 16:26:09 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

*/

#include "fdf.h"
#include <stdio.h>

// static void	ft_init(t_fdf *env)
// {
// 	env->map_h = 0;
// 	env->map_w = 0;
// }

// static void	ft_draw_line(int x0, int y0, int x1, int y1, t_fdf *env)
// {
// 	int dx;
// 	int dy;
// 	int p;
// 	int x;
// 	int y;
	
// 	dx = x1 - x0;
// 	dy = y1 - y0;
// 	x = x0;
// 	y = y0;
// 	p = 2 * dy - dx;
// 	while (x < x1)
// 	{
// 		if (p >= 0)
// 		{
// 			mlx_pixel_put(env->mlx, env->mlx_win, x, y, 0x00FF0000);
// 			y = y + 1;
// 			p = p + 2 * dy - 2 * dx;
// 		}
// 		else
// 		{
// 			mlx_pixel_put(env->mlx, env->mlx_win, x, y, 0x00FF0000);
// 			p = p + 2 * dy;
// 			x = x + 1;
// 		}
// 	}
// }

static int	ft_mouse_hook(int button, int x, int y, t_fdf *env)
{
	mlx_pixel_put(env->mlx, env->mlx_win, x, y, 0x00FF0000);
	printf("(%3d, %3d)\n", x, y);
	(void)button;
	return (0);
}

int main(int argc, char *argv[])
{
	t_fdf	env;
	
	(void)argc;
	(void)argv;
	env.mlx = mlx_init();
	env.mlx_win = mlx_new_window(env.mlx, 800, 600, "test");
	env.first_click = 0;
	mlx_mouse_hook(env.mlx_win, ft_mouse_hook, &env);
	mlx_loop(env.mlx);
}
