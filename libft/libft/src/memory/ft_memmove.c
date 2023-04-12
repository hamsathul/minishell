/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:48:02 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/19 11:34:24 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memmove(void *to, const void *from, size_t n)
{
	unsigned char	*to_p;
	unsigned char	*from_p;
	size_t			i;

	to_p = (unsigned char *) to;
	from_p = (unsigned char *) from;
	if (to == NULL && from == NULL)
		return (NULL);
	i = 0;
	if (from_p > to_p)
	{
		while (i < n)
		{
			to_p[i] = from_p[i];
			i++;
		}
	}
	else
		ft_memcpy(to, from, n);
	return (to);
}

/* int main()
{
	char from[] = "hello world";
	char to[] = "world";
	printf("To before memmove: %s", to);
	ft_memmove(to, from, sizeof(from));
	printf("\nTo after memmove: %s", to);
} */