/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:18:07 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/29 22:38:24 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

int	ft_unset(char **argv)
{
	t_env	*var;
	int		exit_code;

	exit_code = EXIT_SUCCESS;
	if (!*(argv + 1))
		return (exit_code);
	argv++;
	while (*argv)
	{
		if (check_option(*argv) == EXIT_FAILURE)
			exit_code = error_usage("unset", *argv) + 1;
		else if (ft_strchr(*argv, '='))
			exit_code = error_env("unset", *argv);
		else if (valid_env_name(*argv) == EXIT_FAILURE)
			exit_code = error_env("unset", *argv);
		else
		{
			var = get_env(*argv);
			if (var)
				remove_env(var);
		}
		argv++;
	}
	return (exit_code);
}
