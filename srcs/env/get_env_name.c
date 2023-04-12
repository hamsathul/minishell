/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:47:55 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/29 13:01:30 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

char	*get_env_name(char *argv)
{
	char	*name;
	size_t	len;

	if (!ft_strchr(argv, '='))
		len = ft_strlen(argv) + 1;
	else
		len = ft_strchr(argv, '=') - argv + 1;
	name = (char *)mini_calloc(len, sizeof(char));
	if (!name)
		exit(EXIT_FAILURE);
	ft_strlcpy(name, argv, len);
	return (name);
}
