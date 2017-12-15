/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_plot_second.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <skamoza@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:47:00 by skamoza           #+#    #+#             */
/*   Updated: 2017/12/14 20:57:20 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	fract_4th_mandel(t_complex z, t_complex z2, t_complex c)
{
	z.im = 4 * z.real * z.im * (z2.real - z2.im) + c.im;
	z.real = z2.real * z2.real + z2.im * z2.im - 6 * z2.real * z2.im + c.real;
	return (z);
}

t_complex	fract_4th_mandelbar(t_complex z, t_complex z2, t_complex c)
{
	z.im = -4 * z.real * z.im * (z2.real - z2.im) + c.im;
	z.real = z2.real * z2.real + z2.im * z2.im - 6 * z2.real * z2.im + c.real;
	return (z);
}

t_complex	fract_4th_bs(t_complex z, t_complex z2, t_complex c)
{
	z.im = 4 * fabs(z.real * z.im) * (z2.real - z2.im) + c.im;
	z.real = z2.real * z2.real + z2.im * z2.im - 6 * z2.real * z2.im + c.real;
	return (z);
}

t_complex	fract_quazi_heart(t_complex z, t_complex z2, t_complex c)
{
	z.im = fabs(z2.real * 3.0 - z2.im) * z.im + c.im;
	z.real = (z2.real - z2.im * 3.0) * fabs(z.real) + c.real;
	return (z);
}

t_complex	fract_part_cubic_bs(t_complex z, t_complex z2, t_complex c)
{
	z.im = (z2.real * 3.0 - z2.im) * fabs(z.im) + c.im;
	z.real = -(z2.real - z2.im * 3.0) * z.real + c.real;
	return (z);
}
