/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:58:22 by nefimov           #+#    #+#             */
/*   Updated: 2025/03/03 23:28:45 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>

#ifndef MAIN_H
# define MAIN_H

# define SX 		900
# define SY 		600
# define MAX_ITER 	255

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bpp;
	int		sl;
	int		endian;
	char	*img_addr;
	double	zoom;
	double	moveX;
	double	moveY;
	double	c_r;
	double	c_i;		
}	t_mlx;

int		int_color(unsigned char r, unsigned char g, unsigned char b);
void	set_bits(char *addr, unsigned int color, int bpp);

int 	get_julia_color(t_mlx *xwin, double x, double y);
int 	get_mandelbrot_color(t_mlx *xwin, double x, double y);
void	draw_fractal(t_mlx *xwin);

#endif