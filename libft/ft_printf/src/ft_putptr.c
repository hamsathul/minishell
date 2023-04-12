/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:43:28 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/20 22:43:28 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putptr(unsigned long long int ptr)
{
	int			nbr_len;
	const char	*base = "0123456789abcdef";

	nbr_len = 0;
	if (ptr == 0)
		return (write(1, "0x0", 3));
	else
	{	
		nbr_len += write(1, "0x", 2);
		ft_uputnbr_base(ptr, base);
		nbr_len += ft_unbrlen_base(ptr, ft_strlen(base));
	}
	return (nbr_len);
}
