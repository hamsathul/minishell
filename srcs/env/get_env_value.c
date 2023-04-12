/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:02:30 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/29 13:05:22 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

char	*get_env_value(char *argv)
{
	char	*value;
	char	*ptr;
	int		len;

	ptr = ft_strchr(argv, '=');
	if (!ptr)
		return (NULL);
	ptr++;
	len = ft_strlen(ptr) + 1;
	value = (char *)mini_calloc(len, sizeof(char));
	if (!value)
		exit(EXIT_FAILURE);
	ft_strlcpy(value, ptr, len);
	return (value);
}
