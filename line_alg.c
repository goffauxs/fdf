/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:38:44 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/23 12:49:23 by sgoffaux         ###   ########.fr       */
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

// static float ft_round(float n)
// {
// 	return (ft_ipart(n + 0.5f));
// }

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

void draw_line(int x0, int y0, int x1, int y1, t_fdf *env)
{
	int	steep = ft_abs(y1 - y0) > ft_abs(x1 - x0);
	int	x;

	if (steep)
	{
		ft_swap(&x0, &y0);
		ft_swap(&x1, &y1);
	}
	if (x0 > x1)
	{
		ft_swap(&x0, &x1);
		ft_swap(&y0, &y1);
	}

	float dx = x1 - x0;
	float dy = y1 - y0;
	float gradient = dy / dx;
	if (dx == 0.0f)
		gradient = 1.f;
	float intersectY = y0;
	
	if (steep)
	{
		x = x0;
		while (x <= x1)
		{
			ft_put_pixel(env, ft_ipart(intersectY), x, 255 - (int)(ft_rfpart(intersectY) * 255));
			ft_put_pixel(env, ft_ipart(intersectY) - 1, x, 255 - (int)(ft_fpart(intersectY) * 255));
			intersectY += gradient;
			x++;
		}
	}
	else
	{
		x = x0;
		while (x <= x1)
		{
			ft_put_pixel(env, x, ft_ipart(intersectY), 255 - (int)(ft_rfpart(intersectY) * 255));
			ft_put_pixel(env, x, ft_ipart(intersectY) - 1, 255 - (int)(ft_fpart(intersectY) * 255));
			intersectY += gradient;
			x++;
		}
	}
}