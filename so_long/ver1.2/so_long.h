/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:13:40 by jaekim            #+#    #+#             */
/*   Updated: 2022/05/30 18:19:02 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define GAMENAME "so_long"
# define TILE 60
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define RED_CROSS 17

# define EMPTY "image/0_empty.xpm"
# define WALL "image/1_wall.xpm"
# define ITEM "image/2_item.xpm"
# define EXIT "image/3_exit.xpm"
# define PLAYER "image/4_player.xpm"
# define ENEMY "image/5_enemy.xpm"
# define ERROR "Error"
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define BUFFER_SIZE 1024

typedef struct s_game
{
	void	*start;
	void	*window;
	int		width;
	int		height;
}	t_game;

typedef struct s_map
{
	int		fd;
	int		row;
	int		columns;
	size_t	size;
	char	*map;
}	t_map;

typedef struct s_img
{
	void	*id;
	int		width;
	int		height;
}	t_img;

typedef struct s_draw
{
	t_game	*game;
	t_img	*image;
	t_map	*map;
}	t_draw;

typedef struct s_draw_position
{
	int	x;
	int	y;
}	t_draw_position;

typedef struct s_player
{
	t_game	*game;
	t_map	*map;
	t_img	*image;
	int		position;
	int		x;
	int		y;
	int		move_count;
}	t_player;

void	init_component(t_map *map, t_game *so_long, t_img *image, char **av);
void	init_player(t_player *player, t_game *game, t_map *map, t_img *image);
void	init_game(t_game *game);
void	init_window(t_game *so_long);
void	init_put_img(t_draw *put_img, t_img *image, t_game *game, t_map *map);
void	get_mapinfo(t_map *map, char **av);
void	get_windowinfo(t_game *so_long, t_map *map);
void	get_imageinfo(t_img *image, t_game *so_long, t_map *map);
void	control_function(t_map *map, t_game *game, t_img *image);
int		window_close(void);

void	draw(t_draw *put_img);
void	draw_player(t_player *player);
void	draw_empty(t_player *player, int keycode);
void	draw_image(t_draw *put_img, char *type, int x, int y);
void	draw_position(t_draw *put_img, char *map_arr, int map_size, int index);
void	draw_image_for_exit(t_player *player, char *type, int x, int y);
int		change_image(t_player *player, int keycode);

int		gameable(char *map_arr);
void	write_error(char *error);
void	check_ac(int ac);
void	check_error(t_map *map);
int		check_other_character(t_map *map);
int		check_exit(t_player *player, int keycode);
int		check_wall(t_player *player, int keycode);
int		check_exist(t_map *map);
int		check_closed_by_wall(t_map *map);
int		check_c(char *map_arr);

int		press_key(int keycode, t_player *player);
void	set_position(t_player *player);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s1, int c);
size_t	ft_strlen(const char *s1);
void	malloc_map(t_map *map, char **av);

#endif
