/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:11:16 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/14 11:30:25 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	free_read(char *read, char *tmp)
{
	free(read);
	free(tmp);
	read = NULL;
	tmp = NULL;
}

void	free_map(char **map)
{
	size_t	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map[i]);
	map[i] = NULL;
	free(map);
	map = NULL;
}

void	free_charac(t_charac *charac)
{
	charac->pos_x = 0;
	charac->pos_y = 0;
	charac->goal = 0;
	charac->collect = 0;
	charac->s_charac = NULL;
	free(charac);
	charac = NULL;
}

void	free_t_string(t_string *string)
{
	free(string->collect);
	free(string->goal);
	free(string->life);
	free(string->move);
}
