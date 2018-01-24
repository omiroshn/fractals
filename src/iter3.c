/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:30:57 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/24 18:32:08 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	iter_celtic_perpend(t_info *i)
{
	while (i->n < i->maxiterations)
	{
		i->z_re2 = i->z_re * i->z_re;
		i->z_im2 = i->z_im * i->z_im;
		if (i->z_re2 + i->z_im2 > 4)
			break ;
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
			break ;
		i->z_im = i->z_re * fabs(i->z_im) * -2.0 + i->c_im;
		i->z_re = fabs(i->z_re2 - i->z_im2) + i->c_re;
		i->n++;
	}
}
