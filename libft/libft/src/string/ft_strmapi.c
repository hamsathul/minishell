/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:20:51 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/19 11:35:50 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	char	*str;

	index = 0;
	if (!s || !f)
		return (NULL);
	str = ft_strdup (s);
	if (str == NULL)
		return (NULL);
	while (str[index])
	{
		str[index] = (*f)(index, str[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}
