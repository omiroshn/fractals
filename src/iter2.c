/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:30:53 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/24 18:31:56 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	iter_perp_mand(t_info *i)
{
	while (i->n < i->maxiterations)
	{
		i->z_re2 = i->z_re * i->z_re;
		i->z_im2 = i->z_im * i->z_im;
		if (i->z_re2 + i->z_im2 > 4)
			break ;
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
			break ;
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
			break ;
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
			break ;
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
			break ;
		i->z_im = i->z_re * fabs(i->z_im) * -2.0 + i->c_im;
		i->z_re = i->z_re2 - i->z_im2 + i->c_re;
		i->n++;
	}
}
