/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:15:39 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/24 19:56:24 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	init_func(t_info *info, char **argv, int cunt, int i)
{
	if (ft_strequ(argv[cunt], "mandelbrot"))
		info[i].func = &iter_mandelbrot;
	else if (ft_strequ(argv[cunt], "julia"))
		info[i].func = &iter_julia;
	else if (ft_strequ(argv[cunt], "mandelbar3"))
		info[i].func = &iter_mandelbar3;
	else if (ft_strequ(argv[cunt], "mandelbar4"))
		info[i].func = &iter_mandelbar4;
	else if (ft_strequ(argv[cunt], "mandelbar5"))
		info[i].func = &iter_mandelbar5;
	else if (ft_strequ(argv[cunt], "perp_mandelbrot"))
		info[i].func = &iter_perp_mand;
	else if (ft_strequ(argv[cunt], "celtic_mandelbar"))
		info[i].func = &iter_celtic_mand;
	else if (ft_strequ(argv[cunt], "bs"))
		info[i].func = &iter_burning_ship;
	else if (ft_strequ(argv[cunt], "bs_cubic"))
		info[i].func = &iter_cubic_burning_ship;
	else if (ft_strequ(argv[cunt], "bs_perpend"))
		info[i].func = &iter_bs_perpend;
	else if (ft_strequ(argv[cunt], "celtic_perpend"))
		info[i].func = &iter_celtic_perpend;
	else if (ft_strequ(argv[cunt], "perpend_buffalo"))
		info[i].func = &iter_perpend_buffalo;
}

void	reset(t_info *i)
{
	i->minre = -2.0;
	i->minim = -2.0;
	i->dre = 4.0;
	i->maxiterations = 50;
	i->k_re = -0.4;
	i->k_im = 0.6;
	i->offset = 0;
}

void	init(char *name, t_info *i)
{
	i->name = name;
	i->maxiterations = 50;
	i->move_x = -0.5;
	i->move_y = 0;
	i->zoom = 1;
	i->minre = -2.0;
	i->minim = -2.0;
	i->dre = 4.0;
	i->is_julia = -1;
	i->k_im = 0.6;
	i->k_re = -0.4;
}
