/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:25:57 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/29 13:29:46 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

void	remove_env(t_env *var)
{
	t_env	*temp;

	temp = g_manager.env;
	if (temp == var)
		g_manager.env = temp->next;
	else
	{
		while (temp->next != var)
		temp = temp->next;
		temp->next = var->next;
	}
	free(var->name);
	free(var->value);
	free(var);
}