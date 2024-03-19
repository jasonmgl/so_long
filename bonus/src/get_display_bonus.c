/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_display_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:08:47 by jason             #+#    #+#             */
/*   Updated: 2024/02/17 14:12:43 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	string_putbis(t_data *data)
{
	mlx_string_put(data->p_mlx, data->p_win, 8, 50, WHITE, "Move :");
	mlx_string_put(data->p_mlx, data->p_win, 85, 50, WHITE, "Collect :");
	mlx_string_put(data->p_mlx, data->p_win, 165, 50, WHITE, "/");
	mlx_string_put(data->p_mlx, data->p_win, 9, 16, WHITE, "Welcome !");
	mlx_string_put(data->p_mlx, data->p_win, 130, 16, WHITE, "Life :");
}

static void	string_put(int move, t_data *data, t_charac *charac)
{
	char	*itoa;

	itoa = ft_itoa(move);
	if (!itoa)
		exit_fail(data, "\e[31mError\n\e[0mft_itoa()\n");
	mlx_string_put(data->p_mlx, data->p_win, 55, 50, WHITE, itoa);
	free(itoa);
	itoa = ft_itoa(charac->goal);
	if (!itoa)
		exit_fail(data, "\e[31mError\n\e[0mft_itoa()\n");
	mlx_string_put(data->p_mlx, data->p_win, 175, 50, WHITE, itoa);
	free(itoa);
	itoa = ft_itoa(charac->collect);
	if (!itoa)
		exit_fail(data, "\e[31mError\n\e[0mft_itoa()\n");
	mlx_string_put(data->p_mlx, data->p_win, 150, 50, WHITE, itoa);
	free(itoa);
	itoa = ft_itoa(charac->life);
	if (!itoa)
		exit_fail(data, "\e[31mError\n\e[0mft_itoa()\n");
	mlx_string_put(data->p_mlx, data->p_win, 175, 16, WHITE, itoa);
	free(itoa);
	string_putbis(data);
}

int	key_event(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit_succ(data);
	else if (keycode == UP)
		key_up(data, data->charac);
	else if (keycode == DOWN)
		key_down(data, data->charac);
	else if (keycode == RIGHT)
		key_right(data, data->charac);
	else if (keycode == LEFT)
		key_left(data, data->charac);
	else if (keycode == ARROW_UP)
		key_up(data, data->charac);
	else if (keycode == ARROW_DOWN)
		key_down(data, data->charac);
	else if (keycode == ARROW_RIGHT)
		key_right(data, data->charac);
	else if (keycode == ARROW_LEFT)
		key_left(data, data->charac);
	else if (keycode == DISPLAY_COLL)
		ft_printf("\e[32mCollectable : %d / %d.\n\e[0m", data->charac->collect,
			data->charac->goal);
	return (1);
}

void	get_window(char **map, t_map *d_map, int fd)
{
	t_data		data;
	t_charac	*charac;
	int			img_w;
	int			img_h;

	if (!map || !d_map)
		return ;
	charac = init_charac(map);
	init_data(&data, charac, map, d_map);
	data.fd = fd;
	data.p_mlx = mlx_init();
	if (!data.p_mlx)
		exit_fail(&data, "\e[31mError\n\e[0mmlx_init()\n");
	if (!(check_screen_size(&data)))
		exit_fail(&data, "\e[31mError\n\e[0m[Display] : check_screen_size()\n");
	data.charac->s_charac = xpm_to_img(data.p_mlx, S_C_F, &img_w, &img_h);
	load_sprite(&data, d_map, &img_w, &img_h);
	display(&data, d_map);
	mlx_key_hook(data.p_win, key_event, &data);
	mlx_hook(data.p_win, CLOSE_WINDOW, 0, exit_succ, &data);
	mlx_loop(data.p_mlx);
}

void	display(t_data *data, t_map *d_map)
{
	int			img_h;
	char		*itoa;

	if (!(data->charac->s_charac))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	itoa = ft_itoa(data->charac->move - 1);
	if (data->charac->move > 0)
		mlx_string_put(data->p_mlx, data->p_win, 55, 50, BLACK, itoa);
	ft_printf("\e[32mMove : %d\n\e[0m", data->charac->move);
	free(itoa);
	string_put(data->charac->move, data, data->charac);
	img_h = 32;
	make_map(data, d_map, &img_h, &img_h);
	data->charac->move += 1;
	if (data->charac->life == 0)
	{
		anim_die(data, data->charac);
		if (data->open)
			anim_close(data, d_map);
		ft_printf("\e[31mTry again ! You lost !\n\e[0m");
		exit_succ(data);
	}
}
