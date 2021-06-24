/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:10:10 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/24 15:59:30 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}				t_color;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct s_pointf
{
	float	x;
	float	y;
}				t_pointf;

typedef struct s_map
{
	int	height;
	int	width;
	int	**array;
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

int		ft_check_valid(char *filename, t_map *map);
void	ft_draw(t_map *map, t_fdf *env);
void 	ft_put_pixel(t_fdf *env, int x, int y, int color);
void 	draw_line(t_point s, t_point e, t_fdf *env);
t_point	iso(int x, int y, t_map *map, int zoom);
int		ft_min(int a, int b);

#endif