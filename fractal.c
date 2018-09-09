/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:21:04 by alefebvr          #+#    #+#             */
/*   Updated: 2018/06/01 16:33:42 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_unity(t_fractal *elem)
{
	double	tmp;
	int		i;

	i = 0;
	while (((elem->z_r * elem->z_r) + (elem->z_i * elem->z_i)) < 4
		&& i < elem->imax)
	{
		tmp = elem->z_r;
		elem->z_r = (elem->z_r * elem->z_r)
		- (elem->z_i * elem->z_i) + elem->c_r;
		if (elem->fractal == burningship)
			elem->z_i = 2 * fabsl(elem->z_i * tmp) + elem->c_i;
		else
			elem->z_i = 2 * elem->z_i * tmp + elem->c_i;
		i++;
	}
	return (i);
}

void	mandelbrot(t_fractal *elem)
{
	intmax_t		x;
	intmax_t		y;
	int				i;

	x = elem->x;
	while (x < WINX + elem->x)
	{
		y = elem->y;
		while (y < WINY + elem->y)
		{
			elem->c_r = x / elem->zoom + elem->x1;
			elem->c_i = y / elem->zoom + elem->y1;
			elem->z_r = 0;
			elem->z_i = 0;
			i = ft_unity(elem);
			if (i == elem->imax)
				print_pixel(elem, x - elem->x, y - elem->y, 0);
			else
				print_pixel(elem, x - elem->x, y - elem->y, i * elem->color);
			y++;
		}
		x++;
	}
}

void	julia(t_fractal *elem)
{
	intmax_t	x;
	intmax_t	y;
	int			i;

	x = elem->x;
	while (x < WINX + elem->x)
	{
		y = elem->y;
		while (y < WINY + elem->y)
		{
			elem->z_r = x / elem->zoom + elem->x1;
			elem->z_i = y / elem->zoom + elem->y1;
			i = ft_unity(elem);
			if (i == elem->imax)
				print_pixel(elem, x - elem->x, y - elem->y, 0);
			else
				print_pixel(elem, x - elem->x, y - elem->y, i * elem->color);
			y++;
		}
		x++;
	}
}

void	burningship(t_fractal *elem)
{
	intmax_t	x;
	intmax_t	y;
	int			i;

	x = elem->x;
	while (x < WINX + elem->x)
	{
		y = elem->y;
		while (y < WINY + elem->y)
		{
			elem->c_r = x / elem->zoom + elem->x1;
			elem->c_i = y / elem->zoom + elem->y1;
			elem->z_r = 0;
			elem->z_i = 0;
			i = ft_unity(elem);
			if (i == elem->imax)
				print_pixel(elem, x - elem->x, y - elem->y, 0);
			else
				print_pixel(elem, x - elem->x, y - elem->y, i * elem->color);
			y++;
		}
		x++;
	}
}
