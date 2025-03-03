/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:49:16 by nefimov           #+#    #+#             */
/*   Updated: 2025/03/03 23:28:35 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int get_julia_color(t_mlx *xwin, double x, double y)
{
	double zx;
	double zy;
	double tmp;
	int i;

	// zx = (x - SX / 2) / (0.5 * xwin->zoom * SX) + xwin->moveX;
	zx = 1.5 * (x - SX / 2) / (0.5 * xwin->zoom * SX) + xwin->moveX;
	zy = (y - SY / 2) / (0.5 * xwin->zoom * SY) + xwin->moveY;
	i = -1;
	while (++i < MAX_ITER)
	{
		tmp = zx * zx - zy * zy + xwin->c_r;
		zy = 2.0 * zx * zy + xwin->c_i;
		zx = tmp;
		if (zx * zx + zy * zy > 4.0)
			break;
	}
	return int_color(i * 5 / 4, i * 5 / 3, i * 7 / 3);
}

int get_mandelbrot_color(t_mlx *xwin, double x, double y)
{
	double zx;
	double zy;
	double tmp;
	int i;

	xwin->c_r = 1.5 * (x - SX / 2) / (0.5 * xwin->zoom * SX) + xwin->moveX;
	xwin->c_i = (y - SY / 2) / (0.5 * xwin->zoom * SY) + xwin->moveY;
	zx = 0;
	zy = 0;
	i = -1;
	while (++i < MAX_ITER) {
		tmp = zx * zx - zy * zy + xwin->c_r;
		zy = 2.0 * zx * zy + xwin->c_i;
		zx = tmp;
		if (zx * zx + zy * zy > 4.0)
			break;
	}
	return int_color(i * 5 / 4, i * 5 / 3, i * 7 / 3);
}