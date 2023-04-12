/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:49:35 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/04 22:24:10 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

static void	env_quotes(void)
{
	t_env	*ptr;

	ptr = g_manager.env;
	while (ptr)
	{
		ft_putstr_fd(ptr->name, STDOUT_FILENO);
		if (ptr->value)
		{
			write(STDOUT_FILENO, "=\"", 2);
			ft_putstr_fd(ptr->value, STDOUT_FILENO);
			write(STDOUT_FILENO, "\"", 1);
		}
		write(STDOUT_FILENO, "\n", 1);
		ptr = ptr->next;
	}
}

static void exec_export(char *argv)
{
	char	*name;
	char	*value;
	t_env	*ptr;

	name = get_env_name(argv);
	value = get_env_value(argv);
	ptr = get_env(name);
	if (ptr)
	{
		if (value)
		{
			if (ptr->value)
				free(ptr->value);
			ptr->value = value;
		}
		free(name);
	}
	else
		add_env(name, get_env_value(argv));
}
/* Export command marks an environment variable to be 
forwarded to the child processes. environment variables 
are set when we open a new shell session. at any time 
if we change any of the variable values, the shell has 
no way of picking that change. The export command, on the 
other hand, provides the ability to update the current shell 
session about the change we made to the exported variable.
we don’t have to wait until new shell session to use the 
value of the variable you changed. */
int	ft_export(char	**argv)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (!argv[1])
	{
		env_quotes();
		return (exit_code);
	}
	argv++;
	while (*argv)
	{
		if (check_option(*argv) == EXIT_FAILURE)
			exit_code = error_usage("export", *argv) + 1;
		else if (valid_env_name(*argv) == EXIT_FAILURE)
			exit_code = error_env("export", *argv);
		else
			exec_export(*argv);
		argv++;
	}
	return (exit_code);
}