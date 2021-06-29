/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:23:00 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/29 16:23:21 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define ARROW_LEFT 123
#define ARROW_RIGHT 124
#define ARROW_DOWN 125
#define ARROW_UP 126
#define CHEVRON_LESS 43
#define CHEVRON_MORE 47

int	ft_key_press(int keycode, void *params)
{
	t_fdf	*env;

	env = (t_fdf *)params;
	if (keycode == ARROW_LEFT)
		env->camera->x_offset -= 10;
	else if (keycode == ARROW_RIGHT)
		env->camera->x_offset += 10;
	else if (keycode == ARROW_DOWN)
		env->camera->y_offset += 10;
	else if (keycode == ARROW_UP)
		env->camera->y_offset -= 10;
	else if (keycode == CHEVRON_LESS)
		env->camera->z_height += 0.1;
	else if (keycode == CHEVRON_MORE)
		env->camera->z_height -= 0.1;
	if (env->camera->z_height < 0.1)
		env->camera->z_height = 0.1;
	else if (env->camera->z_height > 10)
		env->camera->z_height = 10;
	ft_draw(env->map, env);
	return (0);
}