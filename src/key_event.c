/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:54:46 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/16 13:14:13 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	key_generic(t_data *data, char *c, char *file_path, t_vector2 pos)
{
	int			img;

	if (ft_strncmp(c, "1", 1) != 0
		&& ft_strncmp(c, "E", 1) != 0)
	{
		if (ft_strncmp(c, "C", 1) == 0)
			data->charac->collect += 1;
		data->map[pos.y][pos.x] = '0';
		*c = 'P';
		mlx_destroy_image(data->p_mlx, data->charac->s_charac);
		mlx_destroy_image(data->p_mlx, data->d_map->s_d);
		data->charac->s_charac = xpm_to_img(data->p_mlx, file_path, &img, &img);
		display(data, data->d_map);
	}
	else if (ft_strncmp(c, "E", 1) == 0
		&& ft_strncmp(c, "1", 1) != 0
		&& data->charac->goal == data->charac->collect)
	{
		ft_printf("\e[32mYou win with %d moves !\n\e[0m", data->charac->move);
		exit_succ(data);
	}
}

int	key_event(int keycode, t_data *data)
{
	t_vector2	pos;

	pos.x = find_pos(data->map, 'x');
	pos.y = find_pos(data->map, 'y');
	if (keycode == ESC)
		exit_succ(data);
	else if (keycode == UP)
		key_generic(data, &data->map[pos.y - 1][pos.x], S_C_B, pos);
	else if (keycode == DOWN)
		key_generic(data, &data->map[pos.y + 1][pos.x], S_C_F, pos);
	else if (keycode == RIGHT)
		key_generic(data, &data->map[pos.y][pos.x + 1], S_C_R, pos);
	else if (keycode == LEFT)
		key_generic(data, &data->map[pos.y][pos.x - 1], S_C_L, pos);
	return (1);
}
