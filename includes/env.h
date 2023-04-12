/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:29:00 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/02 23:08:46 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

#include "minishell.h"

# define PATHENV "PATH"
# define TMPENV "TMPDIR"
# define TMPDIR "/tmp/"
# define TMPKEY "minishell"

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

int		valid_env_name(char *name);
char	*get_env_value(char *argv);
char	*get_env_name(char *argv);
void	remove_env(t_env *var);
void	add_env(char *name, char *value);
void	free_env(void);
t_env	*get_env(char *name);

#endif