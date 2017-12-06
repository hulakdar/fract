/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:32:37 by skamoza           #+#    #+#             */
/*   Updated: 2017/12/06 17:56:54 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fract_draw(t_map *map)
{
	double MinRe = -2.0;
	double MaxRe = 1.0;
	double MinIm = -1.2;
	double MaxIm = MinIm+(MaxRe-MinRe)*HEIGHT/WIDTH;
	double Re_factor = (MaxRe-MinRe)/(WIDTH-1);
	double Im_factor = (MaxIm-MinIm)/(HEIGHT-1);
	unsigned MaxIterations = 3000;
	for(unsigned y=0; y<HEIGHT; ++y)
	{
		double c_im = MaxIm - y*Im_factor;
		for(unsigned x=0; x<WIDTH; ++x)
		{
			double c_re = MinRe + x*Re_factor;
			double Z_re = c_re, Z_im = c_im;
			unsigned n;
			for(n=0; n<MaxIterations; ++n)
			{
				double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
				if(Z_re2 + Z_im2 > 4)
					break;
				Z_im = 2*Z_re*Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
			}
			map->image[x + (y * map->size_line >> 2)] = ((double)n / MaxIterations * 0x90a0);
		}
	}
	mlx_put_image_to_window(map->mlx, map->window, map->image_ptr, 0, 0);
}
