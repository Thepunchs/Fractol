/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 16:57:36 by alefebvr          #+#    #+#             */
/*   Updated: 2018/06/01 16:34:59 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		exit_hook(void)
{
	exit(0);
}

int		key_hook2(int key, t_fractal *elem)
{
	if (key == 15)
		elem->color = 0xE30B5C;
	if (key == 9)
		elem->color = 0xB2F302;
	if (key == 11)
		elem->color = 0x0066FF;
	if (key == 83)
		elem->color = 787222;
	if (key == 125)
		elem->y += 100;
	if (key == 126)
		elem->y -= 100;
	if (key == 124)
		elem->x += 100;
	if (key == 123)
		elem->x -= 100;
	if (key == 258 || key == 257)
		elem->pause *= -1;
	mlx_clear_window(elem->mlx, elem->win);
	elem->fractal(elem);
	mlx_put_image_to_window(elem->mlx, elem->win, elem->img, 0, 0);
	return (0);
}

int		key_hook(int key, t_fractal *elem)
{
	if (key == 53)
		exit_hook();
	if (key == 69 && elem->color <= 16580000)
		elem->color += 20000;
	if (key == 78 && elem->color >= 20002)
		elem->color -= 20000;
	if (key == 34)
		elem->imax += 5;
	if (key == 31 && elem->imax > 0)
		elem->imax -= 5;
	if (key == 51 && elem->fractal == mandelbrot)
		init_mandelbrot(elem);
	if (key == 51 && elem->fractal == julia)
		init_julia(elem);
	if (key == 51 && elem->fractal == burningship)
		init_burningship(elem);
	if (key == 49)
	{
		elem->color += 1111;
		if (elem->color >= 16580000)
			elem->color = 2;
	}
	key_hook2(key, elem);
	return (0);
}

int		mouse_hook(int key, int x, int y, t_fractal *elem)
{
	if (key == 1 || key == 4)
	{
		elem->x += (double)x / 6.0;
		elem->y += (double)y / 6.0;
		elem->zoom *= 1.2;
		elem->y *= 1.2;
		elem->x *= 1.2;
	}
	if (key == 2 || key == 5)
	{
		elem->x -= (double)x / 5.0;
		elem->y -= (double)y / 5.0;
		elem->zoom /= 1.2;
		elem->y /= 1.2;
		elem->x /= 1.2;
	}
	mlx_clear_window(elem->mlx, elem->win);
	elem->fractal(elem);
	mlx_put_image_to_window(elem->mlx, elem->win, elem->img, 0, 0);
	return (0);
}

int		mouse_move(int x, int y, t_fractal *elem)
{
	if (elem->pause == 1)
	{
		elem->c_r = (long double)x / 500;
		elem->c_i = (long double)y / 500;
		mlx_clear_window(elem->mlx, elem->win);
		elem->fractal(elem);
		mlx_put_image_to_window(elem->mlx, elem->win, elem->img, 0, 0);
	}
	return (0);
}
