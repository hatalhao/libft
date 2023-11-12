/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 03:44:27 by hatalhao          #+#    #+#             */
/*   Updated: 2023/11/06 03:44:30 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// char	**ft_split(char const *s, char c)
// {
// 	char		**str;
// 	int			counter;
// 	int			in_word;
// 	int			len;
// 	int			i;
// 	const char	*p;
// 	const char	*start;

// 	if (s == NULL)
// 		return (NULL);
// 	counter = 0;
// 	in_word = 0;
// 	p = s;
// 	while (*p)
// 	{
// 		if (*p == c)
// 			in_word = 0;
// 		else if (in_word == 0)
// 		{
// 			counter++;
// 			in_word = 1;
// 		}
// 		p++;
// 	}
// 	str = malloc((counter + 1) * sizeof(char *));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (*s)
// 	{
// 		if (*s != c)
// 		{
// 			start = s;
// 			while (*s && *s != c)
// 				s++;
// 			len = s - start;
// 			str[i] = (char *)malloc((len + 1) * sizeof(char));
// 			if (!str[i])
// 				return (NULL);
// 			ft_memcpy(str[i], start, len);
// 			str[i][len] = '\0';
// 			i++;
// 		}
// 		else
// 			s++;
// 	}
// 	str[counter] = NULL;
// 	return (str);
// }

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int			counter;
	int			in_word;
	char const	*p;

	if (s == NULL)
		return (0);
	counter = 0;
	in_word = 0;
	p = s;
	while (*p)
	{
		if (*p == c)
			in_word = 0;
		else if (in_word == 0)
		{
			counter++;
			in_word = 1;
		}
		p++;
	}
	return (counter);
}

static char **fri_ol(char **str)
{
	int i;

	while (str[i])
		free(str[i++]);
	free(str);
	return(NULL);
}

static char **khadija(char **str, char const *s, char c)
{
	const char	*start;
	int			i;
	int			len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			len = s - start;
			str[i] = (char *)malloc((len + 1) * sizeof(char));
			if (!str[i])
				return (fri_ol(str));
			ft_memcpy(str[i], start, len);
			str[i][len] = '\0';
			i++;
		}
		else
			s++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char		**str;

	str = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	return (khadija(str, s, c));
}

// int main()
// {
// 	char    *str;

// 	str = "   Hello world, is everything alright?";
// 	char** ret = ft_split(str, ' ');
// 	int i = 0;
// 	while (ret[i])
// 	{
// 		printf("%s\n", ret[i]);
// 		i++;
// 	}
// 	return (0);
// }
