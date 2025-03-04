/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:51:57 by nefimov           #+#    #+#             */
/*   Updated: 2025/03/04 13:20:11 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "libft.h"

int		main(int argc, char *argv[])
{
	t_mlx	xwin;

	read_args(argc, argv, &xwin);
	init_mlx(&xwin);
	draw_fractal(&xwin);
  	mlx_mouse_hook(xwin.win, mouse_win, &xwin);
  	mlx_key_hook(xwin.win, key_win, &xwin);
	mlx_hook(xwin.win, 17, 0, close_window, &xwin);
	mlx_loop(xwin.mlx);
	clean_exit(&xwin, 0);
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
			xwin->c_r = -0.4;
			xwin->c_i = 0.6;
			// xwin->get_fractal_color = get_julia_color;
			xwin->get_fractal_color = get_tricorn_color;
			color = mlx_get_color_value(xwin->mlx, xwin->get_fractal_color(xwin, x, y));
			set_bits(xwin->img_addr + y*xwin->sl + x*xwin->bpp/8, color, xwin->bpp);
		}
	}	
	mlx_put_image_to_window(xwin->mlx, xwin->win, xwin->img, 0, 0);
}