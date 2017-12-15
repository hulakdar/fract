/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:47:00 by skamoza           #+#    #+#             */
/*   Updated: 2017/12/14 20:32:16 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fract_mouse(int keycode, int x, int y, t_map *map)
{
	if (keycode == 5 || keycode == 4)
		fract_zoom(keycode, x, y, map);
	fract_draw(map);
	return (0);
}

void	fract_init(t_map *map)
{
	if (!(map->window = mlx_new_window(map->mlx,
					WIDTH, HEIGHT, "skamoza's fractol")))
		fract_error("Something went completely wrong", map);
	map->image_ptr = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	map->image = (int *)mlx_get_data_addr(map->image_ptr, &map->bits_per_pixel,
										&map->size_line, &map->endian);
	mlx_hook(map->window, 2, 5, fract_key, map);
	mlx_hook(map->window, 17, 1L << 17, fract_exit_x, map);
	mlx_mouse_hook(map->window, (int (*)())fract_mouse, map);
	map->offset = 0;
}

int		fract_match(char *str, t_map *map)
{
	if (ft_strequ(str, "mandelbrot"))
		fract_mandel_init(map);
	else if (ft_strequ(str, "julia"))
		fract_julia_init(map);
	else if (ft_strequ(str, "bs"))
		fract_ship_init(map);
	else if (ft_strequ(str, "cubic_bs"))
		fract_cubic_bs_init(map);
	else if (ft_strequ(str, "cubic_mandelbar"))
		fract_cubic_mandelbar_init(map);
	else if (ft_strequ(str, "4th_mandelbrot"))
		fract_4th_mandel_init(map);
	else if (ft_strequ(str, "4th_mandelbar"))
		fract_4th_mandelbar_init(map);
	else if (ft_strequ(str, "4th_bs"))
		fract_4th_bs_init(map);
	else if (ft_strequ(str, "quazi_heart"))
		fract_quazi_heart_init(map);
	else if (ft_strequ(str, "part_cubic_bs"))
		fract_part_cubic_bs_init(map);
	else
		return (0);
	return (1);
}

int		fract_parse(int argc, char **argv, t_map *maps, void *mlx)
{
	int	cunt;
	int	i;

	cunt = 1;
	i = 0;
	while (cunt < argc)
	{
		if (fract_match(argv[cunt], &maps[i]))
			i++;
		else
			return (0);
		cunt++;
	}
	while (i-- > 0)
	{
		maps[i].mlx = mlx;
		fract_init(&maps[i]);
		fract_draw(&maps[i]);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	static t_map	maps[10];
	void			*mlx;

	if (!(mlx = mlx_init()))
		fract_error("Something went completely wrong", NULL);
	if (argc < 2 || !fract_parse(argc, argv, &maps[0], mlx))
		fract_usage();
	mlx_loop(mlx);
}
