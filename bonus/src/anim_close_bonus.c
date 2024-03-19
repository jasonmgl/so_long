/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_close_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:57:50 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/16 14:34:30 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

#define S_D_O_0			"../bonus/sprites_bonus/anim_open/door_close0.xpm"
#define S_D_C_0			"../bonus/sprites_bonus/anim_close/anim_close0.xpm"
#define S_D_C_1			"../bonus/sprites_bonus/anim_close/anim_close1.xpm"
#define S_D_C_2			"../bonus/sprites_bonus/anim_close/anim_close2.xpm"
#define S_D_C_3			"../bonus/sprites_bonus/anim_close/anim_close3.xpm"
#define S_D_C_4			"../bonus/sprites_bonus/anim_close/anim_close4.xpm"
#define S_D_C_5			"../bonus/sprites_bonus/anim_close/anim_close5.xpm"
#define S_D_C_6			"../bonus/sprites_bonus/anim_close/anim_close6.xpm"
#define S_D_C_7			"../bonus/sprites_bonus/anim_close/anim_close7.xpm"
#define S_D_C_8			"../bonus/sprites_bonus/anim_close/anim_close8.xpm"
#define S_D_C_9			"../bonus/sprites_bonus/anim_close/anim_close9.xpm"
#define S_D_C_10		"../bonus/sprites_bonus/anim_close/anim_close10.xpm"
#define S_D_C_11		"../bonus/sprites_bonus/anim_close/anim_close11.xpm"
#define S_D_C_12		"../bonus/sprites_bonus/anim_close/anim_close12.xpm"
#define S_D_C_13		"../bonus/sprites_bonus/anim_close/anim_close13.xpm"
#define S_D_C_14		"../bonus/sprites_bonus/anim_close/anim_close14.xpm"
#define S_D_C_15		"../bonus/sprites_bonus/anim_close/anim_close15.xpm"
#define S_D_C_16		"../bonus/sprites_bonus/anim_close/anim_close16.xpm"
#define S_D_C_17		"../bonus/sprites_bonus/anim_close/anim_close17.xpm"
#define S_D_C_18		"../bonus/sprites_bonus/anim_close/anim_close18.xpm"
#define S_D_C_19		"../bonus/sprites_bonus/anim_close/anim_close19.xpm"

static void	anim(t_data *data, t_map *d_map)
{
	anim_iter(data, d_map, S_D_C_0);
	anim_iter(data, d_map, S_D_C_1);
	anim_iter(data, d_map, S_D_C_2);
	anim_iter(data, d_map, S_D_C_3);
	anim_iter(data, d_map, S_D_C_4);
	anim_iter(data, d_map, S_D_C_5);
	anim_iter(data, d_map, S_D_C_6);
	anim_iter(data, d_map, S_D_C_7);
	anim_iter(data, d_map, S_D_C_8);
	anim_iter(data, d_map, S_D_C_9);
	anim_iter(data, d_map, S_D_C_10);
	anim_iter(data, d_map, S_D_C_11);
	anim_iter(data, d_map, S_D_C_12);
	anim_iter(data, d_map, S_D_C_13);
	anim_iter(data, d_map, S_D_C_14);
	anim_iter(data, d_map, S_D_C_15);
	anim_iter(data, d_map, S_D_C_16);
	anim_iter(data, d_map, S_D_C_17);
	anim_iter(data, d_map, S_D_C_18);
	anim_iter(data, d_map, S_D_C_19);
}

void	anim_close(t_data *data, t_map *d_map)
{
	anim(data, d_map);
	if (!(d_map->s_d))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
	sleep(1);
}
