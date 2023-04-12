/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:31:31 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/29 00:02:29 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/error.h"

int	error_exit(char *cmd, char *err, int exit_code)
{
	g_manager.exit_code = exit_code;
	error_general(cmd, NULL, err);
	exit(g_manager.exit_code);
	return (EXIT_FAILURE);
}

// int main(void)
// {
// 	error_exit("pwd", "error", 1);
// }