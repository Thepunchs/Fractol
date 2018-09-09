/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:53:42 by alefebvr          #+#    #+#             */
/*   Updated: 2018/06/01 16:33:29 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_fractal *elem)
{
	elem->x1 = -2.1;
	elem->x2 = 0.6;
	elem->y1 = -1.2;
	elem->y2 = 1.2;
	elem->imax = 50;
	elem->zoom = 250;
	elem->color = 5000;
	elem->x = 0;
	elem->y = 0;
}

void	init_julia(t_fractal *elem)
{
	elem->pause = 1;
	elem->x1 = -1;
	elem->x2 = 1;
	elem->y1 = -1.2;
	elem->y2 = 1.2;
	elem->imax = 150;
	elem->zoom = 250;
	elem->color = 5000;
	elem->x = 0;
	elem->y = 0;
	elem->c_r = 0.285;
	elem->c_i = 0.01;
}

void	init_burningship(t_fractal *elem)
{
	elem->x1 = -2.2;
	elem->x2 = 0.6;
	elem->y1 = -2.5;
	elem->y2 = 1.2;
	elem->imax = 50;
	elem->zoom = 250;
	elem->color = 5000;
	elem->x = 0;
	elem->y = 0;
}

void	init_elem(t_fractal *elem, char *arg)
{
	elem->name = arg;
	elem->mlx = mlx_init();
	elem->win = mlx_new_window(elem->mlx, WINX, WINY, elem->name);
	elem->img = mlx_new_image(elem->mlx, WINX, WINY);
	elem->tmp =
	mlx_get_data_addr(elem->img, &elem->bpp, &elem->s_l, &elem->edn);
	elem->pixel = (int*)elem->tmp;
	if (ft_strcmp(arg, "Mandelbrot") == 0)
	{
		elem->fractal = mandelbrot;
		init_mandelbrot(elem);
	}
	else if (ft_strcmp(arg, "Julia") == 0)
	{
		elem->fractal = julia;
		init_julia(elem);
	}
	else if (ft_strcmp(arg, "Burningship") == 0)
	{
		elem->fractal = burningship;
		init_burningship(elem);
	}
	else
		error_arg();
}
