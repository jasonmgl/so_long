/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_down_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:32:22 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/16 14:34:35 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

#define S_D_C_F_0			"../bonus/sprites_bonus/anim_front/anim_front0.xpm"
#define S_D_C_F_1			"../bonus/sprites_bonus/anim_front/anim_front1.xpm"
#define S_D_C_F_2			"../bonus/sprites_bonus/anim_front/anim_front2.xpm"
#define S_D_C_F_3			"../bonus/sprites_bonus/anim_front/anim_front3.xpm"
#define S_D_C_F_4			"../bonus/sprites_bonus/anim_front/anim_front4.xpm"
#define S_D_C_F_5			"../bonus/sprites_bonus/anim_front/anim_front5.xpm"
#define S_D_C_F_6			"../bonus/sprites_bonus/anim_front/anim_front6.xpm"
#define S_D_C_F_7			"../bonus/sprites_bonus/anim_front/anim_front7.xpm"
#define S_D_C_F_8			"../bonus/sprites_bonus/anim_front/anim_front8.xpm"
#define S_D_C_F_9			"../bonus/sprites_bonus/anim_front/anim_front9.xpm"
#define S_D_C_F_10			"../bonus/sprites_bonus/anim_front/anim_front10.xpm"
#define S_D_C_F_11			"../bonus/sprites_bonus/anim_front/anim_front11.xpm"
#define S_D_C_F_12			"../bonus/sprites_bonus/anim_front/anim_front12.xpm"
#define S_D_C_F_13			"../bonus/sprites_bonus/anim_front/anim_front13.xpm"
#define S_D_C_F_14			"../bonus/sprites_bonus/anim_front/anim_front14.xpm"
#define S_D_C_F_15			"../bonus/sprites_bonus/anim_front/anim_front15.xpm"
#define S_D_C_F_16			"../bonus/sprites_bonus/anim_front/anim_front16.xpm"

static void	anim(t_data *data, t_map *d_map)
{
	anim_iter(data, d_map, S_D_C_F_0);
	anim_iter(data, d_map, S_D_C_F_1);
	anim_iter(data, d_map, S_D_C_F_2);
	anim_iter(data, d_map, S_D_C_F_3);
	anim_iter(data, d_map, S_D_C_F_4);
	anim_iter(data, d_map, S_D_C_F_5);
	anim_iter(data, d_map, S_D_C_F_6);
	anim_iter(data, d_map, S_D_C_F_7);
	anim_iter(data, d_map, S_D_C_F_8);
	anim_iter(data, d_map, S_D_C_F_9);
	anim_iter(data, d_map, S_D_C_F_10);
	anim_iter(data, d_map, S_D_C_F_11);
	anim_iter(data, d_map, S_D_C_F_12);
	anim_iter(data, d_map, S_D_C_F_13);
	anim_iter(data, d_map, S_D_C_F_14);
	anim_iter(data, d_map, S_D_C_F_15);
	anim_iter(data, d_map, S_D_C_F_16);
}

void	anim_down(t_data *data, t_map *d_map)
{
	anim(data, d_map);
	if (!(d_map->s_d))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
}
