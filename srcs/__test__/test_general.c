/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 23:25:32 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/04 23:25:54 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/test.h"

void	test_general(void)
{
	char	**arg;
	char	**ptr;
	char	*tmp;

	arg = ft_split(g_manager.command_line, ' ');
	exec_general(arg);
	ptr = arg;
	while (*ptr)
	{
		tmp = *ptr;
		ptr++;
		free(tmp);
	}
	free(arg);
}
