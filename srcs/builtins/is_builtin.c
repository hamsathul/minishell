/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:46:26 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/29 14:07:10 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

int	is_builtin(char *func_name)
{
	if (!mini_strcmp(func_name, "cd"))
		return (TRUE);
	else if (!mini_strcmp(func_name, "echo"))
		return (TRUE);
	else if (!mini_strcmp(func_name, "pwd"))
		return (TRUE);
	else if (!mini_strcmp(func_name, "env"))
		return (TRUE);
	else if (!mini_strcmp(func_name, "exit"))
		return (TRUE);
	else if (!mini_strcmp(func_name, "export"))
		return (TRUE);
	else if (!mini_strcmp(func_name, "unset"))
		return (TRUE);
	else
		return (FALSE);
}
