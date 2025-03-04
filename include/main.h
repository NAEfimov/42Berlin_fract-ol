/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:58:22 by nefimov           #+#    #+#             */
/*   Updated: 2025/03/04 12:35:35 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "keys.h"

#ifndef MAIN_H
# define MAIN_H

# define SX 		900
# define SY 		600
# define MAX_ITER 	255
# define JULIA		0
# define MANDELBROT	1
# define MOVE_INC	0.03
# define ZOOM_INC	0.1

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bpp;
	int		sl;
	int		endian;
	char	*img_addr;
	char	f_type;
	int		(*get_fractal_color)(struct s_mlx *xwin, double x, double y);
	double	asp_ratio;
	double	zoom;
	double	moveX;
	double	moveY;
	double	c_r;
	double	c_i;
}	t_mlx;

int		init_mlx(t_mlx *xwin);
int		int_color(unsigned char r, unsigned char g, unsigned char b);
void	set_bits(char *addr, unsigned int color, int bpp);
void	clean_exit(t_mlx *xwin, int errc);

int 	get_julia_color(t_mlx *xwin, double x, double y);
int 	get_mandelbrot_color(t_mlx *xwin, double x, double y);
int		get_tricorn_color(t_mlx *xwin, double x, double y);
void	draw_fractal(t_mlx *xwin);

int		key_win(int keycode,void *param);
int		mouse_win(int button,int x,int y,void *param);
int		close_window(void *param);

#endif