/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:09:55 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/06/21 15:45:19 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

*/

#include "fdf.h"

static void	ft_init(t_fdf *env)
{
	env->map_h = 0;
	env->map_w = 0;
}

int main(int argc, char *argv[])
{
	t_fdf	env;
	
	if (argc == 2)
	{
		ft_init(&env);
		ft_check_valid(argv[1], &env);
	}
}