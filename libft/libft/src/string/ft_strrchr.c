/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:44:15 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/10 22:44:15 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	length;

	length = ft_strlen(str);
	while (length >= 0)
	{
		if (str[length] == (char)c)
			return ((char *)str + length);
		length--;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

/* int main()
{
	char str[] = "www.google.com";
	printf("%s", ft_strrchr(str,'.'));	
} */