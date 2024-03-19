/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmougel <jmougel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:23:51 by jmougel           #+#    #+#             */
/*   Updated: 2024/02/01 09:07:49 by jmougel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	size_t		len;
	char		*str;

	i = 0;
	len = ft_strlen(s);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = (*f)(i, str[i]);
		i++;
	}
	return (str);
}
