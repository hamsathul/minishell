/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:13:33 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/19 11:34:10 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/* int main()
{
    char str[] = "hello world how are you";

    printf("\nBefore memset(): %s\n", str);  
    ft_bzero(str + 13, 8*sizeof(char));  
    printf("After memset():  %s", str);
    return 0;
} */