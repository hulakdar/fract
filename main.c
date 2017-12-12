/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:47:00 by skamoza           #+#    #+#             */
/*   Updated: 2017/12/12 21:15:46 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fract_parse(int argc, char **argv)
{
	printf("%d %s\n", argc, argv[1]);
	return (1);
}

int		fract_mouse(int keycode, int x, int y, t_map *map)
{
	if (keycode == 5 || keycode == 4)
		fract_zoom(keycode, x, y, map);
	fract_draw(map);
	return (0);
}

void	fract_init(t_map *map)
{
	if (!(map->mlx = mlx_init()))
		fract_error("Something went completely wrong", map);
	if (!(map->window = mlx_new_window(map->mlx,
					WIDTH, HEIGHT, "skamoza's fractol")))
		fract_error("Something went completely wrong", map);
	map->image_ptr = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	map->image = (int *)mlx_get_data_addr(map->image_ptr, &map->bits_per_pixel,
										&map->size_line, &map->endian);
	mlx_hook(map->window, 2, 5, fract_key, map);
	mlx_hook(map->window, 17, 1L << 17, fract_exit_x, map);
	mlx_mouse_hook(map->window, (int (*)())fract_mouse, map);
	fract_tomandel_init(map);
}

int		main(int argc, char **argv)
{
	t_map	map;

	if (argc < 2)
		fract_usage();
	if (!fract_parse(argc, argv))
		fract_usage();
	fract_init(&map);
	fract_draw(&map);
	mlx_loop(map.mlx);
}
