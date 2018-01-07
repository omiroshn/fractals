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

int		exit_func(void *param)
{
	param = NULL;
	exit(1);
	return (0);
}

void	init(t_mapinfo *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIDTH, HEIGHT, "omiroshn's fractol");
	map->image_ptr = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	map->image = (int *)mlx_get_data_addr(map->image_ptr, &map->bits_per_pixel,
										&map->size_line, &map->endian);
	map->maxiterations_const = 100;
	map->maxiterations = map->maxiterations_const;
}

void	draw(t_mapinfo *map)
{
	int x;
	int y;
	float bright = 0xFFFFFF;
	float a;
	float b;
	float n;
	float aa;
	float bb;
	float ca;
	float cb;
	int pix;
	

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
	// 		bright = ft_map(n, 0, map->maxiterations, 0, 1);
	// 		bright = ft_map(sqrt(bright), 0, 1, 0, rgba_to_int(0,255,0,255));
	// 		if (n == map->maxiterations)
	// 			bright = 0;
 //      		map->image[pix] = ft_map(n, 0, map->maxiterations_const, 0, bright);
	// 		y++;
	// 	}
	// 	x++;
	// }

	double MinRe = -2.0;
	double MaxRe = 1.0;
	double MinIm = -1.2;
	double MaxIm = MinIm+(MaxRe-MinRe)*HEIGHT/WIDTH;
	double Re_factor = (MaxRe-MinRe)/(WIDTH-1);
	double Im_factor = (MaxIm-MinIm)/(HEIGHT-1);
	unsigned MaxIterations = 30;
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		double c_im = MaxIm - x*Im_factor;
		while (y < HEIGHT)
		{
			double c_re = MinRe + y*Re_factor;
			double Z_re = c_re, Z_im = c_im;
			//bool isInside = true;
			pix = (y + x * WIDTH);
			n = 0;
			while (n < map->maxiterations)
			{
				double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
            	if(Z_re2 + Z_im2 > 4)
            	{
            	    //isInside = false;
            	    break;
            	}
            	Z_im = 2*Z_re*Z_im + c_im;
            	Z_re = Z_re2 - Z_im2 + c_re;
				n++;
			}
			bright = ft_map(n, 0, map->maxiterations, 0, 1);
			bright = ft_map(sqrt(bright), 0, 1, 0, rgba_to_int(0,255,0,255));
			if (n == map->maxiterations)
				bright = 0;
      		map->image[pix] = ft_map(n, 0, map->maxiterations_const, 0, bright);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(map->mlx, map->win, map->image_ptr, 0, 0);
}

int		key_function(int keycode, void *param)
{
	t_mapinfo *map;

	map = (t_mapinfo *)param;
	mlx_clear_window(map->mlx, map->win);
	if (keycode == 53)
		exit_func(map);
	else if (keycode == MAC_BUT_PLUS)
		map->maxiterations += 1;
	else if (keycode == MAC_BUT_MINUS)
		map->maxiterations -= 1;
	draw(map);
	return (0);
}

int		main(int argc, char *argv[])
{
	t_mapinfo map;

	if (argc != 2)
		ft_putendl("Usage : ./fractol <filename>");
	else
	{
		init(&map);
		draw(&map);
		mlx_hook(map.win, 2, 5, key_function, &map);
		mlx_hook(map.win, 17, 1L << 17, exit_func, &map);
		mlx_loop(map.mlx);
	}
	return (0);
}
