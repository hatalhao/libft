/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:17:30 by hatalhao          #+#    #+#             */
/*   Updated: 2023/11/03 18:20:09 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	isleft;

	if (!s)
		return (0);
	if (start >= ft_strlen(s) || !len)
	{
		substring = (char *) malloc ((1) * sizeof(char));
		if (substring == NULL)
			return (NULL);
		substring[0] = '\0';
		return (substring);
	}
	isleft = ft_strlen(s + start);
	if (len > isleft)
		len = isleft;
	substring = (char *) malloc ((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	substring = ft_memcpy(substring, s + start, len);
	substring[len] = '\0';
	return (substring);
}
