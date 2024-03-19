/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:49:50 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/16 08:19:43 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	error_main(char **map, int fd, char *str, char *error)
{
	if (fd)
		close(fd);
	if (map)
		free_map(map);
	ft_putstr_fd("\e[31mError\n\e[0m", 2);
	if (str)
		ft_putstr_fd(str, 2);
	if (error)
		ft_putstr_fd(error, 2);
	return (1);
}

int	main(int argc, char **argv)
{
	ssize_t	fd;
	char	**map;
	t_map	d_map;
	char	*error;

	ft_memset(&d_map, 0, sizeof(t_map));
	error = NULL;
	if (argc == 2)
	{
		if (check_file_format(argv[1]) == 0)
			return (ft_putstr_fd("\e[31mError\n\e[0m[File format]\n", 2), 1);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (perror("\e[31mError\n\e[0m[Opening file"), 1);
		map = get_map(fd);
		if (!map)
			return (error_main(map, fd, "[Getting map]\n", error));
		error = check_map(map, &d_map);
		if (error)
			return (error_main(map, fd, "[Checking map] : ", error));
		get_window(map, &d_map, fd);
	}
	return (0);
}
