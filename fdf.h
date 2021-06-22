/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:10:10 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/22 16:03:15 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"

typedef struct s_fdf
{
	void	*mlx;
	void	*mlx_win;
	
	int		map_w;
	int		map_h;
	int		**map;

	int		first_click;
	int		x0;
	int		y0;
}				t_fdf;

int	ft_check_valid(char *filename, t_fdf *env);

#endif