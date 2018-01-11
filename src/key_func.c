#include "fract.h"

int		key_function(int keycode, void *param)
{
	t_mapinfo *map;

	map = (t_mapinfo *)param;
	mlx_clear_window(map->mlx, map->win);
	if (keycode == MAC_ESC_BUT)
		exit_func(map);
	else if (keycode == MAC_BUT_PLUS)
		map->fract.maxiterations += 1;
	else if (keycode == MAC_BUT_MINUS)
		map->fract.maxiterations -= 1;
	else if (keycode == MAC_ARROW_LEFT)
		map->fract.moveX -= 0.02;
	else if (keycode == MAC_ARROW_RIGHT)
		map->fract.moveX += 0.02;
	else if (keycode == MAC_ARROW_UP)
		map->fract.moveY -= 0.02;
	else if (keycode == MAC_ARROW_DOWN)
		map->fract.moveY += 0.02;
	else if (keycode == MAC_BUT_1)
	{
		map->fract.zoom *= 1.02;
		//map->fract.maxiterations = fabs(map->fract.maxiterations * 1.01 + 2);
	}
	else if (keycode == MAC_BUT_2)
	{
		map->fract.zoom *= 0.98;
		// map->fract.maxiterations = fabs(map->fract.maxiterations * 0.99 - 2);
	}
	draw(map);
	return (0);
}
