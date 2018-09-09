/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:20:52 by alefebvr          #+#    #+#             */
/*   Updated: 2018/06/01 16:21:18 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_pixel(t_fractal *elem, int x, int y, int color)
{
	if (x >= 0 && x < WINX && y >= 0 && y < WINY)
		elem->pixel[y * WINX + x] = color;
}

int		main(int argc, char **argv)
{
	t_fractal *elem;

	if ((elem = (t_fractal *)malloc(sizeof(t_fractal))) == NULL)
		error_malloc();
	if (argc != 2)
		error_arg();
	init_elem(elem, argv[1]);
	elem->fractal(elem);
	mlx_put_image_to_window(elem->mlx, elem->win, elem->img, 0, 0);
	mlx_hook(elem->win, 2, 0, key_hook, elem);
	mlx_hook(elem->win, 17, 0, exit_hook, elem);
	if (elem->fractal == julia)
		mlx_hook(elem->win, 6, 64, mouse_move, elem);
	mlx_mouse_hook(elem->win, mouse_hook, elem);
	mlx_loop(elem->mlx);
}
