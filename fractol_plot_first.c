/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_plot_first.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <skamoza@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:25:18 by skamoza           #+#    #+#             */
/*   Updated: 2017/12/14 20:57:14 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	fract_mandel(t_complex z, t_complex z2, t_complex c)
{
	z.im = z.real * 2.0 * z.im + c.im;
	z.real = z2.real - z2.im + c.real;
	return (z);
}

t_complex	fract_bs(t_complex z, t_complex z2, t_complex c)
{
	z.im = fabs(z.real * z.im) * (-2.0) + c.im;
	z.real = z2.real - z2.im + c.real;
	return (z);
}
t_complex	fract_julia(t_complex z, t_complex z2, t_complex c)
{
	z.im = z.real * 2.0 * z.im + c.im;
	z.real = z2.real - z2.im + c.real;
	return (z);
}

t_complex	fract_cubic_mandelbar(t_complex z, t_complex z2, t_complex c)
{
	z.im = (z2.real * 3.0 - z2.im) * z.im + c.im;
	z.real = -(z2.real - z2.im * 3.0) * z.real + c.real;
	return (z);
}

t_complex	fract_cubic_bs(t_complex z, t_complex z2, t_complex c)
{
	z.im = -(z2.real * 3.0 - z2.im) * fabs(z.im) + c.im;
	z.real = (z2.real - z2.im * 3.0) * fabs(z.real) + c.real;
	return (z);
}
