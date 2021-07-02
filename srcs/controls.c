/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:06:01 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/07/02 15:47:31 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close_win(void *params)
{
	(void)params;
	exit(0);
}

void	ft_hook_controls(t_fdf *env)
{
	mlx_hook(env->win, 2, 0, ft_key_press, env);
	mlx_hook(env->win, 4, 0, ft_mouse_down, env);
	mlx_hook(env->win, 5, 0, ft_mouse_up, env);
	mlx_hook(env->win, 6, 0, ft_mouse_move, env);
	mlx_hook(env->win, 17, 0, ft_close_win, env);
}
