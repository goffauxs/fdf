/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:38:44 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/07/01 10:34:33 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float ft_abs(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int ft_lerp(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

static int ft_get_color(int x, t_point s, t_point e, float factor)
{
	int		r;
	int		g;
	int		b;
	float	percent;

	percent = ft_abs(x - s.x) / ft_abs(e.x - s.x);
	if (s.reverse)
	{
		r = ft_lerp((e.color >> 16) & 0xFF, (s.color >> 16) & 0xFF, percent);
		g = ft_lerp((e.color >> 8) & 0xFF, (s.color >> 8) & 0xFF, percent);
		b = ft_lerp(e.color & 0xFF, s.color & 0xFF, percent);
	}
	else
	{
		r = ft_lerp((s.color >> 16) & 0xFF, (e.color >> 16) & 0xFF, percent);
		g = ft_lerp((s.color >> 8) & 0xFF, (e.color >> 8) & 0xFF, percent);
		b = ft_lerp(s.color & 0xFF, e.color & 0xFF, percent);
	}
	r *= factor;
	g *= factor;
	b *= factor;
	return ((r << 16) | (g << 8) | b);
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

static void	ft_draw_line_loop(int steep, t_point s, t_point e,
								float gradient, t_fdf *env)
{
	float	inter_y;
	int		x;
	
	inter_y = (float)s.y;
	x = s.x;
	while (x <= e.x)
	{
		if (steep)
		{
			ft_put_pixel(env, ft_ipart(inter_y), x,
							ft_get_color(x, s, e, ft_rfpart(inter_y)));
			ft_put_pixel(env, ft_ipart(inter_y) + 1, x,
							ft_get_color(x, s, e, ft_fpart(inter_y)));
		}
		else
		{
			ft_put_pixel(env, x, ft_ipart(inter_y),
							ft_get_color(x, s, e, ft_rfpart(inter_y)));
			ft_put_pixel(env, x, ft_ipart(inter_y) + 1,
							ft_get_color(x, s, e, ft_fpart(inter_y)));
		}
		inter_y += gradient;
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
	}
	dx = (float)(e.x - s.x);
	dy = (float)(e.y - s.y);
	gradient = dy / dx;
	if (dx == 0.0f)
		gradient = 1.f;
	ft_draw_line_loop(steep, s, e, gradient, env);
}
