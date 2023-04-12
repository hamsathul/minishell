/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:16:18 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/19 11:34:16 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*s;

	ch = (unsigned char)c;
	s = (unsigned char *)str;
	while (n)
	{
		if (*s == ch)
			return (s);
		s++;
		n--;
	}
	return (NULL);
}
