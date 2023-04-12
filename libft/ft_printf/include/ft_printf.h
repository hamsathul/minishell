/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:17:22 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/21 13:34:30 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdarg.h>
# include	<unistd.h>
# include	<stdio.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
size_t	ft_nbrlen_base(long long int nbr, size_t base_len);
int		ft_putchar(char c);
int		ft_putptr(unsigned long long int ptr);
int		ft_putstr(char *str);
int		ft_putnbr_fd(long long int nbr, int fd);
size_t	ft_unbrlen_base(unsigned long long int nbr, size_t base_len);
int		ft_uputnbr_base(unsigned long long int nbr, const char *base);

#endif