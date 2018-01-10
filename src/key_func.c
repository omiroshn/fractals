#include "fract.h"

int		key_function(int keycode, void *param)
{
	t_mapinfo *map;

	map = (t_mapinfo *)param;
	mlx_clear_window(map->mlx, map->win);
	if (keycode == LINUX_ESC_BUT)
		exit_func(map);
	else if (keycode == LINUX_BUT_PLUS)
		map->maxiterations += 1;
	else if (keycode == LINUX_BUT_MINUS)
		map->maxiterations -= 1;
	draw_mandelbrot(map);
	return (0);
}
