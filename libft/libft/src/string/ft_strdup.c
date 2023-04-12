/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:08:23 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/19 11:35:27 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strdup(const char *s)
{
	size_t	length;
	char	*dup;
	size_t	i;

	length = ft_strlen(s);
	dup = (char *)malloc(sizeof(char) * (length + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/* int main()
{
    char *str = "hello world";
    char *dup = ft_strdup(str);
  
        printf("%s",dup);
} */