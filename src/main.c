/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:51:57 by nefimov           #+#    #+#             */
/*   Updated: 2025/03/03 23:30:21 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	init_mlx(t_mlx *xwin);

int		main(void)
{
	t_mlx	xwin;
	
	init_mlx(&xwin);

	draw_fractal(&xwin);
	
	
	mlx_loop(xwin.mlx);
	
	mlx_destroy_image(xwin.mlx, xwin.img);
	printf("Image destroyed\n");
	mlx_destroy_window(xwin.mlx, xwin.win);
	printf("Window destroyed\n");
	mlx_destroy_display(xwin.mlx);
	printf("Display destroyed\n");
	return (0);
}

int	init_mlx(t_mlx *xwin)
{
	xwin->mlx = mlx_init ();
	if (xwin->mlx == NULL)
		return (1);
	xwin->win = mlx_new_window(xwin->mlx, SX, SY, "Window");
	if (xwin->win == NULL)
		return (1);
	xwin->img = mlx_new_image(xwin->mlx, SX, SY);
	if (xwin->img == NULL)
		return (1);
	xwin->img_addr = mlx_get_data_addr(xwin->img, &xwin->bpp, &xwin->sl, &xwin->endian);
	if (xwin->img_addr == NULL)
		return (1);
	xwin->moveX = 0;
	xwin->moveY = 0;
	xwin->zoom = 1;
	xwin->c_r = 0;
	xwin->c_i = 0;
	return (0);
}

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
			// color = mlx_get_color_value(mlx, int_color((255 * x / SX), (255 * y / SY), 0));
			xwin->c_r = -0.4;
			xwin->c_i = 0.6;
			// color = mlx_get_color_value(xwin->mlx, get_julia_color(xwin, x, y));
			color = mlx_get_color_value(xwin->mlx, get_mandelbrot_color(xwin, x, y));
			set_bits(xwin->img_addr + y*xwin->sl + x*xwin->bpp/8, color, xwin->bpp);
		}
	}
	
	mlx_put_image_to_window(xwin->mlx, xwin->win, xwin->img, 0, 0);
}