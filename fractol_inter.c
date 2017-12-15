/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_inter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <skamoza@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:04:39 by skamoza           #+#    #+#             */
/*   Updated: 2017/12/14 18:43:05 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fract_inter(double t, int offset)
{
	t_color color;

	if (t > 1.0)
		t = 1.0;
	color.channel[(2 + offset) % 3] = (t_byte)(9 * (1 - t) * t * t * t * 255);
 	color.channel[(1 + offset) % 3] = (t_byte)(15 * (1 - t)
													* (1 - t) * t * t * 255);
 	color.channel[(0 + offset) % 3] = (t_byte)(8.5 * (1 - t) *
												(1 - t) * (1 - t) * t * 255);
	color.channel[3] = 0;
	return (color.color);
}
