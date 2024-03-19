/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_die_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:57:50 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/17 14:45:21 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

#define S_D_C_D_0			"../bonus/sprites_bonus/anim_die/anim_die0.xpm"
#define S_D_C_D_1			"../bonus/sprites_bonus/anim_die/anim_die1.xpm"
#define S_D_C_D_2			"../bonus/sprites_bonus/anim_die/anim_die2.xpm"
#define S_D_C_D_3			"../bonus/sprites_bonus/anim_die/anim_die3.xpm"
#define S_D_C_D_4			"../bonus/sprites_bonus/anim_die/anim_die4.xpm"
#define S_D_C_D_5			"../bonus/sprites_bonus/anim_die/anim_die5.xpm"
#define S_D_C_D_6			"../bonus/sprites_bonus/anim_die/anim_die6.xpm"
#define S_D_C_D_7			"../bonus/sprites_bonus/anim_die/anim_die7.xpm"
#define S_D_C_D_8			"../bonus/sprites_bonus/anim_die/anim_die8.xpm"
#define S_D_C_D_9			"../bonus/sprites_bonus/anim_die/anim_die9.xpm"
#define S_D_C_D_10			"../bonus/sprites_bonus/anim_die/anim_die10.xpm"
#define S_D_C_D_11			"../bonus/sprites_bonus/anim_die/anim_die11.xpm"
#define S_D_C_D_12			"../bonus/sprites_bonus/anim_die/anim_die12.xpm"
#define S_D_C_D_13			"../bonus/sprites_bonus/anim_die/anim_die13.xpm"
#define S_D_C_D_14			"../bonus/sprites_bonus/anim_die/anim_die14.xpm"
#define S_D_C_D_15			"../bonus/sprites_bonus/anim_die/anim_die15.xpm"

static void	anim_iterbis(t_data *data, t_charac *charac, char *path)
{
	int	img;

	mlx_destroy_image(data->p_mlx, charac->s_charac);
	charac->s_charac = xpm_to_img(data->p_mlx, path, &img, &img);
	if (!(charac->s_charac))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	img_to_win(data, charac->s_charac, charac->c_x, charac->c_y);
	usleep(130000);
}

static void	anim(t_data *data, t_charac *charac)
{
	anim_iterbis(data, charac, S_D_C_D_0);
	anim_iterbis(data, charac, S_D_C_D_1);
	anim_iterbis(data, charac, S_D_C_D_2);
	anim_iterbis(data, charac, S_D_C_D_3);
	anim_iterbis(data, charac, S_D_C_D_4);
	anim_iterbis(data, charac, S_D_C_D_5);
	anim_iterbis(data, charac, S_D_C_D_6);
	anim_iterbis(data, charac, S_D_C_D_7);
	anim_iterbis(data, charac, S_D_C_D_8);
	anim_iterbis(data, charac, S_D_C_D_9);
	anim_iterbis(data, charac, S_D_C_D_10);
	anim_iterbis(data, charac, S_D_C_D_11);
	anim_iterbis(data, charac, S_D_C_D_12);
	anim_iterbis(data, charac, S_D_C_D_13);
	anim_iterbis(data, charac, S_D_C_D_14);
	anim_iterbis(data, charac, S_D_C_D_15);
	anim_iterbis(data, charac, S_D_C_D_15);
}

void	anim_die(t_data *data, t_charac *charac)
{
	while (1)
	{
		if (!(charac->s_charac))
			exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
		charac->pos_y = find_pos(data->map, 'y');
		charac->pos_x = find_pos(data->map, 'x');
		data->map[charac->pos_y][charac->pos_x] = '0';
		if (charac->pos_y == 0 || charac->pos_x == 0)
			break ;
		charac->c_y = (charac->pos_y * 32) + (2 * 32);
		charac->c_x = (charac->pos_x * 32) + (1 * 32);
		anim(data, charac);
	}
	sleep(1);
}
