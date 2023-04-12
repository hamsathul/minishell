/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:19:51 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/22 12:19:51 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include "../../include/libft.h"

size_t	gnl_strlen(char *str);
char	*gnl_strchr(char *str, int c);
char	*gnl_strjoin(char *line, char *buff);
char	*get_next_line(int fd);

#endif