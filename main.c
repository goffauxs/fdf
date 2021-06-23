/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:09:55 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/23 12:44:28 by sgoffaux         ###   ########.fr       */
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

static int	close_win(t_fdf *env)
{
	(void)env;
	exit(0);
}

// static int	ft_mouse_hook(int button, int x, int y, t_fdf *env)
// {
// 	static int	first_click = 0;
// 	static int	x0 = 0;
// 	static int	x1 = 0;
// 	static int	y0 = 0;
// 	static int	y1 = 0;

// 	if (first_click)
// 	{
// 		x1 = x;
// 		y1 = y;
// 		ft_draw_line(x0, y0, x1, y1, env);
// 		first_click = 0;
// 	}
// 	else
// 	{
// 		x0 = x;
// 		y0 = y;
// 		first_click = 1;
// 	}
// 	ft_put_pixel(env, x, y, 0x00FF0000);
// 	ft_draw(env->map, env);
// 	printf("(%3d, %3d)\n", x, y);
// 	(void)button;
// 	return (0);
// }

int main(int argc, char *argv[])
{
	t_fdf	env;
	
	(void)argc;
	(void)argv;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 800, 600, "test");
	env.img = mlx_new_image(env.mlx, 800, 600);
	env.data_addr = mlx_get_data_addr(env.img, &env.bpp, 
		&env.size_line, &env.endian);
	//mlx_hook(env.win, 4, 0, ft_mouse_hook, &env);
	mlx_hook(env.win, 17, 0, close_win, &env);
	draw_line(100, 100, 200, 125, &env);
	ft_draw(env.map, &env);
	mlx_loop(env.mlx);
}
