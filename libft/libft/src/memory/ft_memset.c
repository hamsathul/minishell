/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:24:27 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/19 11:34:28 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	while (n > 0)
	{
		*str = c;
		n--;
		str++;
	}
	return (s);
}

/* int main()
{
    char str[] = "hello world how are you";

    printf("\nBefore memset(): %s\n", str);  
    ft_memset(str + 13, '.', 8*sizeof(char));  
    printf("After memset():  %s", str);
    return 0;
} */