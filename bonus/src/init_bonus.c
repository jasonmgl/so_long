/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:14:11 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/16 15:31:26 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

size_t	find_pos(char **map, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!map || !c || (c != 'y' && c != 'x'))
		return (0);
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				if (c == 'y')
					return (i);
				else if (c == 'x')
					return (j);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

t_charac	*init_charac(char **map)
{
	t_charac	*charac;

	charac = NULL;
	if (!map)
		return (NULL);
	charac = (t_charac *)malloc(sizeof(t_charac) * 1);
	if (!charac)
		return (NULL);
	charac->collect = 0;
	charac->move = 0;
	charac->life = LIFE;
	charac->s_charac = NULL;
	charac->pos_y = find_pos(map, 'y');
	charac->pos_x = find_pos(map, 'x');
	charac->goal = check_char(map, 'C');
	charac->map = NULL;
	if (charac->pos_y == 0 || charac->pos_x == 0)
		return (free_charac(charac), NULL);
	if (charac->goal == 0)
		return (free_charac(charac), NULL);
	return (charac);
}

void	init_data(t_data *data, t_charac *charac, char **map, t_map *d_map)
{
	data->p_mlx = NULL;
	data->p_win = NULL;
	data->fd = 0;
	data->charac = NULL;
	data->map = map;
	data->d_map = d_map;
	data->open = false;
	if (!charac)
		exit_fail(data, "\e[31mError\n\e[0minit_data()\n");
	data->charac = charac;
}

static void	load_spritebis(t_data *data, t_map *d_map, int *img_w, int *img_h)
{
	d_map->s_bot_rbis = xpm_to_img(data->p_mlx, S_BOT_RBIS, img_w, img_h);
	if (!(d_map->s_bot_rbis))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	d_map->s_bot_lbis = xpm_to_img(data->p_mlx, S_BOT_LBIS, img_w, img_h);
	if (!(d_map->s_bot_lbis))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	d_map->s_r = xpm_to_img(data->p_mlx, S_R, img_w, img_h);
	if (!(d_map->s_r))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	d_map->s_l = xpm_to_img(data->p_mlx, S_L, img_w, img_h);
	if (!(d_map->s_l))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	d_map->s_e = xpm_to_img(data->p_mlx, S_E, img_w, img_h);
	if (!(d_map->s_e))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	d_map->s_c = xpm_to_img(data->p_mlx, S_C, img_w, img_h);
	if (!(d_map->s_c))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	d_map->s_b = xpm_to_img(data->p_mlx, S_B, img_w, img_h);
	if (!(d_map->s_b))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	d_map->s_enemy = xpm_to_img(data->p_mlx, S_ENEMY, img_w, img_h);
	if (!(d_map->s_enemy))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
}

void	load_sprite(t_data *data, t_map *d_map, int *img_w, int *img_h)
{
	d_map->s_top = xpm_to_img(data->p_mlx, S_TOP, img_w, img_h);
	if (!(d_map->s_top))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	d_map->s_top_r = xpm_to_img(data->p_mlx, S_TOP_R, img_w, img_h);
	if (!(d_map->s_top_r))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	d_map->s_top_l = xpm_to_img(data->p_mlx, S_TOP_L, img_w, img_h);
	if (!(d_map->s_top_l))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	d_map->s_bot = xpm_to_img(data->p_mlx, S_BOT, img_w, img_h);
	if (!(d_map->s_bot))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	d_map->s_bot_r = xpm_to_img(data->p_mlx, S_BOT_R, img_w, img_h);
	if (!(d_map->s_bot_r))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	d_map->s_bot_l = xpm_to_img(data->p_mlx, S_BOT_L, img_w, img_h);
	if (!(d_map->s_bot_l))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	d_map->s_botbis = xpm_to_img(data->p_mlx, S_BOTBIS, img_w, img_h);
	if (!(d_map->s_botbis))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	d_map->s_d = xpm_to_img(data->p_mlx, S_D_C, img_w, img_h);
	if (!(d_map->s_d))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	load_spritebis(data, d_map, img_w, img_h);
}
