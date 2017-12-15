/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_first.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <skamoza@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:09:02 by skamoza           #+#    #+#             */
/*   Updated: 2017/12/14 21:08:16 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fract_mandel_init(t_map *map)
{
	t_fract fract;

	fract.min.im = -2.0;
	fract.max.im = 2.0;
	fract.min.real = -2.0;
	fract.max.real = 2.0;
	fract.factor.real = (fract.max.real - fract.min.real) / WIDTH;
	fract.factor.im = (fract.max.im - fract.min.im) / HEIGHT;
	fract.MaxIterations = 50;
	fract.plot = fract_mandel;
	fract.is_julia = 0;
	map->fract = fract;
}

void	fract_julia_init(t_map *map)
{
	t_fract fract;

	fract.min.im = -2.0;
	fract.max.im = 2.0;
	fract.min.real = -2.0;
	fract.max.real = 2.0;
	fract.factor.real = (fract.max.real - fract.min.real) / WIDTH;
	fract.factor.im = (fract.max.im - fract.min.im) / HEIGHT;
	fract.MaxIterations = 50;
	fract.k.real = 0.353;
	fract.k.im = 0.288;
	fract.is_julia = 1;
	fract.plot = fract_julia;
	map->fract = fract;
}


void	fract_ship_init(t_map *map)
{
	t_fract fract;

	fract.min.im = -2.0;
	fract.max.im = 2.0;
	fract.min.real = -2.0;
	fract.max.real = 2.0;
	fract.factor.real = (fract.max.real - fract.min.real) / WIDTH;
	fract.factor.im = (fract.max.im - fract.min.im) / HEIGHT;
	fract.is_julia = 0;
	fract.MaxIterations = 50;
	fract.plot = fract_bs;
	map->fract = fract;
}

void	fract_cubic_bs_init(t_map *map)
{
	t_fract fract;

	fract.min.im = -2.0;
	fract.max.im = 2.0;
	fract.min.real = -2.0;
	fract.max.real = 2.0;
	fract.factor.real = (fract.max.real - fract.min.real) / WIDTH;
	fract.factor.im = (fract.max.im - fract.min.im) / HEIGHT;
	fract.is_julia = 0;
	fract.MaxIterations = 50;
	fract.plot = fract_cubic_bs;
	map->fract = fract;
}
