/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:22:29 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/19 11:35:15 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	word_length(int c)
{
	int	i;

	if (c < 0)
		i = 1;
	else
		i = 0;
	while (1)
	{
		c /= 10;
		i++;
		if (c == 0)
			break ;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	wordlen;
	char	*str;
	long	nbr;

	nbr = n;
	wordlen = word_length (n);
	str = (char *)malloc(sizeof(char) * (wordlen + 1));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	str[wordlen] = '\0';
	while (1)
	{
		str[wordlen - 1] = nbr % 10 + '0';
		nbr /= 10;
		wordlen--;
		if (nbr == 0)
			break ;
	}
	return (str);
}
