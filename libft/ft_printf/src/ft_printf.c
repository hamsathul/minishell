/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:59:50 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/20 11:59:50 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_conversion(va_list ap, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format == 'p')
		return (ft_putptr(va_arg(ap, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_fd (va_arg(ap, int), 1));
	else if (format == 'u')
		return (ft_uputnbr_base(va_arg(ap, unsigned int), "0123456789"));
	else if (format == 'x')
		return (ft_uputnbr_base(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_uputnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		length;
	va_list	ap;

	i = 0;
	length = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]) != 0)
		{
			length += ft_conversion(ap, format[i + 1]);
			i++;
		}
		else
			length += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (length);
}
