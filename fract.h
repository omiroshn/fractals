/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:24:30 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/11 21:21:20 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# define WIDTH 800
# define HEIGHT 800
# define THREADS 16
# define DB(x) ((double)x)
# define MAP(x, y, z, a, b) (DB(a) + (DB(b) - DB(a)) * ((DB(x) - DB(y)) / (DB(z) - DB(y))))

# define MAC_ESC_BUT 53
# define MAC_BUT_MINUS 27
# define MAC_BUT_PLUS 24
# define MAC_ARROW_UP 126
# define MAC_ARROW_DOWN 125
# define MAC_ARROW_LEFT 123
# define MAC_ARROW_RIGHT 124
# define MAC_BUT_1 18
# define MAC_BUT_2 19

# define LINUX_ESC_BUT 65307
# define LINUX_BUT_MINUS 45
# define LINUX_BUT_PLUS 61
# define LINUX_ARROW_UP 65362
# define LINUX_ARROW_DOWN 65364
# define LINUX_ARROW_LEFT 65361
# define LINUX_ARROW_RIGHT 65363
# define LINUX_BUT_1 49
# define LINUX_BUT_2 50

# include "libft/includes/libft.h"
# include <math.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <pthread.h>

typedef struct	s_complex
{
	float		real;
	float		im;
}				t_complex;

typedef struct	s_fract
{
	t_complex	new_a;
	t_complex	new_b;
	t_complex	old_a;
	t_complex	old_b;
	long long	maxiterations;
	long long	maxiterations_const;
	float		moveX;
	float		moveY;
	float		zoom;
}				t_fract;

typedef	struct	s_mapinfo
{
	void		*mlx;
	void		*win;
	void		*image_ptr;
	int			*image;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_fract		fract;
}				t_mapinfo;

typedef struct	s_info
{
	unsigned	x;
	unsigned	end;
	t_mapinfo	*map;
}				t_info;

void	draw(t_mapinfo *map);
double	ft_map(double value, double istart, double iend, double ostart, double oend);
void	init(t_mapinfo *map, char *str);
void	init_fract_tree(t_mapinfo *map);
void	init_mandelbrot(t_mapinfo *map);
void	init_julia(t_mapinfo *map);
void	draw_mandelbrot(t_info *info);
void	draw_fract_tree(t_mapinfo *map);
void	draw_julia(t_mapinfo *map);
int		exit_func(void *param);
int		key_function(int keycode, void *param);

#endif