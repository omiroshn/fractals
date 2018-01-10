/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:24:30 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/07 20:12:42 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# define WIDTH 800
# define HEIGHT 800

# define MAP(value, istart, iend, ostart, oend) (ostart + (oend - ostart) * ((value - istart) / (iend - istart)))

# define MAC_ESC_BUT 53
# define MAC_BUT_MINUS 78
# define MAC_BUT_PLUS 69

# define LINUX_ESC_BUT 65307
# define LINUX_BUT_MINUS 45
# define LINUX_BUT_PLUS 61

# include "libft/includes/libft.h"
# include <math.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>

typedef	struct	s_mapinfo
{
	void		*mlx;
	void		*win;
	void		*image_ptr;
	int			*image;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			maxiterations;
	int			maxiterations_const;
}				t_mapinfo;

void	init(t_mapinfo *map, char *str);
void	init_fract_tree(t_mapinfo *map);
void	init_mandelbrot(t_mapinfo *map);
void	init_julia(t_mapinfo *map);
void	draw_mandelbrot(t_mapinfo *map);
void	draw_fract_tree(t_mapinfo *map);
void	draw_julia(t_mapinfo *map);
int		exit_func(void *param);
int		key_function(int keycode, void *param);

#endif