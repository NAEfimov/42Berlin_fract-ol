/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:49:16 by nefimov           #+#    #+#             */
/*   Updated: 2025/03/04 19:09:13 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "main.h"

void	draw_fractal(t_mlx *xwin)
{
	int	x;
	int	y;
	int	color;

	y = -1;
	while (++y < SY)
	{
		x = -1;
		while (++x < SX)
		{
			color = mlx_get_color_value(xwin->mlx,
					xwin->get_fractal_color(xwin, x, y));
			set_bits(xwin->img_addr + y * xwin->sl + x * xwin->bpp / 8,
				color, xwin->bpp);
		}
	}
	mlx_put_image_to_window(xwin->mlx, xwin->win, xwin->img, 0, 0);
}

int	get_julia_color(t_mlx *xwin, double x, double y)
{
	double	zx;
	double	zy;
	double	tmp;
	int		i;

	zx = xwin->asp_ratio * (x - SX / 2) / (0.5 * xwin->zoom * SX) + xwin->movex;
	zy = (y - SY / 2) / (0.5 * xwin->zoom * SY) + xwin->movey;
	i = -1;
	while (++i < MAX_ITER)
	{
		tmp = zx * zx - zy * zy + xwin->c_r;
		zy = 2.0 * zx * zy + xwin->c_i;
		zx = tmp;
		if (zx * zx + zy * zy > 4.0)
			break ;
	}
	i = (i * 255 / MAX_ITER);
	return (int_color(i * 5 / 4, i * 5 / 3, i * 7 / 3));
}

int	get_mandelbrot_color(t_mlx *xwin, double x, double y)
{
	double	zx;
	double	zy;
	double	tmp;
	int		i;

	xwin->c_r = xwin->asp_ratio * (x - SX / 2)
		/ (0.5 * xwin->zoom * SX) + xwin->movex;
	xwin->c_i = (y - SY / 2) / (0.5 * xwin->zoom * SY) + xwin->movey;
	zx = 0;
	zy = 0;
	i = -1;
	while (++i < MAX_ITER)
	{
		tmp = zx * zx - zy * zy + xwin->c_r;
		zy = 2.0 * zx * zy + xwin->c_i;
		zx = tmp;
		if (zx * zx + zy * zy > 4.0)
			break ;
	}
	i = (i * 255 / MAX_ITER);
	return (int_color(i * 5 / 4, i * 5 / 3, i * 7 / 3));
}

int	get_tricorn_color(t_mlx *xwin, double x, double y)
{
	double	zx;
	double	zy;
	double	tmp;
	int		i;

	xwin->c_r = xwin->asp_ratio * (x - SX / 2)
		/ (0.5 * xwin->zoom * SX) + xwin->movex;
	xwin->c_i = (y - SY / 2) / (0.5 * xwin->zoom * SY) + xwin->movey;
	zx = 0;
	zy = 0;
	i = -1;
	while (++i < MAX_ITER)
	{
		tmp = zx * zx - zy * zy + xwin->c_r;
		zy = -2.0 * zx * zy + xwin->c_i;
		zx = tmp;
		if (zx * zx + zy * zy > 4.0)
			break ;
	}
	i = (i * 255 / MAX_ITER);
	return (int_color(i * 5 / 4, i * 5 / 3, i * 7 / 3));
}
