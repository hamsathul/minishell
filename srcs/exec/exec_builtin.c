/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:00:59 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/01 02:13:06 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int	exec_builtin(char **argv)
{
	if (!ft_strncmp(*argv, "echo", 5))
		return (ft_echo(argv));
	if (!ft_strncmp(*argv, "cd", 3))
		return (ft_cd(argv));
	if (!ft_strncmp(*argv, "pwd", 4))
		return (ft_pwd(argv));
	if (!ft_strncmp(*argv, "env", 4))
		return (ft_env(argv));
	if (!ft_strncmp(*argv, "export", 7))
		return (ft_export(argv));
	if (!ft_strncmp(*argv, "unset", 6))
		return (ft_unset(argv));
	if (!ft_strncmp(*argv, "exit", 5))
		return (ft_exit(argv));
	return (EXIT_FAILURE);
}
