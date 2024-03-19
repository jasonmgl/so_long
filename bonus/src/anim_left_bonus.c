/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_left_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:32:22 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/16 14:34:36 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

#define S_D_C_L_0			"../bonus/sprites_bonus/anim_left/anim_left0.xpm"
#define S_D_C_L_1			"../bonus/sprites_bonus/anim_left/anim_left1.xpm"
#define S_D_C_L_2			"../bonus/sprites_bonus/anim_left/anim_left2.xpm"
#define S_D_C_L_3			"../bonus/sprites_bonus/anim_left/anim_left3.xpm"
#define S_D_C_L_4			"../bonus/sprites_bonus/anim_left/anim_left4.xpm"
#define S_D_C_L_5			"../bonus/sprites_bonus/anim_left/anim_left5.xpm"
#define S_D_C_L_6			"../bonus/sprites_bonus/anim_left/anim_left6.xpm"
#define S_D_C_L_7			"../bonus/sprites_bonus/anim_left/anim_left7.xpm"
#define S_D_C_L_8			"../bonus/sprites_bonus/anim_left/anim_left8.xpm"
#define S_D_C_L_9			"../bonus/sprites_bonus/anim_left/anim_left9.xpm"
#define S_D_C_L_10			"../bonus/sprites_bonus/anim_left/anim_left10.xpm"
#define S_D_C_L_11			"../bonus/sprites_bonus/anim_left/anim_left11.xpm"
#define S_D_C_L_12			"../bonus/sprites_bonus/anim_left/anim_left12.xpm"
#define S_D_C_L_13			"../bonus/sprites_bonus/anim_left/anim_left13.xpm"
#define S_D_C_L_14			"../bonus/sprites_bonus/anim_left/anim_left14.xpm"
#define S_D_C_L_15			"../bonus/sprites_bonus/anim_left/anim_left15.xpm"
#define S_D_C_L_16			"../bonus/sprites_bonus/anim_left/anim_left16.xpm"

static void	anim(t_data *data, t_map *d_map)
{
	anim_iter(data, d_map, S_D_C_L_0);
	anim_iter(data, d_map, S_D_C_L_1);
	anim_iter(data, d_map, S_D_C_L_2);
	anim_iter(data, d_map, S_D_C_L_3);
	anim_iter(data, d_map, S_D_C_L_4);
	anim_iter(data, d_map, S_D_C_L_5);
	anim_iter(data, d_map, S_D_C_L_6);
	anim_iter(data, d_map, S_D_C_L_7);
	anim_iter(data, d_map, S_D_C_L_8);
	anim_iter(data, d_map, S_D_C_L_9);
	anim_iter(data, d_map, S_D_C_L_10);
	anim_iter(data, d_map, S_D_C_L_11);
	anim_iter(data, d_map, S_D_C_L_12);
	anim_iter(data, d_map, S_D_C_L_13);
	anim_iter(data, d_map, S_D_C_L_14);
	anim_iter(data, d_map, S_D_C_L_15);
	anim_iter(data, d_map, S_D_C_L_16);
}

void	anim_left(t_data *data, t_map *d_map)
{
	anim(data, d_map);
	if (!(d_map->s_d))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
}
