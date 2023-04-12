/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:33:57 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/19 11:35:35 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	length_check(char const *s1, char const *s2)
{
	size_t	length;

	length = 0;
	if (s1)
		length += ft_strlen (s1);
	if (s2)
		length += ft_strlen (s2);
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	joined = (char *)malloc(sizeof(char) * (length_check (s1, s2) + 1));
	if (joined == NULL)
		return (NULL);
	if (s1 && s2)
	{
		ft_memcpy (joined, s1, ft_strlen(s1));
		ft_memcpy (joined + ft_strlen(s1), s2, ft_strlen(s2));
	}
	else if (s1 && !s2)
		ft_memcpy (joined, s1, ft_strlen(s1));
	else if (!s1 && s2)
		ft_memcpy (joined, s2, ft_strlen(s2));
	else
		return (NULL);
	joined[length_check (s1, s2)] = '\0';
	return (joined);
}
