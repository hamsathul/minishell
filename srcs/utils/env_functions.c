/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:33:36 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/24 17:32:04 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*mini_getenv(char *var, char **envp, int max_var_len)
{
	int	i;
	int	var_len;

	i = 0;
	if (max_var_len < 0)
		max_var_len = ft_strlen(var);
	while (!ft_strchr(var, '=') && envp && envp[i])
	{
		var_len = max_var_len;
		if (var_len < ft_strchr_int(envp[i], '='))
			var_len = ft_strchr_int(envp[i], '=');
		if (!ft_strncmp(envp[i], var, var_len))
			return (ft_substr(envp[i], var_len + 1, ft_strlen(envp[i])));
		i++;
	}
	return (NULL);
}

char	**mini_setenv(char *var, char *value, char **envp, int n)
{
	
}
// int main(int ac, char **av, char **envp)
// {
// 	printf("%s", mini_getenv("PWD", envp, -1));
// }