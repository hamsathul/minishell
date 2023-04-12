/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:55:04 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/29 22:38:09 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

static int	change_pwd(t_env *pwd)
{
	char	*tmp;

	if (!pwd)
		return (EXIT_FAILURE);
	tmp = pwd->value;
	pwd->value = getcwd(NULL, 0);
	if (!pwd->value)
		return (error_exit("getcwd", strerror(errno), EXIT_FAILURE));
	if (tmp)
		free(tmp);
	return (EXIT_SUCCESS);
}

static int cd_home(void)
{
	t_env	*ptr;
	char	*home;
	int		exit_code;

	exit_code = change_pwd(get_env("OLDPWD"));
	ptr = get_env("HOME");
	if (!ptr)
		return (error_general("cd", NULL, strerror(errno)));
	home = ptr->value;
	exit_code = chdir(home);
	if (exit_code < 0)
		return (error_general("cd", NULL, strerror(errno)));
	exit_code = change_pwd(get_env("PWD"));
	return (EXIT_SUCCESS);
}

int	ft_cd(char **argv)
{
	int	exit_code;

	exit_code = change_pwd(get_env("OLDPWD"));
	if (!*(argv + 1))
		return (cd_home());
	if (check_option(*(argv + 1)) == EXIT_FAILURE)
		return (error_usage("cd", *(argv + 1)));
	exit_code = chdir(*(argv + 1));
	if (exit_code < 0)
		return (error_general("cd", *(argv + 1), strerror(errno)));
	exit_code = change_pwd(get_env("PWD"));
	return (exit_code);
}
