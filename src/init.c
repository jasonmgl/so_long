/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:14:11 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/16 09:37:29 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	find_pos(char **map, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!map || !c || (c != 'y' && c != 'x'))
		return (0);
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				if (c == 'y')
					return (i);
				else if (c == 'x')
					return (j);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

t_charac	*init_charac(char **map)
{
	t_charac	*charac;

	charac = NULL;
	if (!map)
		return (NULL);
	charac = (t_charac *)malloc(sizeof(t_charac) * 1);
	if (!charac)
		return (NULL);
	charac->collect = 0;
	charac->s_charac = NULL;
	charac->move = 0;
	charac->pos_y = find_pos(map, 'y');
	charac->pos_x = find_pos(map, 'x');
	charac->goal = check_char(map, 'C');
	charac->map = NULL;
	if (charac->pos_y == 0 || charac->pos_x == 0)
		return (free_charac(charac), NULL);
	if (charac->goal == 0)
		return (free_charac(charac), NULL);
	return (charac);
}

void	init_data(t_data *data, t_charac *charac, char **map, t_map *d_map)
{
	data->p_mlx = NULL;
	data->p_win = NULL;
	data->fd = 0;
	data->charac = NULL;
	data->map = map;
	data->d_map = d_map;
	if (!charac)
		exit_fail(data, "\e[31mError\n\e[0minit_data()\n");
	data->charac = charac;
}
