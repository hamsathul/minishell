/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:17:37 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/28 23:54:27 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

int	ft_pwd(char **argv)
{
	char	*cwd;

	if (*(argv + 1) && check_option(*(argv + 1)) == EXIT_FAILURE)
		return (error_usage("pwd", strerror(errno)));
	cwd = getcwd(NULL, 0);
	ft_putstr_fd(cwd, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	free(cwd);
	return (EXIT_SUCCESS);
}

// int main(int ac, char **argv)
// {
// 	ft_pwd(argv);
// }