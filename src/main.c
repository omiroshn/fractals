/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:26:45 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/11 21:20:01 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

double	ft_map(double value, double istart, double iend, double ostart, double oend)
{
    return (ostart + (oend - ostart) * ((value - istart) / (iend - istart)));
}

static inline int	rgb_to_int(int red, int green, int blue)
{
	int r;
	int g;
	int b;

	r = red & 0xFF;
	g = green & 0xFF;
	b = blue & 0xFF;
	return (r << 16 | g << 8 | b);
}

int		get_rgb_smooth(double t)
{
	return (rgb_to_int((int)(9 * (1 - t) * t * t * t * 255),
		(int)(15 * (1 - t)* (1 - t) * t * t * 255),
		(int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255)));
}

void	draw_mandelbrot(t_info *info)
{
	double pr, pi;
	int x;
	int y;
	double bright;
	double old_a;
	double old_b;
	int n;
	double new_a;
	double new_b;
	double ca;
	double cb;
	int pix;
	int hue;
	int saturation;
	double newRe, newIm, oldRe, oldIm;
	
	x = info->x;
	while (x < info->end)
	{
		y = 0;
		while (y < HEIGHT)
		{
			// pr = 1.5 * (x - WIDTH / 2) / (0.5 * info->map->fract.zoom * WIDTH) + info->map->fract.moveX;
			// pi = (y - HEIGHT / 2) / (0.5 * info->map->fract.zoom * HEIGHT) + info->map->fract.moveY;
			// newRe = newIm = oldRe = oldIm = 0;
			old_a = MAP(x, 0, WIDTH, -2 * info->map->fract.zoom, 2 * info->map->fract.zoom) + info->map->fract.moveX;
			old_b = MAP(y, 0, HEIGHT, -2 * info->map->fract.zoom, 2 * info->map->fract.zoom) + info->map->fract.moveY;

			ca = old_a;
			cb = old_b;

			n = 0;
			while (n < info->map->fract.maxiterations)
			{
				// oldRe = newRe;
				// oldIm = newIm;
				// newRe = oldRe * oldRe - oldIm * oldIm + pr;
				// newIm = 2 * oldRe * oldIm + pi;
				// if ((newRe * newRe + newIm * newIm) > 16)
				// 	break;
				new_a = old_a * old_a - old_b * old_b;
				new_b = 2 * old_a * old_b;
				old_a = new_a + ca;
				old_b = new_b + cb;
				if (fabs(old_a + old_b) > 4)
					break;
				n++;
			}
			bright = get_rgb_smooth((double)n / info->map->fract.maxiterations);
			if (n == info->map->fract.maxiterations)
				bright = 0;
			pix = (x + y * WIDTH);
			info->map->image[pix] = bright;
			y++;
		}
		x++;
	}
}

void	draw(t_mapinfo *map)
{
	unsigned	x;
	pthread_t	threads[THREADS];
	t_info		info[THREADS];
	int			i;

	i = 0;
	x = 0;
	while (i < THREADS)
	{
		info[i].map = map;
		info[i].x = x;
		x += WIDTH / THREADS;
		info[i].end = x;
		pthread_create(&threads[i], NULL, (void *(*)(void *))draw_mandelbrot, (void *)&info[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
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
			draw(&map);
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
