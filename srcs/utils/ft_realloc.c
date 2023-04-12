/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:50:51 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/31 22:51:18 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	*ft_realloc(void *ptr, size_t size)
{
	int		i;
	char	*src;
	char	*dst;

	i = 0;
	src = (char *)ptr;
	dst = (char *)malloc(size);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	free(ptr);
	return ((void *)dst);
}
