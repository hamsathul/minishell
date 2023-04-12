/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:53:49 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/04/04 14:32:59 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft/include/libft.h"
# include "minishell.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	*mini_calloc(size_t count, size_t size);
int		mini_strcmp(char *s1, char *s2);
int		mini_isspace(int c);
void	*ft_realloc(void *ptr, size_t size);
char	*mini_find_path(char *cmd);
void	mini_exit_eof(char *command_line);

#endif