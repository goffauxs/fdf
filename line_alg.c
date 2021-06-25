/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:38:44 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/25 12:22:38 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float ft_abs(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int ft_lerpi(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

static int ft_steep_color(int y, t_point s, t_point e, float factor)
{
	int		r;
	int		g;
	int		b;
	float	percent;
	int		color;

	percent = ft_abs(y - s.y) / ft_abs(e.y - s.y);
	if (s.reverse)
	{
		r = ft_lerpi((e.color >> 16) & 0xFF, (s.color >> 16) & 0xFF, percent);
		g = ft_lerpi((e.color >> 8) & 0xFF, (s.color >> 8) & 0xFF, percent);
		b = ft_lerpi(e.color & 0xFF, s.color & 0xFF, percent);
	}
	else
	{
		r = ft_lerpi((s.color >> 16) & 0xFF, (e.color >> 16) & 0xFF, percent);
		g = ft_lerpi((s.color >> 8) & 0xFF, (e.color >> 8) & 0xFF, percent);
		b = ft_lerpi(s.color & 0xFF, e.color & 0xFF, percent);
	}
	r *= factor;
	g *= factor;
	b *= factor;
	color = (r << 16) | (g << 8) | b;
	return (color);
}

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

static void	ft_draw_line_loop(int steep, t_point s, t_point e, float gradient, t_fdf *env)
{
	float	intersectY;
	int		x;
	
	intersectY = (float)s.y;
	x = s.x;
	while (x <= e.x)
	{
		if (steep)
		{
			ft_put_pixel(env, ft_ipart(intersectY), x, ft_steep_color(ft_ipart(intersectY), s, e, ft_rfpart(intersectY)));
			ft_put_pixel(env, ft_ipart(intersectY) + 1, x, ft_steep_color(ft_ipart(intersectY), s, e, ft_fpart(intersectY)));
		}
		else
		{
			ft_put_pixel(env, x, ft_ipart(intersectY), ft_steep_color(ft_ipart(intersectY), s, e, ft_rfpart(intersectY)));
			ft_put_pixel(env, x, ft_ipart(intersectY) + 1, ft_steep_color(ft_ipart(intersectY), s, e, ft_fpart(intersectY)));
		}
		intersectY += gradient;
		x++;
	}
}

void draw_line(t_point s, t_point e, t_fdf *env)
{
	int		steep;
	float	dy;
	float	dx;
	float	gradient;

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
		s.reverse = 1;
		e.reverse = 1;
	}
	dx = (float)(e.x - s.x);
	dy = (float)(e.y - s.y);
	gradient = dy / dx;
	if (dx == 0.0f)
		gradient = 1.f;
	ft_draw_line_loop(steep, s, e, gradient, env);
}
