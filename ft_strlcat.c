/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:50:20 by hatalhao          #+#    #+#             */
/*   Updated: 2023/11/04 21:55:59 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	source_length;
	size_t	destination_length;
	size_t	target_length;
	size_t	i;

	if (!size)
		return (ft_strlen(src));
	source_length = ft_strlen(src);
	destination_length = 0;
	i = 0;
	while (destination_length < size && dest[destination_length])
		destination_length++;
	if (size == destination_length)
		target_length = source_length + size;
	else
	{
		while (src[i] && (i + destination_length) < size - 1)
		{
			dest[i + destination_length] = src[i];
			i++;
		}
		dest[i + destination_length] = '\0';
		target_length = destination_length + source_length;
	}
	return (target_length);
}
