/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_simple_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:35:00 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/01 01:38:57 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	free_simple_command(t_simple_command *simple_command)
{
	int	ac;

	ac = 0;
	while (simple_command->argv[ac])
		free(simple_command->argv[ac++]);
	free(simple_command->argv);
	free(simple_command);
}
