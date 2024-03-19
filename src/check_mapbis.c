/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapbis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:21:44 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/08 09:03:26 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
