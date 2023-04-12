/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 23:24:47 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/04 23:30:35 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/test.h"

/* main insert below readline() */
void	test_builtin(void)
{
	char	**arg;
	char	**ptr;
	char	*tmp;

	arg = ft_split(g_manager.command_line, ' ');
	exec_builtin(arg);
	ptr = arg;
	while (*ptr)
	{
		tmp = *ptr;
		ptr++;
		free(tmp);
	}
	free(arg);
}
