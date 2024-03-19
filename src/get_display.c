/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:08:47 by jason             #+#    #+#             */
/*   Updated: 2024/02/16 09:36:42 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	load_spritebis(t_data *data, t_map *d_map, int *img_w, int *img_h)
{
	d_map->s_bot_rbis = xpm_to_img(data->p_mlx, S_BOT_RBIS, img_w, img_h);
	if (!(d_map->s_bot_rbis))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	d_map->s_bot_lbis = xpm_to_img(data->p_mlx, S_BOT_LBIS, img_w, img_h);
	if (!(d_map->s_bot_lbis))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	data->d_map->s_r = xpm_to_img(data->p_mlx, S_R, img_w, img_h);
	if (!(data->d_map->s_r))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	data->d_map->s_l = xpm_to_img(data->p_mlx, S_L, img_w, img_h);
	if (!(data->d_map->s_l))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	data->d_map->s_e = xpm_to_img(data->p_mlx, S_E, img_w, img_h);
	if (!(data->d_map->s_e))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	data->d_map->s_c = xpm_to_img(data->p_mlx, S_C, img_w, img_h);
	if (!(data->d_map->s_c))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	data->d_map->s_b = xpm_to_img(data->p_mlx, S_B, img_w, img_h);
	if (!(data->d_map->s_b))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
}

static void	load_sprite(t_data *data, t_map *d_map, int *img_w, int *img_h)
{
	data->d_map->s_top = xpm_to_img(data->p_mlx, S_TOP, img_w, img_h);
	if (!(data->d_map->s_top))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	data->d_map->s_top_r = xpm_to_img(data->p_mlx, S_TOP_R, img_w, img_h);
	if (!(data->d_map->s_top_r))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	data->d_map->s_top_l = xpm_to_img(data->p_mlx, S_TOP_L, img_w, img_h);
	if (!(data->d_map->s_top_l))
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
	load_spritebis(data, d_map, img_w, img_h);
}

static int	check_screen_size(t_data *data, t_map *d_map)
{
	int	max_width;
	int	max_height;
	int	width;
	int	height;

	width = (d_map->nbr_x * 32) + (2 * 32);
	height = (d_map->nbr_y * 32) + (3 * 32);
	mlx_get_screen_size(data->p_mlx, &max_width, &max_height);
	if (height > max_height || width > max_width)
		return (0);
	data->p_win = mlx_new_window(data->p_mlx, width, height, "SO_LONG");
	if (!data->p_win)
		return (0);
	return (1);
}

void	get_window(char **map, t_map *d_map, int fd)
{
	t_data		data;
	t_charac	*charac;
	int			img_w;
	int			img_h;

	if (!map || !d_map || fd < 0)
		return ;
	charac = init_charac(map);
	init_data(&data, charac, map, d_map);
	data.fd = fd;
	data.p_mlx = mlx_init();
	if (!data.p_mlx)
		exit_fail(&data, "\e[31mError\n\e[0mmlx_init()\n");
	if (!(check_screen_size(&data, d_map)))
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
	int			img_w;
	int			img_h;

	if (!(data->charac->s_charac))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	data->charac->move += 1;
	ft_printf("\e[32mMove : %d\n\e[0m", data->charac->move);
	if (data->charac->goal - data->charac->collect == 0)
		d_map->s_d = xpm_to_img(data->p_mlx, S_D_O, &img_w, &img_h);
	else if (data->charac->goal - data->charac->collect != 0)
		d_map->s_d = xpm_to_img(data->p_mlx, S_D_C, &img_w, &img_h);
	if (!(d_map->s_d) || !(d_map->s_bot_rbis))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	img_h = 32;
	make_map(data, d_map, &img_h, &img_h);
}
