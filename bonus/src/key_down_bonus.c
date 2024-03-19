/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_down_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:34:16 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/16 15:52:03 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	display_str(t_data *data)
{
	char		*itoa;

	itoa = NULL;
	data->charac->life -= 1;
	itoa = ft_itoa(data->charac->life + 1);
	if (!itoa)
		exit_fail(data, "\e[31mError\n\e[0mft_itoa()\n");
	mlx_string_put(data->p_mlx, data->p_win, 175, 16, BLACK, itoa);
	free(itoa);
	itoa = ft_itoa(data->charac->life);
	if (!itoa)
		exit_fail(data, "\e[31mError\n\e[0mft_itoa()\n");
	mlx_string_put(data->p_mlx, data->p_win, 175, 16, WHITE, itoa);
	free(itoa);
}

static void	event_move(t_data *data, t_charac *charac, int x, int y)
{
	int			img_w;
	int			img_h;
	char		*itoa;

	itoa = NULL;
	if (ft_strncmp(&data->map[y + 1][x], "C", 1) == 0)
	{
		itoa = ft_itoa(charac->collect);
		mlx_string_put(data->p_mlx, data->p_win, 150, 50, BLACK, itoa);
		free(itoa);
		charac->collect += 1;
	}
	else if (ft_strncmp(&data->map[y + 1][x], "X", 1) == 0)
		display_str(data);
	data->map[y][x] = '0';
	data->map[y + 1][x] = 'P';
	mlx_destroy_image(data->p_mlx, charac->s_charac);
	charac->s_charac = xpm_to_img(data->p_mlx, S_C_F, &img_w, &img_h);
	display(data, data->d_map);
}

void	key_down(t_data *data, t_charac *charac)
{
	int		x;
	int		y;

	x = find_pos(data->map, 'x');
	y = find_pos(data->map, 'y');
	if (ft_strncmp(&data->map[y + 1][x], "1", 1) != 0
		&& ft_strncmp(&data->map[y + 1][x], "E", 1) != 0)
		event_move(data, charac, x, y);
	else if (ft_strncmp(&data->map[y + 1][x], "E", 1) == 0
		&& ft_strncmp(&data->map[y + 1][x], "1", 1) != 0
		&& charac->goal == charac->collect)
	{
		img_to_win(data, data->d_map->s_e, charac->c_x, charac->c_y);
		anim_down(data, data->d_map);
		anim_close(data, data->d_map);
		sleep(1);
		ft_printf("\e[32mYou win with %d moves !\n\e[0m", charac->move);
		exit_succ(data);
	}
}
