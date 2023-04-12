/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:41:57 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/29 00:04:29 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

//needs to test this function
int	ft_env(char **argv)
{
	t_env *ptr;

	ptr = g_manager.env;
	if (*(argv + 1))
		return (error_usage("env", *(argv + 1)));
	while (ptr)
	{
		if (ptr->value)
		{
			ft_putstr_fd(ptr->name, STDOUT_FILENO);
			write(STDOUT_FILENO, "=", 1);
			ft_putstr_fd(ptr->value, STDOUT_FILENO);
			write(STDOUT_FILENO, "\n", 1);
		}
		ptr = ptr->next;
	}
	return (EXIT_SUCCESS);
}


// int main(int argc, char **argv, char **envp)
// {
//     (void)argc;
//     (void)argv;

// 	ft_env(envp);
// }