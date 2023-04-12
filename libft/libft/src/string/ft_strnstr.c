/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:09:21 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/19 11:35:58 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (1)
	{
		if (little[j] == '\0')
			return ((char *)big + (i - j));
		if (big[i] == little [j])
			j++;
		else
		{
			i -= j;
			j = 0;
		}
		if (big[i] == '\0' || i >= len)
			return (NULL);
		i++;
	}	
}
