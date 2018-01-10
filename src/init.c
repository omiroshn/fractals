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
	map->maxiterations_const = 100;
	map->maxiterations = map->maxiterations_const;
}

void	init_julia(t_mapinfo *map)
{
	init(map, "julia fractol");
	map->maxiterations_const = 100;
	map->maxiterations = map->maxiterations_const;
}

void	init_fract_tree(t_mapinfo *map)
{
	init(map, "fractol tree");
}
