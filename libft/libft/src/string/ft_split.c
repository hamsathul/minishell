/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:14:20 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/02/09 12:03:07 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	word_count(const char *str, char c)
{
	size_t	i;
	size_t	toggle;

	i = 0;
	toggle = 0;
	while (*str)
	{
		if (*str != c && toggle == 0)
		{
			toggle = 1;
			i++;
		}
		else if (*str == c)
			toggle = 0;
		str++;
	}
	return (i);
}

static int	word_length(const char *str, char c)
{
	size_t	wordlength;

	if (!ft_strchr (str, c))
		wordlength = ft_strlen (str);
	else
		wordlength = ft_strchr (str, c) - str;
	return (wordlength);
}

char	**ft_split(const char *str, char c)
{
	char	**split;
	size_t	i;

	if (!str)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (word_count(str, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str)
		{
			split[i++] = ft_substr (str, 0, word_length (str, c));
			str = str + word_length (str, c);
		}
	}
	split[i] = NULL;
	return (split);
}
