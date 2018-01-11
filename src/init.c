#include "fract.h"

void	init(t_mapinfo *map, char *str)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIDTH, HEIGHT, str);
	map->image_ptr = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	map->image = (int *)mlx_get_data_addr(map->image_ptr, &map->bits_per_pixel,
										&map->size_line, &map->endian);
}

void	init_mandelbrot(t_mapinfo *map)
{
	init(map, "mandelbrot fractol");
	map->fract.maxiterations_const = 50;
	map->fract.maxiterations = map->fract.maxiterations_const;
	map->fract.moveX = -0.5;
	map->fract.moveY = 0;
	map->fract.zoom = 1;
}

void	init_julia(t_mapinfo *map)
{
	init(map, "julia fractol");
	map->fract.maxiterations_const = 100;
	map->fract.maxiterations = map->fract.maxiterations_const;
}

void	init_fract_tree(t_mapinfo *map)
{
	init(map, "fractol tree");
}
