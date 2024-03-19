/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapbis_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:21:44 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/16 14:09:42 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

size_t	check_nbr_line(char **map)
{
	size_t	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
		i++;
	return (i);
}

static size_t	check_wall_full(char *map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
	{
		if (map[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static size_t	check_wall_part(char *map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	if (map[i] != '1')
		return (0);
	i++;
	while (map[i])
		i++;
	if (map[i - 1] != '1')
		return (0);
	return (1);
}

size_t	check_wall(char **map)
{
	size_t	i;
	size_t	nbr_line;

	i = 1;
	if (!map)
		return (0);
	nbr_line = check_nbr_line(map);
	if (nbr_line < 3 || ft_strlen(map[0]) < 3
		|| (nbr_line == 3 && ft_strlen(map[0]) == 3))
		return (0);
	if (!(check_wall_full(map[0])) || !(check_wall_full(map[0])))
		return (0);
	while (i < (nbr_line - 1))
	{
		if (!(check_wall_part(map[i])) || !(check_wall_part(map[i])))
			return (0);
		i++;
	}
	if (!(check_wall_full(map[nbr_line - 1]))
		|| !(check_wall_full(map[nbr_line - 1])))
		return (0);
	return (1);
}

int	check_screen_size(t_data *data)
{
	int	max_width;
	int	max_height;
	int	width;
	int	height;

	width = (data->d_map->nbr_x * 32) + (2 * 32);
	height = (data->d_map->nbr_y * 32) + (4 * 32);
	mlx_get_screen_size(data->p_mlx, &max_width, &max_height);
	if (height > max_height || width > max_width)
		return (0);
	data->p_win = mlx_new_window(data->p_mlx, width, height, "SO_LONG");
	if (!data->p_win)
		return (0);
	return (1);
}
