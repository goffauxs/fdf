/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:23:00 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/07/01 16:48:29 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_toggle_projection(t_fdf *env)
{
	if (env->iso)
	{
		env->camera->x_angle = -0.523599;
		env->camera->y_angle = -0.261799;
	}
	else
	{
		env->camera->x_angle = 0;
		env->camera->y_angle = 0;
	}
	env->iso = !env->iso;
}

static void	ft_mod_height(int keycode, t_fdf *env)
{
	if (keycode == MINUS)
		env->camera->z_height += 0.1;
	else if (keycode == PLUS)
		env->camera->z_height -= 0.1;
	if (env->camera->z_height < 0.1)
		env->camera->z_height = 0.1;
	else if (env->camera->z_height > 10)
		env->camera->z_height = 10;
}

static void	ft_translate(int keycode, t_fdf *env)
{
	if (keycode == ARROW_LEFT)
		env->camera->x_offset -= 10;
	else if (keycode == ARROW_RIGHT)
		env->camera->x_offset += 10;
	else if (keycode == ARROW_DOWN)
		env->camera->y_offset += 10;
	else if (keycode == ARROW_UP)
		env->camera->y_offset -= 10;
}

int	ft_key_press(int keycode, void *params)
{
	t_fdf	*env;

	env = (t_fdf *)params;
	if (keycode == ARROW_DOWN || keycode == ARROW_LEFT || keycode == ARROW_UP
		|| keycode == ARROW_RIGHT)
		ft_translate(keycode, env);
	else if (keycode == MINUS || keycode == PLUS)
		ft_mod_height(keycode, env);
	else if (keycode == SPACE)
		ft_toggle_projection(env);
	ft_draw(env->map, env);
	return (0);
}
