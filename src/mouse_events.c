/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:53:41 by ggavryly          #+#    #+#             */
/*   Updated: 2019/05/15 14:53:43 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, t_rt *map)
{
	if (!map->stop && x < WIN_WIDTH && y < WIN_HEIGHT && x > 0 && y > 0)
	{
		map->mouse_x = (x - WIN_WIDTH / 2) / 500.0;
		map->mouse_y = (y - WIN_HEIGHT / 2) / 500.0;
	}
	pthread_control(map);
	return (0);
}

int		mouse_press(int button, int x, int y, t_rt *map)
{
	map->mouse[X] = x;
	map->mouse[Y] = y;
	if (button == 4)
	{
		map->edge[X] = (map->edge[X] + (map->mouse[X] / map->zoom)) -
				(map->mouse[X] / (map->zoom * 1.1));
		map->edge[Y] = (map->edge[Y] + (map->mouse[Y] / map->zoom)) -
				(map->mouse[Y] / (map->zoom * 1.1));
		map->zoom *= 1.1;
	}
	else if (button == 5)
	{
		map->edge[X] = (map->edge[X] + (map->mouse[X] / map->zoom)) -
				(map->mouse[X] / (map->zoom / 1.1));
		map->edge[Y] = (map->edge[Y] + (map->mouse[Y] / map->zoom)) -
				(map->mouse[Y] / (map->zoom / 1.1));
		map->zoom /= 1.1;
	}
	pthread_control(map);
	return (0);
}
