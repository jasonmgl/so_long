/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:09:23 by jason             #+#    #+#             */
/*   Updated: 2024/02/12 10:22:08 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	make_top(t_data *data, t_map *d_map, int *img_w, int *img_h)
{
	int	i;

	i = 1;
	img_to_win(data, d_map->s_top_l, d_map->c_x, d_map->c_y);
	d_map->c_x += *img_w;
	while (data->map[0][i + 1])
	{
		img_to_win(data, d_map->s_top, d_map->c_x, d_map->c_y);
		d_map->c_x += *img_w;
		i++;
	}
	img_to_win(data, d_map->s_top_r, d_map->c_x, d_map->c_y);
	d_map->c_x = 0;
	d_map->c_y += *img_h;
}

static void	make_botbis(t_data *data, t_map *d_map, int *img_w)
{
	int	i;

	i = 1;
	d_map->c_x += *img_w;
	img_to_win(data, d_map->s_bot_lbis, d_map->c_x, d_map->c_y);
	d_map->c_x += *img_w;
	while (data->map[d_map->last_l][i + 1])
	{
		img_to_win(data, d_map->s_botbis, d_map->c_x, d_map->c_y);
		data->d_map->c_x += *img_w;
		i++;
	}
	img_to_win(data, d_map->s_bot_rbis, d_map->c_x, d_map->c_y);
	data->d_map->c_x += *img_w;
}

static void	make_bot(t_data *data, t_map *d_map, int *img_w, int *img_h)
{
	int	i;

	i = 1;
	d_map->c_x += *img_w;
	img_to_win(data, d_map->s_bot_l, d_map->c_x, d_map->c_y);
	d_map->c_x += *img_w;
	while (data->map[d_map->last_l][i + 1])
	{
		img_to_win(data, d_map->s_bot, d_map->c_x, d_map->c_y);
		d_map->c_x += *img_w;
		i++;
	}
	img_to_win(data, d_map->s_bot_r, d_map->c_x, d_map->c_y);
	d_map->c_x = 0;
	d_map->c_y += *img_h - 1;
	make_botbis(data, d_map, img_w);
}

static void	make_mid(t_data *data, t_map *d_map, int *img_w, int *img_h)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (data->map[j + 1])
	{
		d_map->c_x += *img_w;
		img_to_win(data, d_map->s_l, d_map->c_x, d_map->c_y);
		d_map->c_x += *img_w;
		while (data->map[j + 1][i + 1])
		{
			set_img(data, d_map, data->charac, &data->map[j][i]);
			d_map->c_x += *img_w;
			i++;
		}
		img_to_win(data, d_map->s_r, d_map->c_x, d_map->c_y);
		i = 1;
		j++;
		d_map->c_x = 0;
		d_map->c_y += *img_h;
	}
}

void	make_map(t_data *data, t_map *d_map, int *img_w, int *img_h)
{
	d_map->c_y += (*img_h * 1);
	d_map->c_x += *img_w;
	make_top(data, d_map, img_w, img_h);
	make_mid(data, d_map, img_w, img_h);
	make_bot(data, d_map, img_w, img_h);
	data->d_map->c_y = 0;
	data->d_map->c_x = 0;
}
