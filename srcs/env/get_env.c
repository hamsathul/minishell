/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:30:00 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/29 22:35:04 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

t_env	*get_env(char *name)
{
	t_env			*ptr;
	unsigned int	len;

	ptr = g_manager.env;
	len = ft_strlen(name);
	while (ptr)
	{
		if (ft_strlen(ptr->name) == len && ft_strncmp(name, ptr->name, len) == 0)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}