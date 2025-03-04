/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:52:46 by nefimov           #+#    #+#             */
/*   Updated: 2025/03/04 12:32:43 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	init_mlx(t_mlx *xwin)
{
	xwin->mlx = NULL;
	xwin->win = NULL;
	xwin->img = NULL;
	xwin->mlx = mlx_init ();
	if (xwin->mlx == NULL)
		clean_exit(xwin, 1);
	xwin->win = mlx_new_window(xwin->mlx, SX, SY, "Window");
	if (xwin->win == NULL)
		clean_exit(xwin, 1);
	xwin->img = mlx_new_image(xwin->mlx, SX, SY);
	if (xwin->img == NULL)
		clean_exit(xwin, 1);
	xwin->img_addr = mlx_get_data_addr(xwin->img, &xwin->bpp, &xwin->sl, &xwin->endian);
	if (xwin->img_addr == NULL)
		clean_exit(xwin, 1);
	xwin->asp_ratio = SX / (double)SY;
	xwin->moveX = 0;
	xwin->moveY = 0;
	xwin->zoom = 1;
	xwin->c_r = 0;
	xwin->c_i = 0;
	return (0);
}

int		int_color(unsigned char r, unsigned char g, unsigned char b)
{
	int	col;

	col = 0;
	col = (col + r) << 8;
	col = (col + g) << 8;
	col = col + b;
	return (col);
}

void	set_bits(char *addr, unsigned int color, int bpp)
{
    int	i;

	i = -1;
	while (++i < bpp)
	{
        if (color & (1 << i))
            addr[i / 8] |= (1 << (i % 8));
        else
            addr[i / 8] &= ~(1 << (i % 8));
    }
}

void	clean_exit(t_mlx *xwin, int errc)
{
	if (xwin->img)
		mlx_destroy_image(xwin->mlx, xwin->img);
	if (xwin->win)
		mlx_destroy_window(xwin->mlx, xwin->win);
	if (xwin->mlx)
	{
		mlx_destroy_display(xwin->mlx);
		free(xwin->mlx);
	}
	exit(errc);
}