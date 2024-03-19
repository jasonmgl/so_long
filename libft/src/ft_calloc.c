/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:34:39 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/01 09:04:24 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	n;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	n = nmemb * size;
	ptr = (void *) malloc(n);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n);
	return (ptr);
}
