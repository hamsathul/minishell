/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:23:05 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/19 11:34:22 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memcpy(void *to, const void *from, size_t n)
{
	unsigned char	*from_p;
	unsigned char	*to_p;

	from_p = (unsigned char *)from;
	to_p = (unsigned char *)to;
	if (from == NULL && to == NULL)
		return (NULL);
	while (n > 0)
	{
		n--;
		to_p[n] = from_p[n];
	}
	return (to);
}

/* int main ()
{
 char from[] = "hero";
 char to[] = "zero";
 printf("Before memcpy: %s", to);
 ft_memcpy(to, from, sizeof(from));
 printf("\nAfter memcpy: %s", to);
} */
