/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:14:29 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/19 11:35:42 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*  int main()
 {
     char src[] = "Worldfdfd";
     char dest[] = "Hello ";
	 char src1[] = "World";
	 char dest1[] = "Hello";
     printf("%zu | %s\n", ft_strlcpy(dest, src,0), dest);
     printf("%lu | %s", strlcpy(dest1, src1,5), dest1);
     return 0;
 } */
