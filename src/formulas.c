/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:31:36 by ggavryly          #+#    #+#             */
/*   Updated: 2019/05/08 16:31:38 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fr *map)
{
	double	aa;
	double	bb;

	while (map->iter < map->depth)
	{
		aa = map->a * map->a - map->b * map->b;
		bb = 2 * map->a * map->b;
		map->a = aa + map->c[REAL];
		map->b = bb + map->c[IMAG];
		map->iter++;
		if (aa * aa + bb * bb > 16)
			break ;
	}
}

void	julia(t_fr *map)
{
	double	aa;
	double	bb;

	while (map->iter < map->depth)
	{
		aa = map->a * map->a - map->b * map->b;
		bb = 2 * map->a * map->b;
		map->a = aa + map->rt->mouse_x;
		map->b = bb + map->rt->mouse_y;
		map->iter++;
		if (fabs(map->a + map->b) > 16)
			break ;
	}
}

void	burning_ship(t_fr *map)
{
	double	aa;
	double	bb;

	while (map->iter < map->depth)
	{
		aa = map->a * map->a - map->b * map->b;
		bb = 2 * map->a * map->b;
		map->a = aa + map->c[REAL];
		map->b = fabs(bb) + map->c[IMAG];
		map->iter++;
		if (aa * aa + bb * bb > 16)
			break ;
	}
}

void	tricorn(t_fr *map)
{
	double	aa;
	double	bb;

	while (map->iter < map->depth)
	{
		aa = map->a * map->a - map->b * map->b;
		bb = -2 * map->a * map->b;
		map->a = aa + map->c[REAL];
		map->b = bb + map->c[IMAG];
		map->iter++;
		if (aa * aa + bb * bb > 16)
			break ;
	}
}

void	tunnel(t_fr *map)
{
	double	aa;
	double	bb;

	while (map->iter < map->depth)
	{
		aa = map->a * map->a - map->b * map->b;
		bb = 2 * map->a * map->b;
		map->a = map->a + map->c[REAL];
		map->b = map->b + map->c[IMAG];
		map->iter++;
		if (aa * aa + bb * bb > 16)
			break ;
	}
}
