/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:21:05 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/29 22:28:50 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

void	free_env(void)
{
	t_env	*temp;

	while (g_manager.env)
	{
		temp = g_manager.env;
		g_manager.env = g_manager.env->next;
		if (temp->name)
			free(temp->name);
		if (temp->value)
			free(temp->value);
		free(temp);
	}
}
