/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:17:19 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/19 11:34:13 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static size_t	get_size_max(void)
{
	static size_t	max;

	max = 0;
	if (max == 0)
	{
		max -= 1U;
	}
	return (max);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = malloc(count * size);
	if (!(ptr))
		return (NULL);
	if (size && get_size_max() / size < count)
		return (NULL);
	ft_memset (ptr, 0, count * size);
	return (ptr);
}
