/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:21:19 by alefebvr          #+#    #+#             */
/*   Updated: 2018/06/01 16:27:50 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# define WINX 1200
# define WINY 800

typedef struct		s_fractal
{
	void			*mlx;
	void			*win;
	void			*img;
	void			(*fractal)();
	char			*name;
	int				rgb;
	long double		x1;
	long double		x2;
	long double		y1;
	long double		y2;
	long double		zoom;
	long double		c_r;
	long double		c_i;
	long double		z_r;
	long double		z_i;
	intmax_t		imax;
	int				bpp;
	int				s_l;
	int				edn;
	int				*pixel;
	intmax_t		x;
	intmax_t		y;
	unsigned int	color;
	char			*tmp;
	int				pause;
}					t_fractal;

void				print_pixel(t_fractal *elem, int x, int y, int color);
void				mandelbrot(t_fractal *elem);
void				julia(t_fractal *elem);
void				burningship(t_fractal *elem);
void				init_mandelbrot(t_fractal *elem);
void				init_julia(t_fractal *elem);
void				init_burningship(t_fractal *elem);
void				init_elem(t_fractal *elem, char *arg);
void				error_arg();
void				error_malloc();
int					key_hook(int x, t_fractal *elem);
int					exit_hook();
int					mouse_hook(int key, int x, int y, t_fractal *elem);
int					mouse_move(int x, int y, t_fractal *elem);

#endif
