/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:46:51 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/24 22:04:05 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static int		fract_inter(double t, int offset)
{
	t_color color;

	if (t > 1.0)
		t = 1.0;
	color.channel[(2 + offset) % 3] = (t_byte)(9 * (1 - t) * t * t * t * 255);
	color.channel[(1 + offset) % 3] =
	(t_byte)(15 * (1 - t) * (1 - t) * t * t * 255);
	color.channel[(0 + offset) % 3] =
	(t_byte)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	color.channel[3] = 0;
	return (color.color);
}

void			draw(t_info *i)
{
	i->y = i->cunt;
	while (i->y < i->end)
	{
		i->c_im = i->minim + (WIDTH - i->y) * i->im_factor;
		i->x = 0;
		while (i->x < HEIGHT)
		{
			i->c_re = i->minre + i->x * i->re_factor;
			i->z_im = i->c_im;
			i->z_re = i->c_re;
			i->n = 0;
			i->func(i);
			i->bright =
			fract_inter(((double)i->n / i->maxiterations), i->offset);
			if (i->n == i->maxiterations)
				i->bright = 0;
			i->pix = (i->x + i->y * WIDTH);
			i->map.image[i->pix] = i->bright;
			i->x++;
		}
		i->y++;
	}
}

void			threads_crete(t_info *in)
{
	pthread_t	threads[THREADS];
	t_info		info[THREADS];
	unsigned	y;
	int			i;
	char		*str;

	in->re_factor = in->dre / (WIDTH - 1);
	in->im_factor = in->dre / (HEIGHT - 1);
	i = -1;
	y = 0;
	while (++i < THREADS)
	{
		info[i] = *in;
		info[i].cunt = y;
		y += HEIGHT / THREADS;
		info[i].end = y;
		pthread_create(&threads[i], NULL,
								(void *(*)(void *))draw, (void *)&info[i]);
	}
	while (i-- > 0)
		in->map.status = pthread_join(threads[i], (void**)&in->map.status_addr);
	mlx_put_image_to_window(in->map.mlx, in->map.win, in->map.image_ptr, 0, 0);
	mlx_string_put(in->map.mlx, in->map.win, 10, 10, 0xFF0000,
								(str = ft_itoa(in->maxiterations)));
	ft_strdel(&str);
}
