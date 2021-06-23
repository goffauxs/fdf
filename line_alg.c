/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:38:44 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/23 16:09:34 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	ft_ipart(float n)
{
	return ((int)n);
}

static float ft_fpart(float n)
{
	if (n > 0.f)
		return (n - ft_ipart(n));
	return (n - (ft_ipart(n) + 1.f));
}

static float ft_rfpart(float n)
{
	return (1.f - ft_fpart(n));
}

static float ft_abs(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	ft_draw_line_loop(int steep, t_point s, t_point e, float gradient, t_fdf *env)
{
	float	intersectY;
	
	intersectY = (float)(s.y);
	while (s.x <= e.x)
	{
		if (steep)
		{
			ft_put_pixel(env, ft_ipart(intersectY), s.x, 0xFF0000 * (int)(ft_rfpart(intersectY) * 255));
			ft_put_pixel(env, ft_ipart(intersectY) - 1, s.x, 0xFF0000 * (int)(ft_fpart(intersectY) * 255));
		}
		else
		{
			ft_put_pixel(env, s.x, ft_ipart(intersectY), 0xFF0000 * (int)(ft_rfpart(intersectY) * 255));
			ft_put_pixel(env, s.x, ft_ipart(intersectY) - 1, 0xFF0000 * (int)(ft_fpart(intersectY) * 255));
		}
		intersectY += gradient;
		s.x++;
	}
}

void draw_line(t_point s, t_point e, t_fdf *env)
{
	int			steep;
	t_pointf 	delta;
	float		gradient;

	steep = ft_abs(e.y - s.y) > ft_abs(e.x - s.x);
	if (steep)
	{
		ft_swap(&s.x, &s.y);
		ft_swap(&e.x, &e.y);
	}
	if (s.x > e.x)
	{
		ft_swap(&s.x, &e.x);
		ft_swap(&s.y, &e.y);
	}
	delta.x = (float)(e.x - s.x);
	delta.y = (float)(e.y - s.y);
	gradient = delta.y / delta.x;
	if (delta.x == 0.0f)
		gradient = 1.f;
	ft_draw_line_loop(steep, s, e, gradient, env);
}