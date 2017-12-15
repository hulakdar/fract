/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:15:28 by skamoza           #+#    #+#             */
/*   Updated: 2017/12/14 21:00:25 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#ifndef FRACTOL_H
# define FRACTOL_H
# define THREADS 2
# define HEIGHT 700
# define WIDTH 700
# include <mlx.h>
# include <pthread.h>
# include <math.h>
# include <limits.h>
# include "libft/includes/libft.h"
# define NUM_1 83
# define NUM_2 84
# define NUM_3 85

typedef unsigned char t_byte;
typedef union	u_color
{
	int			color;
	t_byte		channel[4];
}				t_color;
typedef struct	s_complex
{
	double		real;
	double		im;
}				t_complex;
typedef struct	s_fract
{
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	long long	MaxIterations;
	t_complex	(*plot)(t_complex, t_complex, t_complex);
	t_complex	k;
	int			is_julia;
}				t_fract;
typedef struct	s_map
{
	void		*image_ptr;
	int			*image;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			offset;
	void		*mlx;
	void		*window;
	t_fract		fract;
}				t_map;
typedef struct	s_chunk
{
	int			y;
	int			ceil;
	t_map		*map;
}				t_chunk;
void			fract_error(char *error, t_map *parameter);
void			fract_usage(void);
void			fract_zoom(int keycode, int x, int y, t_map *map);
int				fract_inter(double t, int offset);
void			fract_draw(t_map *parameter);
int				fract_key(int keycode, t_map *parameter);
int				fract_exit_x(t_map *parameter);
void			fract_destruct(t_map *map);
void			fract_mandel_init(t_map *map);
void			fract_4th_mandel_init(t_map *map);
void			fract_4th_bs_init(t_map *map);
void			fract_4th_mandelbar_init(t_map *map);
void			fract_quazi_heart_init(t_map *map);
void			fract_cubic_mandel_init(t_map *map);
void			fract_part_cubic_bs_init(t_map *map);
void			fract_cubic_bs_init(t_map *map);
void			fract_ship_init(t_map *map);
void			fract_tomandel_init(t_map *map);
void			fract_julia_init(t_map *map);
void			fract_cubic_mandel_init(t_map *map);
void			fract_cubic_mandelbar_init(t_map *map);
void			fract_ship_init(t_map *map);
t_complex		fract_4th_bs(t_complex z, t_complex z2, t_complex c);
t_complex		fract_4th_mandelbar(t_complex z, t_complex z2, t_complex c);
t_complex		fract_4th_mandel(t_complex z, t_complex z2, t_complex c);
t_complex		fract_quazi_heart(t_complex z, t_complex z2, t_complex c);
t_complex		fract_mandel(t_complex, t_complex, t_complex);
t_complex		fract_cubic_mandel(t_complex, t_complex, t_complex);
t_complex		fract_cubic_bs(t_complex, t_complex, t_complex);
t_complex		fract_part_cubic_bs(t_complex, t_complex, t_complex);
t_complex		fract_cubic_mandelbar(t_complex, t_complex, t_complex);
t_complex		fract_bs(t_complex, t_complex, t_complex);
t_complex		fract_julia(t_complex, t_complex, t_complex);
#endif
