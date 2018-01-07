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

# define WIDTH 1280
# define HEIGHT 1280

# define MAC_BUT_MINUS 78
# define MAC_BUT_PLUS 69

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

#endif