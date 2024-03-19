/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:07:29 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/20 08:37:13 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

size_t	check_players(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i++])
		{
			if (map[j][i] == 'P')
			{
				if (map[j - 1][i] == 'P')
					return (0);
				else if (map[j + 1][i] == 'P')
					return (0);
				else if (map[j][i - 1] == 'P')
					return (0);
				else if (map[j][i + 1] == 'P')
					return (0);
			}
		}
		i = 0;
		j++;
	}
	return (1);
}

size_t	check_file_format(char *argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
		i++;
	if (ft_strncmp(&argv[i - 4], ".ber", 4) != 0)
		return (0);
	return (1);
}

void	flood_fill(t_charac *charac, size_t *e, size_t x, size_t y)
{
	char	p_char;
	char	n_char;

	p_char = '0';
	n_char = 'x';
	if (charac->map[y][x] == '1' || charac->map[y][x] == n_char
		|| charac->map[y][x] == 'X')
		return ;
	if (charac->map[y][x] == p_char)
		charac->map[y][x] = n_char;
	else if (charac->map[y][x] == 'C')
	{
		charac->collect += 1;
		charac->map[y][x] = n_char;
	}
	else if (charac->map[y][x] == 'E')
	{
		*e += 1;
		charac->map[y][x] = '1';
		return ;
	}
	flood_fill(charac, e, x + 1, y);
	flood_fill(charac, e, x - 1, y);
	flood_fill(charac, e, x, y + 1);
	flood_fill(charac, e, x, y - 1);
}

size_t	check_validity(char **map)
{
	t_charac	*charac;
	char		**dup_map;
	size_t		e;

	e = 0;
	dup_map = NULL;
	charac = NULL;
	if (!map)
		return (0);
	charac = init_charac(map);
	if (!charac)
		return (0);
	dup_map = duplicate_map(map);
	if (!dup_map)
		return (free_charac(charac), 0);
	charac->map = dup_map;
	flood_fill(charac, &e, charac->pos_x, charac->pos_y);
	if (e != 1 || charac->collect != charac->goal)
		return (free_map(dup_map), free_charac(charac), 0);
	free_map(dup_map);
	charac->map = NULL;
	free_charac(charac);
	return (1);
}
