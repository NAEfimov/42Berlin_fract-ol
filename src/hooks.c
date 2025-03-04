/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:22:28 by nefimov           #+#    #+#             */
/*   Updated: 2025/03/04 19:10:42 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "keys.h"

int	key_win(int keycode, void *param)
{
	t_mlx	*xwin;

	xwin = (t_mlx *)param;
	if (keycode == KEY_ESC)
		clean_exit(param, 0);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		xwin->movex += MOVE_INC * (keycode % 10 - 2);
		draw_fractal(xwin);
	}
	else if (keycode == KEY_UP || keycode == KEY_DOWN)
	{
		xwin->movey += MOVE_INC * (keycode % 10 - 3);
		draw_fractal(xwin);
	}
	return (0);
}

int	mouse_win(int button, int x, int y, void *param)
{
	t_mlx	*xwin;

	xwin = (t_mlx *)param;
	(void)x;
	(void)y;
	if (button == BTN_SCROLL_UP)
	{
		xwin->zoom += ZOOM_INC;
		draw_fractal(xwin);
	}
	else if (button == BTN_SCROLL_DOWN)
	{
		xwin->zoom -= ZOOM_INC;
		draw_fractal(xwin);
	}
	return (0);
}

int	close_window(void *param)
{
	t_mlx	*xwin;

	xwin = (t_mlx *)param;
	clean_exit(xwin, 0);
	return (0);
}
