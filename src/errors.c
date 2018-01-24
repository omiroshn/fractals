/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:15:27 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/24 22:08:29 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		exit_func(void *param)
{
	param = NULL;
	exit(0);
}

void	options(void)
{
	ft_putendl("Usage : ./fractol <name>");
	ft_putendl("                  mandelbrot");
	ft_putendl("                  julia");
	ft_putendl("                  bs");
	ft_putendl("                  bs_cubic");
	ft_putendl("                  bs_perpend");
	ft_putendl("                  mandelbar3");
	ft_putendl("                  mandelbar4");
	ft_putendl("                  mandelbar5");
	ft_putendl("                  perp_mandelbrot");
	ft_putendl("                  celtic_mandelbar");
	ft_putendl("                  celtic_perpend");
	ft_putendl("                  perpend_buffalo");
	ft_putendl("Or you can just copy that:");
	ft_putstr("./fractol mandelbrot julia bs bs_cubic bs_perpend ");
	ft_putstr("mandelbar3 mandelbar4 mandelbar5 perp_mandelbrot ");
	ft_putstr("celtic_mandelbar celtic_perpend perpend_buffalo\n");
	exit(0);
}

void	options2(void)
{
	ft_putendl("Error. You can't enter more, than 12 fractols");
	ft_putendl("Try again by ./fractol <name>");
	exit(0);
}
