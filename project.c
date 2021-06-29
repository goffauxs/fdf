/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:45:49 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/29 12:03:25 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_rotate_x(int *y, int *z, double x_angle)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(x_angle) + *z * sin(x_angle);
	*z = prev_y * -sin(x_angle) + *z * cos(x_angle);
}

static void	ft_rotate_y(int *x, int *z, double y_angle)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(y_angle) + *z * sin(y_angle);
	*z = prev_x * -sin(y_angle) + *z * cos(y_angle);
}

static void	ft_rotate_z(int *x, int *y, double z_angle)
{
	t_point	prev;

	prev.x = *x;
	prev.y = *y;
	*x = prev.x * cos(z_angle) - prev.y * sin(z_angle);
	*y = prev.x * sin(z_angle) + prev.y * cos(z_angle);
}

static int	ft_set_color(int x, int y, t_fdf *env)
{
	if (env->map->array[y][x][1])
		return (env->map->array[y][x][1]);
	else
		return (get_default_color(env->map->array[y][x][0], env->map));
}

t_point	project(int x, int y, t_fdf *env)
{
	t_point	point;
	int		prev_x;
	
	point.z = env->map->array[y][x][0];
	point.color = ft_set_color(x, y, env);
	point.x = x * env->camera->zoom;
	point.y = y * env->camera->zoom;
	point.z *= env->camera->zoom / env->camera->z_height;
	point.x -= (env->map->width * env->camera->zoom) / 2;
	point.y -= (env->map->height * env->camera->zoom) / 2;
	ft_rotate_x(&point.y, &point.z, env->camera->x_angle);
	ft_rotate_y(&point.x, &point.z, env->camera->y_angle);
	ft_rotate_z(&point.x, &point.y, env->camera->z_angle);
	if (env->iso)
	{
		prev_x = point.x;
		point.x = (point.x - point.y) * cos(0.523599);
		point.y = -point.z + (prev_x + point.y) * sin(0.523599);
	}
	point.x += WIDTH / 2 + env->camera->x_offset;
	point.y += (HEIGHT + env->map->height * env->camera->zoom) / 2
				+ env->camera->y_offset;
	point.reverse = 0;
	return (point);
}
