/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:27:42 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/10 23:01:10 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define WIDTH 1280
# define HEIGHT 1280
# define DWA_PI 2 * 3.141592
# define PI 3.141592
# define PI_2 3.141592 / 2

# define MAC_ESC_BUT 53
# define MAC_QUEST_BUT 44
# define MAC_ARROW_UP 126
# define MAC_ARROW_DOWN 125
# define MAC_ARROW_LEFT 123
# define MAC_ARROW_RIGHT 124
# define MAC_BUT_Z 6
# define MAC_BUT_X 7
# define MAC_BUT_MINUS 78
# define MAC_BUT_PLUS 69
# define MAC_BUT_W 13
# define MAC_BUT_A 0
# define MAC_BUT_S 1
# define MAC_BUT_D 2
# define MAC_BUT_1 18
# define MAC_BUT_2 19
# define MAC_BUT_P 35

# define LINUX_ESC_BUT 65307
# define LINUX_QUEST_BUT 47
# define LINUX_ARROW_UP 65362
# define LINUX_ARROW_DOWN 65364
# define LINUX_ARROW_LEFT 65361
# define LINUX_ARROW_RIGHT 65363
# define LINUX_BUT_Z 122
# define LINUX_BUT_X 120
# define LINUX_BUT_MINUS 45
# define LINUX_BUT_PLUS 61
# define LINUX_BUT_W 119
# define LINUX_BUT_A 97
# define LINUX_BUT_S 115
# define LINUX_BUT_D 100
# define LINUX_BUT_1 49
# define LINUX_BUT_2 50
# define LINUX_BUT_P 112

# include "libft/includes/libft.h"
# include <math.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>

/*
** math
** open
** read
** write, close
** malloc, free, exit
** perror
** strerror
** minilibx
*/

typedef	struct	s_vec
{
	float	x;
	float	y;
	float	z;
	float	w;
	int		color;
}				t_vec;

typedef struct	s_matrix4
{
	float		m[4][4];
}				t_matrix4;

typedef struct	s_persp_proj
{
	float angle_of_view;
	float image_aspect_ratio;
	float n;
	float f;
	float b;
	float t;
	float l;
	float r;
	float scale;
}				t_persp_proj;

typedef struct	s_bresenhem
{
	t_vec	start;
	t_vec	stop;
	int		err;
	int		err2;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		sx;
	int		sy;
	int		distx;
	int		disty;
}				t_bresenhem;

typedef	struct	s_mapinfo
{
	int			speed;
	int			turned_on;
	int			lines;
	int			values;
	int			quantity;
	int			**numbers;
	int			min_len_z;
	int			max_len_z;
	void		*mlx;
	void		*win;
	char		**map;
	char		**color;
	char		*lol;
	t_vec		*vec;
	t_vec		*vec_ch;
	float		angle_x;
	float		angle_y;
	float		angle_z;
	float		scale;
	float		offset_x;
	float		offset_y;
	float		offset_z;
}				t_mapinfo;

#endif
