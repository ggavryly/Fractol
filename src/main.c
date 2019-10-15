/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:55:55 by ggavryly          #+#    #+#             */
/*   Updated: 2019/05/15 14:56:13 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ar, char **av)
{
	t_rt	map;

	init_win(&map, ar, av);
	pthread_control(&map);
	mlx_hook(map.win, 17, 0, exit_k, &map);
	mlx_hook(map.win, 2, 0, deal_key, &map);
	mlx_hook(map.win, 6, 0, mouse_move, &map);
	mlx_hook(map.win, 4, 0, mouse_press, &map);
	mlx_loop(map.mlx);
	return (0);
}
