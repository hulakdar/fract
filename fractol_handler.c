/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:58:02 by skamoza           #+#    #+#             */
/*   Updated: 2017/12/12 21:15:45 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void	fract_destruct(t_map *map)
{
	mlx_destroy_image(map->mlx, map->image_ptr);
}

void	fract_error(char *error, t_map *parameter)
{
	ft_putendl(error);
	if (parameter)
		fract_destruct(parameter);
	exit(0);
}

void	fract_usage(void)
{
	ft_putendl("usage: ./fractol [mandelbrot, julia, multibrot, ship]");
	exit(0);
}

int		fract_key(int keycode, t_map *map)
{
	if (keycode == 53)
		fract_exit_x(map);
	if (keycode == 69)
	{
		map->fract.MaxIterations *= 1.02;
		map->fract.MaxIterations += 2;
		map->fract.MaxIterations = llabs(map->fract.MaxIterations);
	}
	if (keycode == 78)
	{
		map->fract.MaxIterations /= 1.02;
		map->fract.MaxIterations -= 2;
		map->fract.MaxIterations = llabs(map->fract.MaxIterations);
	}
	fract_draw(map);
	return (0);
}

int		fract_exit_x(t_map *parameter)
{
	fract_destruct(parameter);
	exit(0);
	return (0);
}
