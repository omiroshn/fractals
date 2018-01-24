/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:15:49 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/24 22:21:14 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	move_arrows(int key, t_info *i)
{
	if (key == MAC_ARROW_LEFT)
		i->minre -= 0.05 * i->dre;
	else if (key == MAC_ARROW_RIGHT)
		i->minre += 0.05 * i->dre;
	else if (key == MAC_ARROW_UP)
		i->minim += 0.05 * i->dre;
	else if (key == MAC_ARROW_DOWN)
		i->minim -= 0.05 * i->dre;
}

static void	iterations(int key, t_info *i)
{
	if (key == MAC_BUT_PLUS)
	{
		if (i->maxiterations < 50)
			i->maxiterations += 1;
		else if (i->maxiterations < 1000000000)
			i->maxiterations *= 1.05;
	}
	if (key == MAC_BUT_MINUS)
		if (i->maxiterations > 2)
			i->maxiterations *= 0.95;
}

int			key_function(int keycode, t_info *i)
{
	mlx_clear_window(i->map.mlx, i->map.win);
	if (keycode == MAC_ESC_BUT)
		exit_func(i);
	if (keycode == MAC_BUT_MINUS || keycode == MAC_BUT_PLUS)
		iterations(keycode, i);
	if (keycode > MAC_ARROW_LEFT - 1 && keycode < MAC_ARROW_UP + 1)
		move_arrows(keycode, i);
	if (keycode == MAC_SPACE)
		i->is_julia = -(i->is_julia);
	if (keycode == MAC_BUT_R)
		reset(i);
	if (keycode == MAC_BUT_1)
		i->offset = 0;
	if (keycode == MAC_BUT_2)
		i->offset = 1;
	if (keycode == MAC_BUT_3)
		i->offset = 2;
	threads_crete(i);
	return (0);
}

int			mouse_hook(int mousecode, int x, int y, t_info *i)
{
	double	re;
	double	im;

	if (mousecode == 4 || mousecode == 5)
	{
		re = i->minre + ((double)x / WIDTH) * i->dre;
		im = i->minim + ((HEIGHT - (double)y) / HEIGHT) * i->dre;
		if (mousecode == 4)
		{
			i->dre *= 0.9;
			if (i->maxiterations < 1000000000)
				i->maxiterations += 3;
		}
		if (mousecode == 5)
		{
			i->dre *= 1.1;
			if (i->maxiterations > 50)
				i->maxiterations -= 3;
		}
		i->minre = re - ((double)x / WIDTH) * i->dre;
		i->minim = im - ((HEIGHT - (double)y) / HEIGHT) * i->dre;
	}
	threads_crete(i);
	return (0);
}

int			julia_motion(int x, int y, t_info *i)
{
	if (i->is_julia == -1)
		return (0);
	i->k_re = ((double)x - WIDTH / 2) / (WIDTH << 1);
	i->k_im = ((double)y - HEIGHT / 2) / (HEIGHT << 1);
	threads_crete(i);
	return (0);
}
