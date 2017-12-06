/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:58:02 by skamoza           #+#    #+#             */
/*   Updated: 2017/12/06 17:06:59 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void	fract_destruct(t_map *map)
{
	printf("%d %d %d\n", map->endian, map->size_line, map->bits_per_pixel);
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
	ft_putendl("usage: ./fractol [mandelbrot, julia]");
	exit(0);
}

int		fract_key(int keycode, t_map *map)
{
	if (keycode == 53)
		fract_exit_x(map);
	printf("Keyboard: key %d", keycode);
	fract_draw(map);
	return (0);
}

int		fract_exit_x(t_map *parameter)
{
	fract_destruct(parameter);
	system("leaks fract");
	exit(0);
	return (0);
}
