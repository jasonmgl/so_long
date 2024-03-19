/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:12:57 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/16 08:28:36 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	img_to_win(t_data *data, void *sprite, int x, int y)
{
	return (mlx_put_image_to_window(data->p_mlx, data->p_win, sprite, x, y));
}

inline void	*xpm_to_img(void *p_mlx, char *path_file, int *width, int *height)
{
	return (mlx_xpm_file_to_image(p_mlx, path_file, width, height));
}

void	set_img(t_data *data, t_map *d_map, t_charac *charac, char *map)
{
	if (ft_strncmp(map, "1", 1) == 0)
		img_to_win(data, d_map->s_b, d_map->c_x, d_map->c_y);
	else if (ft_strncmp(map, "0", 1) == 0)
		img_to_win(data, d_map->s_e, d_map->c_x, d_map->c_y);
	else if (ft_strncmp(map, "C", 1) == 0)
		img_to_win(data, d_map->s_c, d_map->c_x, d_map->c_y);
	else if (ft_strncmp(map, "E", 1) == 0)
		img_to_win(data, d_map->s_d, d_map->c_x, d_map->c_y);
	else if (ft_strncmp(map, "P", 1) == 0)
	{
		img_to_win(data, charac->s_charac, d_map->c_x, d_map->c_y);
		data->charac->c_x = d_map->c_x;
		data->charac->c_y = d_map->c_y;
	}
}
