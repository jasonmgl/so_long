/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:36:53 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/01 09:07:09 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s)
{
	char		*ptr;
	size_t		len;

	if (!s)
		return (NULL);
	len = ft_strlen((char *)s);
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return ((char *) NULL);
	ft_memcpy(ptr, (const void *)s, (size_t)len);
	ptr[len] = '\0';
	return (ptr);
}
