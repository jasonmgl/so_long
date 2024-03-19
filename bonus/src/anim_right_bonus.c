/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_right_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:32:22 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/16 15:06:48 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

#define S_D_C_20			"../bonus/sprites_bonus/anim_right/anim_close20.xpm"
#define S_D_C_R_0			"../bonus/sprites_bonus/anim_right/anim_right0.xpm"
#define S_D_C_R_1			"../bonus/sprites_bonus/anim_right/anim_right1.xpm"
#define S_D_C_R_2			"../bonus/sprites_bonus/anim_right/anim_right2.xpm"
#define S_D_C_R_3			"../bonus/sprites_bonus/anim_right/anim_right3.xpm"
#define S_D_C_R_4			"../bonus/sprites_bonus/anim_right/anim_right4.xpm"
#define S_D_C_R_5			"../bonus/sprites_bonus/anim_right/anim_right5.xpm"
#define S_D_C_R_6			"../bonus/sprites_bonus/anim_right/anim_right6.xpm"
#define S_D_C_R_7			"../bonus/sprites_bonus/anim_right/anim_right7.xpm"
#define S_D_C_R_8			"../bonus/sprites_bonus/anim_right/anim_right8.xpm"
#define S_D_C_R_9			"../bonus/sprites_bonus/anim_right/anim_right9.xpm"
#define S_D_C_R_10			"../bonus/sprites_bonus/anim_right/anim_right10.xpm"
#define S_D_C_R_11			"../bonus/sprites_bonus/anim_right/anim_right11.xpm"
#define S_D_C_R_12			"../bonus/sprites_bonus/anim_right/anim_right12.xpm"
#define S_D_C_R_13			"../bonus/sprites_bonus/anim_right/anim_right13.xpm"
#define S_D_C_R_14			"../bonus/sprites_bonus/anim_right/anim_right14.xpm"
#define S_D_C_R_15			"../bonus/sprites_bonus/anim_right/anim_right15.xpm"
#define S_D_C_R_16			"../bonus/sprites_bonus/anim_right/anim_right16.xpm"

static void	anim(t_data *data, t_map *d_map)
{
	anim_iter(data, d_map, S_D_C_R_0);
	anim_iter(data, d_map, S_D_C_R_1);
	anim_iter(data, d_map, S_D_C_R_2);
	anim_iter(data, d_map, S_D_C_R_3);
	anim_iter(data, d_map, S_D_C_R_4);
	anim_iter(data, d_map, S_D_C_R_5);
	anim_iter(data, d_map, S_D_C_R_6);
	anim_iter(data, d_map, S_D_C_R_7);
	anim_iter(data, d_map, S_D_C_R_8);
	anim_iter(data, d_map, S_D_C_R_9);
	anim_iter(data, d_map, S_D_C_R_10);
	anim_iter(data, d_map, S_D_C_R_11);
	anim_iter(data, d_map, S_D_C_R_12);
	anim_iter(data, d_map, S_D_C_R_13);
	anim_iter(data, d_map, S_D_C_R_14);
	anim_iter(data, d_map, S_D_C_R_15);
	anim_iter(data, d_map, S_D_C_R_16);
}

void	anim_right(t_data *data, t_map *d_map)
{
	anim(data, d_map);
	if (!(d_map->s_d))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
}
