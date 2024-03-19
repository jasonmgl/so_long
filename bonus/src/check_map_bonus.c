/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:03:43 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/17 14:09:48 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static size_t	check_len(char **map, t_map	*d_map)
{
	size_t	i;
	size_t	len_first_line;
	size_t	len_comp;

	i = 1;
	if (!map)
		return (0);
	len_first_line = ft_strlen(map[0]);
	if (len_first_line < 3)
		return (0);
	while (map[i])
	{
		len_comp = ft_strlen(map[i]);
		if (len_first_line - len_comp != 0)
			return (0);
		i++;
	}
	d_map->last_l = i - 1;
	d_map->nbr_x = len_first_line;
	d_map->nbr_y = i;
	return (1);
}

size_t	check_char(char **map, char c)
{
	size_t	i;
	size_t	j;
	size_t	nbr_c;

	i = 0;
	j = 0;
	nbr_c = 0;
	if (!map || !ft_isalpha(c))
		return (0);
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == c)
				nbr_c++;
			j++;
		}
		j = 0;
		i++;
	}
	return (nbr_c);
}

static size_t	set_char(char c)
{
	if (!c)
		return (0);
	if (c == 'P')
		return (1);
	else if (c == 'E')
		return (1);
	else if (c == 'C')
		return (1);
	else if (c == '0')
		return (1);
	else if (c == 'X')
		return (1);
	else if (c == '1')
		return (1);
	else
		return (0);
}

static size_t	check_valid_char(char **map)
{
	size_t	i;
	size_t	j;
	size_t	c;

	i = 0;
	j = 0;
	c = 0;
	if (!map)
		return (0);
	while (map[i])
	{
		while (map[i][j])
		{
			if (!(set_char(map[i][j])))
				return (0);
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		j = 0;
		i++;
	}
	if (c < 1)
		return (0);
	return (1);
}

char	*check_map(char **map, t_map	*d_map)
{
	if (!(check_len(map, d_map)))
		return ("check_len()\n");
	if (!(check_valid_char(map)))
		return ("check_valid_char()\n");
	if (!(check_char(map, 'P')))
		return ("check_char()\n");
	if (!(check_players(map)))
		return ("check_players()\n");
	if (check_char(map, 'E') != 1)
		return ("check_char()\n");
	if (!(check_wall(map)))
		return ("check_wall()\n");
	if (!(check_validity(map)))
		return ("check_validity()\n");
	return (NULL);
}
