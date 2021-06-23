/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:10:10 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/23 12:41:54 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct s_map
{
	int	height;
	int	width;
	int	**map;
}				t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
	t_map	*map;
}				t_fdf;

int		ft_check_valid(char *filename, t_map *map, t_fdf *env);
void	ft_draw(t_map *map, t_fdf *env);
void 	ft_put_pixel(t_fdf *env, int x, int y, int color);
void 	draw_line(int x0, int y0, int x1, int y1, t_fdf *env);

#endif