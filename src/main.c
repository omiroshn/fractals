/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:26:45 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/12 19:52:53 by omiroshn         ###   ########.fr       */
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

void	draw_mandelbrot(t_info *i)
{
	i->y = i->cunt;
	while (i->y < i->end)
	{
		i->c_im = MAP(i->y, 0, WIDTH, -2 * i->zoom, 2 * i->zoom);
		i->x = 0;
		while (i->x < HEIGHT)
		{
			i->c_re = MAP(i->x, 0, HEIGHT, -2 * i->zoom, 2 * i->zoom);

			i->z_im = i->c_im;
			i->z_re = i->c_re;

			i->n = 0;
			i->func(i);
			i->bright = get_rgb_smooth((double)i->n / i->maxiterations);
			if (i->n == i->maxiterations)
				i->bright = 0;
			i->pix = (i->x + i->y * WIDTH);
			i->map.image[i->pix] = i->bright;
			i->x++;
		}
		i->y++;
	}
}

void	draw(t_info *in)
{
	pthread_t	threads[THREADS];
	int			*status_addr;
	int			status;
	t_info		info[THREADS];
	unsigned	y;
	int			i;

	i = 0;
	y = 0;
	while (i < THREADS)
	{
		info[i] = *in;
		info[i].cunt = y;
		y += HEIGHT / THREADS;
		info[i].end = y;
		pthread_create(&threads[i], NULL, (void *(*)(void *))draw_mandelbrot, (void *)&info[i]);
		i++;
	}
	while (i-- > 0)
		if ((status = pthread_join(threads[i], (void**)&status_addr)))
			printf("Error join thread\n");
	mlx_put_image_to_window(in->map.mlx, in->map.win, in->map.image_ptr, 0, 0);
}

void	loops(t_info info)
{
	info.map.mlx = mlx_init();
	info.map.win = mlx_new_window(info.map.mlx, WIDTH, HEIGHT, info.name);
	info.map.image_ptr = mlx_new_image(info.map.mlx, WIDTH, HEIGHT);
	info.map.image = (int *)mlx_get_data_addr(info.map.image_ptr,
		&info.map.bits_per_pixel, &info.map.size, &info.map.endian);
	draw(&info);
	mlx_hook(info.map.win, 2, 5, key_function, &info);
	mlx_hook(info.map.win, 17, 1L << 17, exit_func, &info);
	//mlx_hook(info.map.win, 6, 5, mmotion, &info);
	//mlx_mouse_hook(info.map.win, mouse_hook, &info);
	mlx_loop(info.map.mlx);
}

void	run(char *name)
{
	t_info info;

	if (ft_strequ(name, "mandelbrot"))
		info.func = &iter_mandelbrot;
	else if (ft_strequ(name, "julia"))
		info.func = &iter_julia;
	else if (ft_strequ(name, "mandelbar3"))
		info.func = &iter_mandelbar3;
	else if (ft_strequ(name, "mandelbar4"))
		info.func = &iter_mandelbar4;
	else if (ft_strequ(name, "mandelbar5"))
		info.func = &iter_mandelbar5;
	else if (ft_strequ(name, "perp_mandelbrot"))
		info.func = &iter_perp_mand;
	else if (ft_strequ(name, "celtic_mandelbar"))
		info.func = &iter_celtic_mand;
	else if (ft_strequ(name, "bs"))
		info.func = &iter_burning_ship;
	else if (ft_strequ(name, "bs_cubic"))
		info.func = &iter_cubic_burning_ship;
	else if (ft_strequ(name, "bs_perpend"))
		info.func = &iter_bs_perpend;
	else if (ft_strequ(name, "celtic_perpend"))
		info.func = &iter_celtic_perpend;
	else if (ft_strequ(name, "perpend_buffalo"))
		info.func = &iter_perpend_buffalo;
	init(name, &info);
	loops(info);
}

void	options()
{
	ft_putendl("Usage : ./fractol <name>");
	ft_putendl("                 -mandelbrot");
	ft_putendl("                 -julia");
	ft_putendl("                 -bs");
	ft_putendl("                 -bs_cubic");
	ft_putendl("                 -bs_perpend");
	ft_putendl("                 -mandelbar3");
	ft_putendl("                 -mandelbar4");
	ft_putendl("                 -mandelbar5");
	ft_putendl("                 -perp_mandelbrot");
	ft_putendl("                 -celtic_mandelbar");
	ft_putendl("                 -celtic_perpend");
	ft_putendl("                 -perpend_buffalo");
	exit(0);
}

void	check(int argc, char **a)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (!ft_strequ(a[i], "mandelbrot") && !ft_strequ(a[i], "julia")
			&& !ft_strequ(a[i], "mandelbar3") && !ft_strequ(a[i], "mandelbar4")
			&& !ft_strequ(a[i], "mandelbar5") && !ft_strequ(a[i], "perp_mandelbrot")
			&& !ft_strequ(a[i], "celtic_mandelbar") && !ft_strequ(a[i], "bs")
			&& !ft_strequ(a[i], "bs_cubic") && !ft_strequ(a[i], "bs_perpend")
			&& !ft_strequ(a[i], "iter_celtic_perpend") && !ft_strequ(a[i], "perpend_buffalo"))
		{
			ft_putstr("Wrong arguments! ");
			ft_putendl("try:");
			options();
		}
	}
}

int		main(int argc, char *argv[])
{
	if (argc != 2)
		options();
	check(argc, argv);
	run(argv[1]);
	return (0);
}
