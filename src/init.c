/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:24:49 by ggavryly          #+#    #+#             */
/*   Updated: 2019/04/22 17:25:03 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		rgb_trans(int r, int g, int b)
{
	int		color;

	color = r;
	color = (color << 8) + g;
	color = (color << 8) + b;
	return (color);
}

void	color_scheme(t_rt *map)
{
	map->color[0] = rgb_trans(66, 30, 15);
	map->color[1] = rgb_trans(25, 7, 26);
	map->color[2] = rgb_trans(9, 1, 47);
	map->color[3] = rgb_trans(4, 4, 73);
	map->color[4] = rgb_trans(0, 7, 100);
	map->color[5] = rgb_trans(12, 44, 138);
	map->color[6] = rgb_trans(24, 82, 177);
	map->color[7] = rgb_trans(57, 125, 209);
	map->color[8] = rgb_trans(134, 181, 229);
	map->color[9] = rgb_trans(211, 236, 248);
	map->color[10] = rgb_trans(241, 233, 191);
	map->color[11] = rgb_trans(248, 201, 95);
	map->color[12] = rgb_trans(255, 170, 0);
	map->color[13] = rgb_trans(204, 128, 0);
	map->color[14] = rgb_trans(153, 87, 0);
	map->color[15] = rgb_trans(106, 52, 3);
}

void	init_win(t_rt *map, int ar, char **av)
{
	int		k;
	int		d;
	int		s;

	map->destiny = usage(ar, av);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIN_WIDTH, WIN_HEIGHT, "$-FRACTOL-$");
	map->img = mlx_new_image(map->mlx, WIN_WIDTH, WIN_HEIGHT);
	map->img_arr = (int *)mlx_get_data_addr(map->img, &k, &s, &d);
	map->depth = 25;
	map->x = 0;
	map->y = 0;
	map->zoom = 250;
	map->mouse_y = 0;
	map->mouse_x = 0;
	map->mouse[X] = 1;
	map->mouse[Y] = 1;
	map->edge[X] = -2;
	map->edge[Y] = -2;
	map->show = 0;
	map->stop = 0;
	color_scheme(map);
}

void	init_data(t_fr tab[THREAD_N], t_rt *map, pthread_t pot[THREAD_N])
{
	int		i;

	i = 0;
	mlx_clear_window(map->mlx, map->win);
	while (i < THREAD_N)
	{
		tab[i].depth = map->depth;
		tab[i].start_y = WIN_THREAD_Y * i;
		tab[i].rt = map;
		pthread_create(&pot[i], NULL, processing, &tab[i]);
		i++;
	}
}
