/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:33:56 by ggavryly          #+#    #+#             */
/*   Updated: 2019/04/22 17:34:15 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		find_color(int n, t_fr *data, t_rt *map)
{
	int i;

	i = n % 16;
	if (n < data->depth && n > 0)
		return (map->color[i]);
	else
		return (0x000000);
}

void	*processing(void *dt)
{
	t_fr	*data;
	t_rt	*map;
	int		i;
	int		j;

	data = (t_fr *)dt;
	map = (t_rt *)data->rt;
	i = data->start_y;
	while (i < WIN_THREAD_Y + data->start_y)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			data->iter = 0;
			data->c[REAL] = ((j + map->x) / map->zoom) + map->edge[X];
			data->c[IMAG] = ((i + map->y) / map->zoom) + map->edge[Y];
			data->a = data->c[REAL];
			data->b = data->c[IMAG];
			formula_choose(map, data);
			map->img_arr[i * WIN_WIDTH + j] = find_color(data->iter, data, map);
			j++;
		}
		i++;
	}
	return (NULL);
}

void	pthread_control(t_rt *map)
{
	t_fr		tab[THREAD_N];
	pthread_t	pot[THREAD_N];
	int			i;

	i = THREAD_N;
	init_data(tab, map, pot);
	while (i--)
		pthread_join(pot[i], NULL);
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	show(map);
}

void	formula_choose(t_rt *map, t_fr *data)
{
	if (map->destiny == 1)
		mandelbrot(data);
	else if (map->destiny == 2)
		julia(data);
	else if (map->destiny == 3)
		burning_ship(data);
	else if (map->destiny == 4)
		tricorn(data);
	else if (map->destiny == 5)
		tunnel(data);
	else if (map->destiny == 6)
		boombrot(data);
	else if (map->destiny == 7)
		holy_julia(data);
}
