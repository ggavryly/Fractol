/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpful_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:59:41 by ggavryly          #+#    #+#             */
/*   Updated: 2019/05/15 14:59:42 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_mess(void)
{
	ft_putstr_fd("Usage: ./fractol\n", 2);
	ft_putstr_fd("\tMandelbrot  - 1\n", 2);
	ft_putstr_fd("\tJulia       - 2\n", 2);
	ft_putstr_fd("\tBurningshio - 3\n", 2);
	ft_putstr_fd("\tTricorn     - 4\n", 2);
	ft_putstr_fd("\tTunnel      - 5\n", 2);
	ft_putstr_fd("\tBoombrot    - 6\n", 2);
	ft_putstr_fd("\tHoly-Julia  - 7\n", 2);
}

int		usage(int ar, char **av)
{
	if (ar != 2)
	{
		put_mess();
		exit(0);
	}
	if (av[1][0] <= '0' || av[1][0] >= '7')
	{
		put_mess();
		exit(0);
	}
	if (av[1][1] != '\0')
	{
		put_mess();
		exit(0);
	}
	return (av[1][0] - '0');
}

void	show(t_rt *map)
{
	if (map->show)
	{
		STRING(map->mlx, map->win, 5, 0, 0xFFFFFF, "-----------------");
		STRING(map->mlx, map->win, 0, 10, 0xFFFFFF, "|  INSTRUCTIONS  |");
		STRING(map->mlx, map->win, 5, 23, 0xFFFFFF, "-----------------");
		STRING(map->mlx, map->win, 0, 32, 0xFFFFFF, "|Mandelbrot   (1)|");
		STRING(map->mlx, map->win, 0, 52, 0xFFFFFF, "|Julia        (2)|");
		STRING(map->mlx, map->win, 0, 72, 0xFFFFFF, "|Burning Ship (3)|");
		STRING(map->mlx, map->win, 0, 92, 0xFFFFFF, "|Tricorn      (4)|");
		STRING(map->mlx, map->win, 0, 112, 0xFFFFFF, "|Tunnel       (5)|");
		STRING(map->mlx, map->win, 0, 132, 0xFFFFFF, "|Boombrot     (6)|");
		STRING(map->mlx, map->win, 0, 152, 0xFFFFFF, "|Holy-Julia   (7)|");
		STRING(map->mlx, map->win, 5, 164, 0xFFFFFF, "-----------------");
		STRING(map->mlx, map->win, 0, 174, 0xFFFFFF, "|Q|E - Iterations|");
		STRING(map->mlx, map->win, 0, 194, 0xFFFFFF, "|Scroll   -  Zoom|");
		STRING(map->mlx, map->win, 0, 214, 0xFFFFFF, "|^|v|<|>  -  Move|");
		STRING(map->mlx, map->win, 0, 234, 0xFFFFFF, "|Enter  -   Reset|");
		STRING(map->mlx, map->win, 0, 254, 0xFFFFFF, "|S     -     Stop|");
		STRING(map->mlx, map->win, 5, 266, 0xFFFFFF, "-----------------");
	}
	else
		STRING(map->mlx, map->win, 5, 0, 0xFFFFFF, "HOW TO USE (I)");
}

void	destiny(t_rt *map, int key)
{
	if (key == 18)
		map->destiny = 1;
	else if (key == 19)
		map->destiny = 2;
	else if (key == 20)
		map->destiny = 3;
	else if (key == 21)
		map->destiny = 4;
	else if (key == 23)
		map->destiny = 5;
	else if (key == 22)
		map->destiny = 6;
	else if (key == 26)
		map->destiny = 7;
}

void	show_stop(t_rt *map, int key)
{
	if (key == 34)
	{
		if (map->show)
			map->show = 0;
		else
			map->show = 1;
	}
	else if (key == 1)
	{
		if (map->stop)
			map->stop = 0;
		else
			map->stop = 1;
	}
}
