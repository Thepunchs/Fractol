/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 16:38:52 by alefebvr          #+#    #+#             */
/*   Updated: 2018/04/15 22:00:56 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_arg(void)
{
	ft_putendl("Usage : ./fractol [Mandelbrot || Julia || Burningship]");
	exit(1);
}

void	error_malloc(void)
{
	ft_putendl("Malloc error");
	exit(1);
}
