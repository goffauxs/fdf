/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:18:12 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/07/02 15:28:54 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_return_error(const char *err_msg)
{
	if (errno == 0)
		ft_putendl_fd(err_msg, 2);
	else
		perror(err_msg);
	exit(-1);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	get_default_color(int z, t_map *map)
{
	double			percent;
	unsigned int	max;

	max = map->z_max - map->z_min;
	if (max == 0)
		return (0x432371);
	percent = ((double)(z - map->z_min) / max);
	if (percent < 0.2)
		return (0x432371);
	else if (percent < 0.4)
		return (0x714674);
	else if (percent < 0.6)
		return (0x9F6976);
	else if (percent < 0.8)
		return (0xCC8B79);
	else
		return (0xFAAE7B);
}

char	*ft_get_title(const char *str)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	tmp = ft_strrchr(str, '/');
	if (tmp)
		tmp++;
	len = ft_strlen(tmp);
	while (str[i] && &str[i] != tmp)
		i++;
	return (ft_substr(str, i, len - 4));
}