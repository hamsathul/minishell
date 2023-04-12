/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 23:26:07 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/04 23:26:37 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/test.h"

t_token	get_token(void);

/* main insert below init_manager(command_line) */
void	test_token(void)
{
	t_token	token;

	token = get_token();
	while (token.type != T_NULL)
	{
		printf("%d: %s\n", token.type, token.value);
		free(token.value);
		token = get_token();
	}
	free(token.value);
}
