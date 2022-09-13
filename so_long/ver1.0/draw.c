#include "so_long.h"

void	draw_image(t_draw *put_img, char *type, int x, int y)
{
	void	*id;
	void	*so_long;
	void	*window;
	int		width;
	int		height;

	width = put_img->image->width;
	height = put_img->image->height;
	id = put_img->image->id;
	so_long = put_img->game->start;
	window = put_img->game->window;
	id = mlx_xpm_file_to_image(so_long, type, &width, &height);
	mlx_put_image_to_window(so_long, window, id, TILE * x, TILE * y);
}

void	draw_position(t_draw *put_img, char *map_arr, int map_size, int	index)
{
	t_draw_position	position;
	
	position.y = 0;
	while (index < map_size)
	{
		position.x = 0;
		while (position.x < put_img->map->row && 0 != map_arr[index])
		{
			if ('0' == map_arr[index])
				draw_image(put_img, EMPTY, position.x, position.y);
			else if ('1' == map_arr[index])
				draw_image(put_img, WALL, position.x, position.y);
			else if ('C' == map_arr[index])
				draw_image(put_img, ITEM, position.x, position.y);
			else if ('E' == map_arr[index])
				draw_image(put_img, EXIT, position.x, position.y);
			else if ('P' == map_arr[index])
				draw_image(put_img, PLAYER, position.x, position.y);
			else if ('X' == map_arr[index])
				draw_image(put_img, ENEMY, position.x, position.y);
			index++;
			position.x++;
		}
		position.y++;
	}
}

void	draw(t_draw *put_img)
{
	char	*map_arr;
	int		map_size;
	int		index;

	index = 0;
	map_arr = put_img->map->map;
	map_size = put_img->map->size;
	draw_position(put_img, map_arr, map_size, index);
}