/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:26:45 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/24 21:00:35 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	loops(t_info info, void *mlx)
{
	info.map.mlx = mlx;
	info.map.win = mlx_new_window(info.map.mlx, WIDTH, HEIGHT, info.name);
	info.map.image_ptr = mlx_new_image(info.map.mlx, WIDTH, HEIGHT);
	info.map.image = (int *)mlx_get_data_addr(info.map.image_ptr,
		&info.map.bits_per_pixel, &info.map.size, &info.map.endian);
	threads_crete(&info);
	mlx_hook(info.map.win, 2, 5, key_function, &info);
	mlx_hook(info.map.win, 17, 5, exit_func, &info);
	mlx_hook(info.map.win, 6, 5, julia_motion, &info);
	mlx_mouse_hook(info.map.win, mouse_hook, &info);
}

void	check(int argc, char **a)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strequ(a[i], "mandelbrot")
			&& !ft_strequ(a[i], "julia")
			&& !ft_strequ(a[i], "bs")
			&& !ft_strequ(a[i], "bs_cubic")
			&& !ft_strequ(a[i], "bs_perpend")
			&& !ft_strequ(a[i], "mandelbar3")
			&& !ft_strequ(a[i], "mandelbar4")
			&& !ft_strequ(a[i], "mandelbar5")
			&& !ft_strequ(a[i], "perp_mandelbrot")
			&& !ft_strequ(a[i], "celtic_mandelbar")
			&& !ft_strequ(a[i], "celtic_perpend")
			&& !ft_strequ(a[i], "perpend_buffalo"))
		{
			ft_putstr("Wrong arguments! ");
			ft_putendl("try:");
			options();
		}
		i++;
	}
}

void	run(int argc, char **argv)
{
	static t_info	info[12];
	void			*mlx;
	int				cunt;
	int				i;

	i = 0;
	cunt = 1;
	mlx = mlx_init();
	while (cunt < argc)
	{
		init_func(info, argv, cunt, i);
		init(argv[cunt], &info[i]);
		loops(info[i++], mlx);
		cunt++;
	}
	mlx_loop(mlx);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		options();
	check(argc, argv);
	run(argc, argv);
	return (0);
}
