/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 11:45:36 by ggavryly          #+#    #+#             */
/*   Updated: 2019/05/17 11:45:45 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/include/libft.h"
# include "math.h"
# include "/usr/local/include/mlx.h"
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <pthread.h>
# define WIN_WIDTH		1000
# define WIN_HEIGHT		1000
# define ESC			53
# define REAL			0
# define IMAG			1
# define X				0
# define Y				1
# define THREAD_N		10
# define WIN_THREAD_Y	WIN_HEIGHT / THREAD_N
# define STRING mlx_string_put

typedef struct	s_rt
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*img_arr;
	int			destiny;
	int			color[16];
	double		zoom;
	int			depth;
	int			x;
	int			y;
	int			show;
	int			stop;
	double		mouse_x;
	double		mouse_y;
	double		mouse[2];
	double		edge[2];
}				t_rt;

typedef struct	s_fr
{
	double		c[2];
	double		a;
	double		b;
	int			iter;
	int			depth;
	int			start_y;
	t_rt		*rt;
}				t_fr;

void			show(t_rt *map);
void			show_stop(t_rt *map, int key);
void			destiny(t_rt *map, int key);
void			init_win(t_rt *map, int ar, char **av);
void			init_data(t_fr t[THREAD_N], t_rt *map, pthread_t p[THREAD_N]);
int				usage(int ar, char **av);
int				exit_k(t_rt *map);
int				deal_key(int key, t_rt *map);
int				mouse_press(int button, int x, int y, t_rt *map);
int				mouse_move(int x, int y, t_rt *map);
void			*processing(void *dt);
void			formula_choose(t_rt *map, t_fr *data);
void			pthread_control(t_rt *map);
void			mandelbrot(t_fr *map);
void			julia(t_fr *map);
void			burning_ship(t_fr *map);
void			tricorn(t_fr *map);
void			tunnel(t_fr *map);
void			boombrot(t_fr *map);
void			holy_julia(t_fr *map);
#endif
