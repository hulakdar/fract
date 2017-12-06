/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:15:28 by skamoza           #+#    #+#             */
/*   Updated: 2017/12/06 17:47:44 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#ifndef FRACTOL_H
# define FRACTOL_H
# define HEIGHT 1000
# define WIDTH 1000
# include <mlx.h>
# include <pthread.h>
# include <math.h>
# include <limits.h>
# include "libft/includes/libft.h"

typedef struct	s_pixel
{
	int			x;
	int			y;
	int			color;
}				t_pixel;
typedef struct	s_map
{
	void		*image_ptr;
	int			*image;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	void		*mlx;
	void		*window;
}				t_map;

void			fract_error(char *error, t_map *parameter);
void			fract_usage(void);
int				fract_to_rgb(int n, int iter);
void			fract_center(t_map *map);
void			fract_draw(t_map *parameter);
int				fract_key(int keycode, t_map *parameter);
int				fract_exit_x(t_map *parameter);
void			fract_destruct(t_map *map);
#endif
