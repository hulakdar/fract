/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:32:37 by skamoza           #+#    #+#             */
/*   Updated: 2017/12/14 20:30:05 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fract_zoom(int keycode, int x, int y, t_map *map)
{
	t_complex	c;
	t_complex	new;

	c.im = map->fract.max.im - y * map->fract.factor.im;
	c.real = map->fract.min.real + x * map->fract.factor.real;
	if (__builtin_expect((keycode == 4), 1))
	{
		new.real = (map->fract.max.real - map->fract.min.real) * 1.19;
		new.im = (map->fract.max.im - map->fract.min.im) * 1.19;
		map->fract.MaxIterations = fabs(map->fract.MaxIterations * 0.99 - 2);
	}
	else
	{
		new.real = (map->fract.max.real - map->fract.min.real) * 0.89;
		new.im = (map->fract.max.im - map->fract.min.im) * 0.89;
		map->fract.MaxIterations = fabs(map->fract.MaxIterations * 1.02 + 2);
	}
	map->fract.min.im = c.im - new.im * (double)(HEIGHT - y) / (double)HEIGHT;
	map->fract.min.real = c.real - new.real * ((double)x / WIDTH);
	map->fract.max.im = map->fract.min.im + new.im;
	map->fract.max.real = map->fract.min.real + new.real;
	map->fract.factor.real = new.real / WIDTH;
	map->fract.factor.im = new.im / HEIGHT;
}

double	fract_iterate(t_fract fract, t_complex c)
{
	t_complex	z;
	t_complex	z2;
	unsigned	n;

	n = 0;
	z = c;
	if (fract.is_julia)
		c = fract.k;
	while (n++ < fract.MaxIterations)
	{
		z2.real = z.real * z.real;
		z2.im = z.im * z.im;
		if(z2.real + z2.im > 4.0)
			break ;
		z = fract.plot(z, z2, c);
	}
	return ((double)n / (double)fract.MaxIterations);
}

void	*thread_the_fract(t_chunk *param)
{
	int			x;
	int			y;
	t_complex	c;
	t_fract		fract;

	y = param->y;
	fract = param->map->fract;
	while (y < param->ceil)
	{
		x = 0;
		c.im = fract.max.im - y * fract.factor.im;
		while (x < WIDTH)
		{
			c.real = fract.min.real + x * fract.factor.real;
			param->map->image[(y * (param->map->size_line >> 2)) + x] =
		fract_inter(fract_iterate(param->map->fract, c), param->map->offset);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	fract_draw(t_map *map)
{
	unsigned	y;
	int			i;
	pthread_t	threads[THREADS];
	t_chunk		chunks[THREADS];

	y = 0;
	i = 0;
	while (i < THREADS)
	{
		chunks[i].map = map;
		chunks[i].y = y;
		y += HEIGHT / THREADS;
		chunks[i].ceil = y;
		pthread_create(&threads[i], NULL,
				(void *(*)(void *))thread_the_fract, (void *)&chunks[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(map->mlx, map->window, map->image_ptr, 0, 0);
}
