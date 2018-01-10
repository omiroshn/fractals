/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:26:45 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/07 21:12:03 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

float	ft_map(float value, float istart, float iend, float ostart, float oend)
{
    return (ostart + (oend - ostart) * ((value - istart) / (iend - istart)));
}

static inline int	rgba_to_int(int red, int green, int blue, int alpha)
{
	int r;
	int g;
	int b;
	int a;

	r = red & 0xFF;
	g = green & 0xFF;
	b = blue & 0xFF;
	a = alpha & 0xFF;
	return ((r << 24 | g << 16 | b << 8 | a));
}

void	draw_mandelbrot(t_mapinfo *map)
{
	int x;
	int y;
	float bright;
	float old_a;
	float old_b;
	int n;
	float new_a;
	float new_b;
	float ca;
	float cb;
	int pix;
	

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			

			old_a = ft_map(x, 0, WIDTH, -2, 2);
			old_b = ft_map(y, 0, HEIGHT, -2, 2);

			ca = old_a;
			cb = old_b;

			n = 0;
			while (n < map->maxiterations)
			{
				new_a = old_a * old_a - old_b * old_b;
				new_b = 2 * old_a * old_b;
				old_a = new_a + ca;
				old_b = new_b + cb;

				if (fabs(old_a + old_b) > 4)
					break;
				n++;
			}
			// bright = ft_map(n, 0, map->maxiterations, 0, 1);
			// bright = ft_map(sqrt(bright), 0, 1, 0, 0xFFFFFF);
			bright = (n * 16) % 255;
			if (n == map->maxiterations)
				bright = 0;
			pix = (x + y * WIDTH);
			map->image[pix] = bright;
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(map->mlx, map->win, map->image_ptr, 0, 0);
}

void	draw_julia(t_mapinfo *map)
{
	// int x;
	// int y;
	// float bright;
	// float a;
	// float b;
	// float n;
	// float aa;
	// float bb;
	// float ca;
	// float cb;
	// int pix;
	

	// x = 0;
	// while (x < WIDTH)
	// {
	// 	y = 0;
	// 	while (y < HEIGHT)
	// 	{
	// 		pix = (x + y * WIDTH);

	// 		a = ft_map(x, 0, WIDTH, -2, 2);
	// 		b = ft_map(y, 0, HEIGHT, -2, 2);

	// 		ca = a;
	// 		cb = b;

	// 		n = 0;
	// 		while (n < map->maxiterations)
	// 		{
	// 			aa = a * a - b * b;
	// 			bb = 2 * a * b;
	// 			a = aa + ca;
	// 			b = bb + cb;

	// 			if (fabs(a + b) > 16)
	// 				break;
	// 			n++;
	// 		}
	// 		//bright = ft_map(n, 0, 100, 0, 0xFFFFFF);
	// 		if (n == map->maxiterations)
	// 			map->image[pix] = 0;
	// 		else
	// 			map->image[pix] = sqrt(n / map->maxiterations);
			
			
	// 		y++;
	// 	}
	// 	x++;
	// }
	// mlx_put_image_to_window(map->mlx, map->win, map->image_ptr, 0, 0);
}

int		main(int argc, char *argv[])
{
	t_mapinfo map;

	if (argc != 2)
		ft_putendl("Usage : ./fractol <filename>");
	else
	{
		if (ft_strequ(argv[1], "tree"))
		{
			init_fract_tree(&map);
			draw_fract_tree(&map);
		}
		else if (ft_strequ(argv[1], "mand"))
		{
			init_mandelbrot(&map);
			draw_mandelbrot(&map);
		}
		else if (ft_strequ(argv[1], "julia"))
		{
			init_julia(&map);
			draw_julia(&map);
		}
		else
		{
			ft_putendl("Usage : ./fractol <filename>\n<tree>\n<mand>\n<julia>");
			exit(1);
		}
		mlx_hook(map.win, 2, 5, key_function, &map);
		mlx_hook(map.win, 17, 1L << 17, exit_func, &map);
		mlx_loop(map.mlx);
	}
	return (0);
}
