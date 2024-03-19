/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:49:53 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/20 08:44:37 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H

# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"

# define S_C_F				"../sprites/chara/front.xpm"
# define S_C_R				"../sprites/chara/right.xpm"
# define S_C_L				"../sprites/chara/left.xpm"
# define S_C_B				"../sprites/chara/back.xpm"
# define S_BOT				"../sprites/map/bot/bot.xpm"
# define S_BOT_R			"../sprites/map/bot/bot_right.xpm"
# define S_BOT_L			"../sprites/map/bot/bot_left.xpm"
# define S_BOTBIS			"../sprites/map/bot/bot2.xpm"
# define S_BOT_RBIS			"../sprites/map/bot/bot_right2.xpm"
# define S_BOT_LBIS			"../sprites/map/bot/bot_left2.xpm"
# define S_TOP				"../sprites/map/top/top.xpm"
# define S_TOP_R			"../sprites/map/top/top_right.xpm"
# define S_TOP_L			"../sprites/map/top/top_left.xpm"
# define S_L				"../sprites/map/middle/left.xpm"
# define S_R				"../sprites/map/middle/right.xpm"
# define S_C				"../sprites/map/middle/coll.xpm"
# define S_E				"../sprites/map/middle/empty.xpm"
# define S_D_C				"../sprites/map/middle/door_close.xpm"
# define S_B				"../sprites/map/middle/block.xpm"
# define S_ENEMY			"../bonus/sprites_bonus/enemy.xpm"
# define S_C_DIE			"../bonus/sprites_bonus/die.xpm"

# define WHITE			0xFFFFFFFF
# define BLACK			0xFF000000
# define RED			0xFFFF0000
# define GREEN			0xFF00FF00
# define BLUE			0xFF0000FF

# define ESC			65307
# define UP				119
# define DOWN			115
# define RIGHT			100
# define LEFT			97
# define CLOSE_WINDOW	17
# define ARROW_UP		65362
# define ARROW_DOWN		65364
# define ARROW_LEFT		65361
# define ARROW_RIGHT	65363
# define DISPLAY_COLL	113

# define LIFE			1
# define FRAME			50000

typedef struct s_map
{
	int		nbr_x;
	int		nbr_y;
	int		c_x;
	int		c_y;
	int		door_x;
	int		door_y;
	int		last_l;
	void	*s_top;
	void	*s_top_r;
	void	*s_top_l;
	void	*s_bot;
	void	*s_bot_r;
	void	*s_bot_l;
	void	*s_botbis;
	void	*s_bot_rbis;
	void	*s_bot_lbis;
	void	*s_r;
	void	*s_l;
	void	*s_e;
	void	*s_c;
	void	*s_d;
	void	*s_b;
	void	*s_enemy;
}	t_map;

typedef struct s_string
{
	char	*collect;
	char	*life;
	char	*goal;
	char	*move;
}	t_string;

typedef struct s_charac
{
	void	*s_charac;
	size_t	pos_x;
	size_t	pos_y;
	size_t	c_x;
	size_t	c_y;
	size_t	collect;
	size_t	goal;
	size_t	life;
	size_t	move;
	char	**map;
}	t_charac;

typedef struct s_data
{
	void		*p_mlx;
	void		*p_win;
	int			fd;
	char		**map;
	bool		open;
	t_string	*string;
	t_charac	*charac;
	t_map		*d_map;
}	t_data;

void		init_str(t_string *string, t_data *data);
void		init_data(t_data *data, t_charac *charac, char **map, t_map *d_map);
t_charac	*init_charac(char **map);
size_t		find_pos(char **map, char c);
void		load_sprite(t_data *data, t_map *d_map, int *img_w, int *img_h);

char		**get_map(int fd);
char		**duplicate_map(char **map);

char		*check_map(char **map, t_map	*data_map);
size_t		check_nbr_line(char **map);
size_t		check_wall(char **map);
size_t		check_char(char **map, char c);
int			check_screen_size(t_data *data);

size_t		check_validity(char **map);
size_t		check_file_format(char *argv);
void		flood_fill(t_charac *charac, size_t *e, size_t x, size_t y);
size_t		check_players(char **map);

void		free_read(char *read, char *tmp);
void		free_map(char **map);
void		free_charac(t_charac *charac);
void		free_t_string(t_string *string);

void		get_window(char **map, t_map *data_map, int fd);
int			key_event(int keycode, t_data *data);
void		key_up(t_data *data, t_charac *charac);
void		key_down(t_data *data, t_charac *charac);
void		key_right(t_data *data, t_charac *charac);
void		key_left(t_data *data, t_charac *charac);

int			exit_fail(t_data *data, char *str);
int			exit_succ(t_data *data);
void		destroy_img(t_data *data);

void		make_map(t_data *data, t_map *d_map, int *img_w, int *img_h);
void		display(t_data *data, t_map *d_map);

int			img_to_win(t_data *data, void *sprite, int x, int y);
void		*xpm_to_img(void *p_mlx, char *path_file, int *width, int *height);
void		set_img(t_data *data, t_map *d_map, t_charac *charac, char *map);
void		anim_iter(t_data *data, t_map *d_map, char *path);

void		anim_open(t_data *data, t_map *d_map);
void		anim_close(t_data *data, t_map *d_map);
void		anim_right(t_data *data, t_map *d_map);
void		anim_left(t_data *data, t_map *d_map);
void		anim_down(t_data *data, t_map *d_map);
void		anim_up(t_data *data, t_map *d_map);
void		anim_die(t_data *data, t_charac *charac);

#endif