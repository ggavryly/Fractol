/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpful_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:50:16 by ggavryly          #+#    #+#             */
/*   Updated: 2019/05/15 14:50:21 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		exit_k(t_rt *map)
{
	exit(0);
}

void	restart(t_rt *map)
{
	map->x = 0;
	map->y = 0;
	map->depth = 25;
	map->zoom = 250;
	map->edge[X] = -2;
	map->edge[Y] = -2;
}

void	move(int key, t_rt *map)
{
	if (key == 126)
		map->y += 10;
	else if (key == 125)
		map->y -= 10;
	else if (key == 123)
		map->x += 10;
	else if (key == 124)
		map->x -= 10;
}

int		deal_key(int key, t_rt *map)
{
	if (key == ESC)
		exit_k(map);
	if (key == 12 && map->depth > 3)
		map->depth--;
	else if (key == 14)
		map->depth++;
	else if (key == 126 || key == 123 || key == 124 || key == 125)
		move(key, map);
	else if (key == 36)
		restart(map);
	else if ((key >= 18 && key <= 23) || key == 26)
		destiny(map, key);
	else if (key == 1)
		show_stop(map, key);
	else if (key == 34)
		show_stop(map, key);
	pthread_control(map);
	return (0);
}
