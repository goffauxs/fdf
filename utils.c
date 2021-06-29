/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:18:12 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/29 11:50:33 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	get_default_color(int z, t_map *map)
{
	double percent;

	percent = (double)(z / map->z_max);
	if (percent < 0.2)
		return (0x9A1F6A);
	else if (percent < 0.4)
		return (0xC2294E);
	else if (percent < 0.6)
		return (0xEC4B27);
	else if (percent < 0.8)
		return (0xEF8633);
	else
		return (0xF3AF3D);
}