/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:51:43 by ggavryly          #+#    #+#             */
/*   Updated: 2019/05/24 17:51:44 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	boombrot(t_fr *map)
{
	double	aa;
	double	bb;

	while (map->iter < map->depth)
	{
		aa = map->a * map->a - map->b * map->b;
		bb = 2 * map->a * map->b;
		map->a = fabs(aa) + map->c[REAL];
		map->b = bb + map->c[IMAG];
		map->iter++;
		if (aa * aa + bb * bb > 16)
			break ;
	}
}

void	holy_julia(t_fr *map)
{
	double	aa;
	double	bb;

	while (map->iter < map->depth)
	{
		aa = map->a * map->a - map->b * map->b;
		bb = 2 * map->a * map->b;
		map->a = fabs(aa) + map->rt->mouse_x;
		map->b = fabs(bb) + map->rt->mouse_y;
		map->iter++;
		if (fabs(map->a + map->b) > 16)
			break ;
	}
}
