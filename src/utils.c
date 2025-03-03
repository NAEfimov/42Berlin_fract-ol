/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:52:46 by nefimov           #+#    #+#             */
/*   Updated: 2025/03/03 19:53:46 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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