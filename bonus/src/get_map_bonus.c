/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:17:41 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/14 11:30:35 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	display_map(char **map)
{
	size_t	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

char	**duplicate_map(char **map)
{
	char	**dup_map;
	size_t	i;

	i = 0;
	dup_map = NULL;
	if (!map)
		return (NULL);
	dup_map = (char **)malloc(sizeof(char *) * (check_nbr_line(map) + 1));
	if (!dup_map)
		return (NULL);
	while (map[i])
	{
		dup_map[i] = ft_strdup(map[i]);
		if (!dup_map[i])
			return (free_map(dup_map), NULL);
		i++;
	}
	dup_map[check_nbr_line(map)] = NULL;
	return (dup_map);
}

char	**get_map(int fd)
{
	char	**map;
	char	*tmp;
	char	*read;
	char	*line;

	line = ft_strdup("");
	if (!line)
		return (NULL);
	while (1)
	{
		tmp = line;
		read = get_next_line(fd);
		if (!read)
			break ;
		line = ft_strjoin(line, read);
		if (!line)
			line = ft_strdup("");
		free_read(read, tmp);
	}
	if (!*line)
		return (free(line), NULL);
	map = ft_split(line, '\n');
	if (!map)
		return (free(line), NULL);
	return (free(line), map);
}
