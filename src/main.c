/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:51:57 by nefimov           #+#    #+#             */
/*   Updated: 2025/03/04 17:31:26 by nefimov          ###   ########.fr       */
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