/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:15:28 by skamoza           #+#    #+#             */
/*   Updated: 2017/12/12 21:15:45 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#ifndef FRACTOL_H
# define FRACTOL_H
# define THREADS 8
# define HEIGHT 1000
# define WIDTH 1000
# include <mlx.h>
# include <pthread.h>
# include <math.h>
# include <limits.h>
# include "libft/includes/libft.h"

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
}				t_fract;
typedef struct	s_map
{
	void		*image_ptr;
	int			*image;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
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
int				fract_inter(double t);
void			fract_draw(t_map *parameter);
int				fract_key(int keycode, t_map *parameter);
int				fract_exit_x(t_map *parameter);
void			fract_destruct(t_map *map);
void			fract_mandel_init(t_map *map);
void			fract_ship_init(t_map *map);
void			fract_tomandel_init(t_map *map);
void			fract_julia_init(t_map *map);
t_complex		fract_mandel(t_complex, t_complex, t_complex);
t_complex		fract_ship(t_complex, t_complex, t_complex);
t_complex		fract_tomandel(t_complex, t_complex, t_complex);
t_complex		fract_julia(t_complex, t_complex, t_complex);
#endif
