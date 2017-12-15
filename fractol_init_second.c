/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_second.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <skamoza@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:42:45 by skamoza           #+#    #+#             */
/*   Updated: 2017/12/14 19:46:38 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fract_cubic_mandelbar_init(t_map *map)
{
	t_fract fract;

	fract.min.im = -2.0;
	fract.max.im = 2.0;
	fract.min.real = -2.0;
	fract.max.real = 2.0;
	fract.factor.real = (fract.max.real - fract.min.real) / WIDTH;
	fract.factor.im = (fract.max.im - fract.min.im) / HEIGHT;
	fract.MaxIterations = 50;
	fract.is_julia = 0;
	fract.plot = fract_cubic_mandelbar;
	map->fract = fract;
}

void	fract_4th_mandel_init(t_map *map)
{
	t_fract fract;

	fract.min.im = -2.0;
	fract.max.im = 2.0;
	fract.min.real = -2.0;
	fract.max.real = 2.0;
	fract.factor.real = (fract.max.real - fract.min.real) / WIDTH;
	fract.factor.im = (fract.max.im - fract.min.im) / HEIGHT;
	fract.MaxIterations = 50;
	fract.is_julia = 0;
	fract.plot = fract_4th_mandel;
	map->fract = fract;
}

void	fract_4th_mandelbar_init(t_map *map)
{
	t_fract fract;

	fract.min.im = -2.0;
	fract.max.im = 2.0;
	fract.min.real = -2.0;
	fract.max.real = 2.0;
	fract.factor.real = (fract.max.real - fract.min.real) / WIDTH;
	fract.factor.im = (fract.max.im - fract.min.im) / HEIGHT;
	fract.MaxIterations = 50;
	fract.is_julia = 0;
	fract.plot = fract_4th_mandelbar;
	map->fract = fract;
}

void	fract_4th_bs_init(t_map *map)
{
	t_fract fract;

	fract.min.im = -2.0;
	fract.max.im = 2.0;
	fract.min.real = -2.0;
	fract.max.real = 2.0;
	fract.factor.real = (fract.max.real - fract.min.real) / WIDTH;
	fract.factor.im = (fract.max.im - fract.min.im) / HEIGHT;
	fract.MaxIterations = 50;
	fract.is_julia = 0;
	fract.plot = fract_4th_bs;
	map->fract = fract;
}

void	fract_quazi_heart_init(t_map *map)
{
	t_fract fract;

	fract.min.im = -2.0;
	fract.max.im = 2.0;
	fract.min.real = -2.0;
	fract.max.real = 2.0;
	fract.factor.real = (fract.max.real - fract.min.real) / WIDTH;
	fract.factor.im = (fract.max.im - fract.min.im) / HEIGHT;
	fract.MaxIterations = 50;
	fract.is_julia = 0;
	fract.plot = fract_quazi_heart;
	map->fract = fract;
}

void	fract_part_cubic_bs_init(t_map *map)
{
	t_fract fract;

	fract.min.im = -2.0;
	fract.max.im = 2.0;
	fract.min.real = -2.0;
	fract.max.real = 2.0;
	fract.factor.real = (fract.max.real - fract.min.real) / WIDTH;
	fract.factor.im = (fract.max.im - fract.min.im) / HEIGHT;
	fract.MaxIterations = 50;
	fract.is_julia = 0;
	fract.plot = fract_part_cubic_bs;
	map->fract = fract;
}
