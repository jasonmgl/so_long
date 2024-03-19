/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:17:02 by jason             #+#    #+#             */
/*   Updated: 2024/02/15 16:47:19 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	destroy_imgbis(t_data *data)
{
	if (data->d_map->s_l)
		mlx_destroy_image(data->p_mlx, data->d_map->s_l);
	if (data->d_map->s_e)
		mlx_destroy_image(data->p_mlx, data->d_map->s_e);
	if (data->d_map->s_c)
		mlx_destroy_image(data->p_mlx, data->d_map->s_c);
	if (data->d_map->s_d)
		mlx_destroy_image(data->p_mlx, data->d_map->s_d);
	if (data->d_map->s_b)
		mlx_destroy_image(data->p_mlx, data->d_map->s_b);
	if (data->charac->s_charac)
		mlx_destroy_image(data->p_mlx, data->charac->s_charac);
}

void	destroy_img(t_data *data)
{
	if (data->d_map->s_top)
		mlx_destroy_image(data->p_mlx, data->d_map->s_top);
	if (data->d_map->s_top_r)
		mlx_destroy_image(data->p_mlx, data->d_map->s_top_r);
	if (data->d_map->s_top_l)
		mlx_destroy_image(data->p_mlx, data->d_map->s_top_l);
	if (data->d_map->s_bot)
		mlx_destroy_image(data->p_mlx, data->d_map->s_bot);
	if (data->d_map->s_bot_r)
		mlx_destroy_image(data->p_mlx, data->d_map->s_bot_r);
	if (data->d_map->s_bot_l)
		mlx_destroy_image(data->p_mlx, data->d_map->s_bot_l);
	if (data->d_map->s_botbis)
		mlx_destroy_image(data->p_mlx, data->d_map->s_botbis);
	if (data->d_map->s_bot_rbis)
		mlx_destroy_image(data->p_mlx, data->d_map->s_bot_rbis);
	if (data->d_map->s_bot_lbis)
		mlx_destroy_image(data->p_mlx, data->d_map->s_bot_lbis);
	if (data->d_map->s_r)
		mlx_destroy_image(data->p_mlx, data->d_map->s_r);
	destroy_imgbis(data);
}

int	exit_succ(t_data *data)
{
	if (data->p_win)
		destroy_img(data);
	if (data->p_win)
		mlx_destroy_window(data->p_mlx, data->p_win);
	if (data->p_mlx)
		mlx_destroy_display(data->p_mlx);
	if (data->p_mlx)
		free(data->p_mlx);
	if (data->map)
		free_map(data->map);
	if (data->charac)
		free_charac(data->charac);
	close(data->fd);
	exit(EXIT_SUCCESS);
}

int	exit_fail(t_data *data, char *str)
{
	if (str)
		ft_putstr_fd(str, 2);
	if (data->p_win)
		destroy_img(data);
	if (data->p_win)
		mlx_destroy_window(data->p_mlx, data->p_win);
	if (data->p_mlx)
		mlx_destroy_display(data->p_mlx);
	if (data->p_mlx)
		free(data->p_mlx);
	if (data->map)
		free_map(data->map);
	if (data->charac)
		free_charac(data->charac);
	close(data->fd);
	exit(EXIT_FAILURE);
}
