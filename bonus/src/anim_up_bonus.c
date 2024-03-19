/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_up_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:32:22 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/16 15:07:11 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

#define S_D_C_B_0			"../bonus/sprites_bonus/anim_back/anim_back0.xpm"
#define S_D_C_B_1			"../bonus/sprites_bonus/anim_back/anim_back1.xpm"
#define S_D_C_B_2			"../bonus/sprites_bonus/anim_back/anim_back2.xpm"
#define S_D_C_B_3			"../bonus/sprites_bonus/anim_back/anim_back3.xpm"
#define S_D_C_B_4			"../bonus/sprites_bonus/anim_back/anim_back4.xpm"
#define S_D_C_B_5			"../bonus/sprites_bonus/anim_back/anim_back5.xpm"
#define S_D_C_B_6			"../bonus/sprites_bonus/anim_back/anim_back6.xpm"
#define S_D_C_B_7			"../bonus/sprites_bonus/anim_back/anim_back7.xpm"
#define S_D_C_B_8			"../bonus/sprites_bonus/anim_back/anim_back8.xpm"
#define S_D_C_B_9			"../bonus/sprites_bonus/anim_back/anim_back9.xpm"
#define S_D_C_B_10			"../bonus/sprites_bonus/anim_back/anim_back10.xpm"
#define S_D_C_B_11			"../bonus/sprites_bonus/anim_back/anim_back11.xpm"
#define S_D_C_B_12			"../bonus/sprites_bonus/anim_back/anim_back12.xpm"
#define S_D_C_B_13			"../bonus/sprites_bonus/anim_back/anim_back13.xpm"
#define S_D_C_B_14			"../bonus/sprites_bonus/anim_back/anim_back14.xpm"
#define S_D_C_B_15			"../bonus/sprites_bonus/anim_back/anim_back15.xpm"
#define S_D_C_B_16			"../bonus/sprites_bonus/anim_back/anim_back16.xpm"
#define S_D_C_B_17			"../bonus/sprites_bonus/anim_back/anim_back17.xpm"

static void	anim(t_data *data, t_map *d_map)
{
	anim_iter(data, d_map, S_D_C_B_0);
	anim_iter(data, d_map, S_D_C_B_1);
	anim_iter(data, d_map, S_D_C_B_2);
	anim_iter(data, d_map, S_D_C_B_3);
	anim_iter(data, d_map, S_D_C_B_4);
	anim_iter(data, d_map, S_D_C_B_5);
	anim_iter(data, d_map, S_D_C_B_6);
	anim_iter(data, d_map, S_D_C_B_7);
	anim_iter(data, d_map, S_D_C_B_8);
	anim_iter(data, d_map, S_D_C_B_9);
	anim_iter(data, d_map, S_D_C_B_10);
	anim_iter(data, d_map, S_D_C_B_11);
	anim_iter(data, d_map, S_D_C_B_12);
	anim_iter(data, d_map, S_D_C_B_13);
	anim_iter(data, d_map, S_D_C_B_14);
	anim_iter(data, d_map, S_D_C_B_15);
	anim_iter(data, d_map, S_D_C_B_16);
	anim_iter(data, d_map, S_D_C_B_17);
}

void	anim_up(t_data *data, t_map *d_map)
{
	anim(data, d_map);
	if (!(d_map->s_d))
		exit_fail(data, "\e[31mError\n\e[0mxpm_to_img()\n");
}
