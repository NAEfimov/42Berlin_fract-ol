/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:19:45 by nefimov           #+#    #+#             */
/*   Updated: 2025/03/04 19:13:27 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "main.h"
#include "libft.h"

void	read_args(int argc, char *argv[], t_mlx *xwin)
{
	if (argc == 4 && ft_strcmp(argv[1], "Julia") == 0)
	{
		xwin->get_fractal_color = get_julia_color;
		if (read_double(argv[2], &xwin->c_r) || (xwin->c_r > MAX_C)
			|| (xwin->c_r < MIN_C))
			print_wrong_args();
		if (read_double(argv[3], &xwin->c_i) || (xwin->c_i > MAX_C)
			|| (xwin->c_i < MIN_C))
			print_wrong_args();
	}
	else if (argc == 2 && ft_strcmp(argv[1], "Mandelbrot") == 0)
	{
		xwin->get_fractal_color = get_mandelbrot_color;
		xwin->c_r = 0;
		xwin->c_i = 0;
	}
	else if (argc == 2 && ft_strcmp(argv[1], "Tricorn") == 0)
	{
		xwin->get_fractal_color = get_tricorn_color;
		xwin->c_r = 0;
		xwin->c_i = 0;
	}
	else
		print_wrong_args();
}

int	read_double(char *str, double *read)
{
	int		sign;
	double	i;

	sign = 1;
	*read = 0.0;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (*str >= '0' && *str <= '9')
		*read = *read * 10.0 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		i = 1.0;
		while (*str >= '0' && *str <= '9')
			*read += (*str++ - '0') / pow(10.0, i++);
	}
	if (*str != '\0')
		return (1);
	*read *= sign;
	return (0);
}

void	print_wrong_args(void)
{
	ft_putstr_fd("Available parameters:\n", 1);
	ft_putstr_fd("1) Julia <r> <i> ", 1);
	ft_putstr_fd("(where c_r and c_i should be in a range [-2; 2])\n", 1);
	ft_putstr_fd("2) Mandelbrot\n", 1);
	ft_putstr_fd("3) Tricorn\n", 1);
	exit(0);
}
