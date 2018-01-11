#include "fract.h"

void	draw_line(t_mapinfo *map, int len)
{
	int x;
	int y;
	int pix;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			pix = (x + y * WIDTH);
			if (len < HEIGHT)
			{
				map->image[x + len * WIDTH + WIDTH / 2] = 255;
				len++;
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(map->mlx, map->win, map->image_ptr, 0, 0);
}

void	draw_fract_tree(t_mapinfo *map)
{
	draw_line(map, HEIGHT - 300);
}
