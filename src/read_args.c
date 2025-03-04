/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:19:45 by nefimov           #+#    #+#             */
/*   Updated: 2025/03/04 14:29:07 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "libft.h"

void	read_args(int argc, char *argv[], t_mlx *xwin)
{
	double	i;

	if (argc == 4 && ft_strcmp(argv[1], "Julia") == 0)
	{
		ft_putstr_fd("Julia\n", 1);
		xwin->get_fractal_color = get_julia_color;
		
	}
	else if (argc == 2 && ft_strcmp(argv[1], "Mandelbrot") == 0)
	{
		ft_putstr_fd("Mandelbrot\n", 1);
		xwin->get_fractal_color = get_mandelbrot_color;
		xwin->c_r = 0;
		xwin->c_i = 0;
	}
	else if (argc == 2 && ft_strcmp(argv[1], "Tricorn") == 0)
	{
		ft_putstr_fd("Tricorn\n", 1);
		xwin->get_fractal_color = get_tricorn_color;
		xwin->c_r = 0;
		xwin->c_i = 0;
	}
	else
		print_wrong_args();
}

int	read_num(char *str, double *read)
{
		long int	num;
		double		sign;

		sign = 1.0;
		*read = 0.0;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				sign = -1.0;
			str++;
		}
		while (*str >= '0' && *str <= '9')
			*read = *read * 10.0 + (*str++ - '0');
		*read *= sign;
		sign = 0.0;
		if (*str == '.')
		{
			str++;
			sign = 0.0;
			while (*str >= '0' && *str <= '9')
				*read += (*str++ - '0') / pow(10.0, ++sign);
		}
		if (*str != '\0' || num < INT_MIN || num > INT_MAX)
			return (1);
		return (0);
}


void	print_wrong_args(void)
{
	ft_putstr_fd("Wrong args\n", 1);
	exit(1);
}