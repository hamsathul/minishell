/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_env_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:46:10 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/04 22:26:31 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

int	valid_env_name(char *name)
{
	char *ptr;

	ptr = name;
	if (((*name < 'a' || *name > 'z') && (*name < 'A'
		|| *name > 'Z')) && *name != '_')
		return (EXIT_FAILURE);
	while (*ptr && *ptr != '=')
	{
		if (((*ptr < 'a' || *ptr > 'z') && (*ptr < 'A' || *ptr > 'Z'))
			&& (*ptr != '_') && ((*ptr < '0' || *ptr > '9')))
			return (EXIT_FAILURE);
		ptr++;
	}
	return (EXIT_SUCCESS);
}
