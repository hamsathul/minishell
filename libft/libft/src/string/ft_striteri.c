/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:05:32 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/19 11:35:30 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return ;
	if (s || f)
	{
		j = ft_strlen (s);
		while (i < j)
		{
			(*f)(i, s);
			s++;
			i++;
		}
	}
}
