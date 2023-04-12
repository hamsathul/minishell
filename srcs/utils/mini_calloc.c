/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:53:30 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/29 12:59:44 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	*mini_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*res;

	res = (void *)malloc(size * count);
	if (!res)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size * count)
	{
		*((char *)res + i) = '\0';
		i++;
	}
	return (res);
}