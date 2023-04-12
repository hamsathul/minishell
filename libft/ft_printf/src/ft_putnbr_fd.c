/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:51:21 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/21 09:15:00 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr_fd(long long int nbr, int fd)
{
	const char	*base = "0123456789";
	int			nbr_len;

	nbr_len = 0;
	if (nbr == -9223372036854775807)
	{
		write(1, "-9223372036854775807", 20);
		return (20);
	}
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr_len += ft_putnbr_fd(-nbr, fd);
	}
	else if (nbr >= 10)
	{
		ft_putnbr_fd((nbr / 10), fd);
		ft_putnbr_fd((nbr % 10), fd);
	}
	else
		write (fd, &base[nbr], 1);
	nbr_len += ft_nbrlen_base(nbr, ft_strlen(base));
	return (nbr_len);
}
