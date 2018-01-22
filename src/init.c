/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:15:39 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/22 19:16:55 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	iter_mandelbrot(t_info *i)
{
	while (i->n < i->maxiterations)
	{
		i->z_re2 = i->z_re * i->z_re;
		i->z_im2 = i->z_im * i->z_im;
		if (i->z_re2 + i->z_im2 > 4)
			break;
		i->z_im = 2 * i->z_re * i->z_im + i->c_im;
		i->z_re = i->z_re2 - i->z_im2 + i->c_re;
		i->n++;
	}
}

void	iter_julia(t_info *i)
{
	while (i->n < i->maxiterations)
	{
		i->z_re2 = i->z_re * i->z_re;
		i->z_im2 = i->z_im * i->z_im;
		if (i->z_re2 + i->z_im2 > 4)
			break;
		i->z_im = 2 * i->z_re * i->z_im + i->k_im;
		i->z_re = i->z_re2 - i->z_im2 + i->k_re;
		i->n++;
	}
}

void	iter_mandelbar3(t_info *i)
{
	while (i->n < i->maxiterations)
	{
		i->z_re2 = i->z_re * i->z_re;
		i->z_im2 = i->z_im * i->z_im;
		if (i->z_re2 + i->z_im2 > 4)
			break;
		i->z_im = i->z_re * i->z_im * -2.0 + i->c_im;
		i->z_re = i->z_re2 - i->z_im2 + i->c_re;
		i->n++;
	}
}

void	iter_mandelbar4(t_info *i)
{
	while (i->n < i->maxiterations)
	{
		i->z_re2 = i->z_re * i->z_re;
		i->z_im2 = i->z_im * i->z_im;
		if (i->z_re2 + i->z_im2 > 4)
			break;
		i->z_im = (i->z_re2 * 3.0 - i->z_im2) * i->z_im + i->c_im;
		i->z_re = -(i->z_re2 - i->z_im2 * 3.0) * i->z_re + i->c_re;
		i->n++;
	}
}

void	iter_mandelbar5(t_info *i)
{
	while (i->n < i->maxiterations)
	{
		i->z_re2 = i->z_re * i->z_re;
		i->z_im2 = i->z_im * i->z_im;
		if (i->z_re2 + i->z_im2 > 4)
			break;
		i->z_im = -4 * i->z_re * i->z_im * (i->z_re2 - i->z_im2) + i->c_im;
		i->z_re = i->z_re2 * i->z_re2 + i->z_im2 * i->z_im2 - 6 * i->z_re2 * i->z_im2 + i->c_re;
		i->n++;
	}
}

void	iter_perp_mand(t_info *i)
{
	while (i->n < i->maxiterations)
	{
		i->z_re2 = i->z_re * i->z_re;
		i->z_im2 = i->z_im * i->z_im;
		if (i->z_re2 + i->z_im2 > 4)
			break;
		i->z_im = fabs(i->z_re) * i->z_im * -2.0 + i->c_im;
		i->z_re = i->z_re2 - i->z_im2 + i->c_re;
		i->n++;
	}
}

void	iter_celtic_mand(t_info *i)
{
	while (i->n < i->maxiterations)
	{
		i->z_re2 = i->z_re * i->z_re;
		i->z_im2 = i->z_im * i->z_im;
		if (i->z_re2 + i->z_im2 > 4)
			break;
		i->z_im = i->z_re * i->z_im * -2.0 + i->c_im;
		i->z_re = fabs(i->z_re2 - i->z_im2) + i->c_re;
		i->n++;
	}
}

void	iter_burning_ship(t_info *i)
{
	while (i->n < i->maxiterations)
	{
		i->z_re2 = i->z_re * i->z_re;
		i->z_im2 = i->z_im * i->z_im;
		if (i->z_re2 + i->z_im2 > 4)
			break;
		i->z_im = fabs(i->z_re * i->z_im) * -2.0 + i->c_im;
		i->z_re = i->z_re2 - i->z_im2 + i->c_re;
		i->n++;
	}
}

void	iter_cubic_burning_ship(t_info *i)
{
	while (i->n < i->maxiterations)
	{
		i->z_re2 = i->z_re * i->z_re;
		i->z_im2 = i->z_im * i->z_im;
		if (i->z_re2 + i->z_im2 > 4)
			break;
		i->z_im = -(i->z_re2 * 3.0 - i->z_im2) * fabs(i->z_im) + i->c_im;
		i->z_re = (i->z_re2 - i->z_im2 * 3.0) * fabs(i->z_re) + i->c_re;
		i->n++;
	}
}

void	iter_bs_perpend(t_info *i)
{
	while (i->n < i->maxiterations)
	{
		i->z_re2 = i->z_re * i->z_re;
		i->z_im2 = i->z_im * i->z_im;
		if (i->z_re2 + i->z_im2 > 4)
			break;
		i->z_im = i->z_re * fabs(i->z_im) * -2.0 + i->c_im;
		i->z_re = i->z_re2 - i->z_im2 + i->c_re;
		i->n++;
	}
}

void	iter_celtic_perpend(t_info *i)
{
	while (i->n < i->maxiterations)
	{
		i->z_re2 = i->z_re * i->z_re;
		i->z_im2 = i->z_im * i->z_im;
		if (i->z_re2 + i->z_im2 > 4)
			break;
		i->z_im = fabs(i->z_re) * i->z_im * -2.0 + i->c_im;
		i->z_re = fabs(i->z_re2 - i->z_im2) + i->c_re;
		i->n++;
	}
}

void	iter_perpend_buffalo(t_info *i)
{
	while (i->n < i->maxiterations)
	{
		i->z_re2 = i->z_re * i->z_re;
		i->z_im2 = i->z_im * i->z_im;
		if (i->z_re2 + i->z_im2 > 4)
			break;
		i->z_im = i->z_re * fabs(i->z_im) * -2.0 + i->c_im;
		i->z_re = fabs(i->z_re2 - i->z_im2) + i->c_re;
		i->n++;
	}
}


