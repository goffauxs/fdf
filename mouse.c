/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:30:05 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/07/01 12:12:38 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void ft_zoom(int button, t_fdf *env)
{
	if (button == 4)
		env->camera->zoom += 2;
	else if (button == 5)
		env->camera->zoom -= 2;
	if (env->camera->zoom < 1)
		env->camera->zoom = 1;
	ft_draw(env->map, env);
}

int	ft_mouse_down(int button, int x, int y, void *params)
{
	t_fdf	*env;

	env = (t_fdf *)params;
	if (button == 4 || button == 5)
		ft_zoom(button, env);
	else if (button == 1 || button == 3)
	{
		env->mouse->button = button;
		env->mouse->prev_x = x;
		env->mouse->prev_y = y;
	}
	return (0);
}

int ft_mouse_up(int button, int x, int y, void *params)
{
	t_fdf	*env;

	(void)x;
	(void)y;
	env = (t_fdf *)params;
	if (button == 1 || button == 3)
		env->mouse->button = 0;
	return (0);
}

int	ft_mouse_move(int x, int y, void *params)
{
	t_fdf	*env;

	env = (t_fdf *)params;
	if (env->mouse->button == 3)
	{
		env->camera->x_angle += (y - env->mouse->prev_y) * 0.002;
		env->camera->y_angle += (x - env->mouse->prev_x) * 0.002;
		env->mouse->prev_x = x;
		env->mouse->prev_y = y;
		ft_draw(env->map, env);
	}
	else if (env->mouse->button == 1)
	{
		env->camera->x_offset += (x - env->mouse->prev_x);
		env->camera->y_offset += (y - env->mouse->prev_y);
		env->mouse->prev_x = x;
		env->mouse->prev_y = y;
		ft_draw(env->map, env);
	}
	return (0);
}