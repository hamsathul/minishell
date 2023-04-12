/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:51:21 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/19 11:34:53 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar_fd ('-', fd);
		nb = nb * -1;
	}
	if (nb >= 10)
		ft_putnbr_fd (nb / 10, fd);
	ft_putchar_fd ((nb % 10) + '0', fd);
}
