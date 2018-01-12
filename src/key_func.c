/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:15:49 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/12 18:10:17 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		key_function(int keycode, void *param)
{
	t_info *i;

	i = (t_info *)param;
	mlx_clear_window(i->map.mlx, i->map.win);
	if (keycode == MAC_ESC_BUT)
		exit_func(i);
	else if (keycode == MAC_BUT_PLUS)
		i->maxiterations += 1;
	else if (keycode == MAC_BUT_MINUS)
		i->maxiterations -= 1;
	else if (keycode == MAC_ARROW_LEFT)
		i->moveX -= 0.02;
	else if (keycode == MAC_ARROW_RIGHT)
		i->moveX += 0.02;
	else if (keycode == MAC_ARROW_UP)
		i->moveY -= 0.02;
	else if (keycode == MAC_ARROW_DOWN)
		i->moveY += 0.02;
	else if (keycode == MAC_BUT_1)
	{
		i->zoom *= 1.02;
		//i->maxiterations = fabs(i->maxiterations * 1.01 + 2);
	}
	else if (keycode == MAC_BUT_2)
	{
		i->zoom *= 0.98;
		// i->maxiterations = fabs(i->maxiterations * 0.99 - 2);
	}
	draw(i);
	printf("%i\n", keycode);
	return (0);
}
