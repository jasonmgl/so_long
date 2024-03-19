/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_open_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:57:50 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/16 14:35:23 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

#define S_D_O_0			"../bonus/sprites_bonus/anim_open/door_close0.xpm"
#define S_D_O_1			"../bonus/sprites_bonus/anim_open/door_close1.xpm"
#define S_D_O_2			"../bonus/sprites_bonus/anim_open/door_close2.xpm"
#define S_D_O_3			"../bonus/sprites_bonus/anim_open/door_close3.xpm"
#define S_D_O_4			"../bonus/sprites_bonus/anim_open/door_close4.xpm"
#define S_D_O_5			"../bonus/sprites_bonus/anim_open/door_close5.xpm"
#define S_D_O_6			"../bonus/sprites_bonus/anim_open/door_close6.xpm"
#define S_D_O_7			"../bonus/sprites_bonus/anim_open/door_close7.xpm"
#define S_D_O_8			"../bonus/sprites_bonus/anim_open/door_close8.xpm"
#define S_D_O_9			"../bonus/sprites_bonus/anim_open/door_close9.xpm"
#define S_D_O_10		"../bonus/sprites_bonus/anim_open/door_close10.xpm"
#define S_D_O_11		"../bonus/sprites_bonus/anim_open/door_close11.xpm"
#define S_D_O_12		"../bonus/sprites_bonus/anim_open/door_close12.xpm"
#define S_D_O_13		"../bonus/sprites_bonus/anim_open/door_close13.xpm"
#define S_D_O_14		"../bonus/sprites_bonus/anim_open/door_close14.xpm"
#define S_D_O_15		"../bonus/sprites_bonus/anim_open/door_close15.xpm"
#define S_D_O_16		"../bonus/sprites_bonus/anim_open/door_close16.xpm"
#define S_D_O_17		"../bonus/sprites_bonus/anim_open/door_close17.xpm"
#define S_D_O_18		"../bonus/sprites_bonus/anim_open/door_close18.xpm"
#define S_D_O_19		"../bonus/sprites_bonus/anim_open/door_close19.xpm"
#define S_D_O_20		"../bonus/sprites_bonus/anim_open/door_close20.xpm"
#define S_D_O_21		"../bonus/sprites_bonus/anim_open/door_close21.xpm"
#define S_D_O_22		"../bonus/sprites_bonus/anim_open/door_close22.xpm"
#define S_D_O_23		"../bonus/sprites_bonus/anim_open/door_close23.xpm"
#define S_D_O_24		"../bonus/sprites_bonus/anim_open/door_close24.xpm"
#define S_D_O_25		"../bonus/sprites_bonus/anim_open/door_close25.xpm"

static void	anim(t_data *data, t_map *d_map)
{
	anim_iter(data, d_map, S_D_O_0);
	anim_iter(data, d_map, S_D_O_1);
	anim_iter(data, d_map, S_D_O_2);
	anim_iter(data, d_map, S_D_O_3);
	anim_iter(data, d_map, S_D_O_4);
	anim_iter(data, d_map, S_D_O_5);
	anim_iter(data, d_map, S_D_O_6);
	anim_iter(data, d_map, S_D_O_7);
	anim_iter(data, d_map, S_D_O_8);
	anim_iter(data, d_map, S_D_O_9);
	anim_iter(data, d_map, S_D_O_10);
	anim_iter(data, d_map, S_D_O_11);
	anim_iter(data, d_map, S_D_O_12);
	anim_iter(data, d_map, S_D_O_13);
	anim_iter(data, d_map, S_D_O_14);
	anim_iter(data, d_map, S_D_O_15);
	anim_iter(data, d_map, S_D_O_16);
	anim_iter(data, d_map, S_D_O_17);
	anim_iter(data, d_map, S_D_O_18);
	anim_iter(data, d_map, S_D_O_19);
	anim_iter(data, d_map, S_D_O_20);
	anim_iter(data, d_map, S_D_O_21);
	anim_iter(data, d_map, S_D_O_22);
	anim_iter(data, d_map, S_D_O_23);
	anim_iter(data, d_map, S_D_O_24);
}

void	anim_open(t_data *data, t_map *d_map)
{
	anim(data, d_map);
	anim_iter(data, d_map, S_D_O_25);
	if (!(d_map->s_d))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
}
