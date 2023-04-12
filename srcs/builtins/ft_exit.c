/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:13:01 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/29 10:48:50 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

static int	check_long(unsigned long long res, int sign)
{
	if (res > 9223372036854775807UL && sign > 0)
		return (FALSE);
	if (res > 9223372036854775808UL && sign < 0)
		return (FALSE);
	return (TRUE);
}

int	valid_exit_code(const char *s)
{
	char				*ptr;
	unsigned long long	res;
	int					sign;

	ptr = (char *)s;
	res = 0;
	sign  = 1;
	if (*ptr == '-')
	{
		sign = -1;
		ptr++;
	}
	while (*ptr)
	{
		if (res > res * 10 + (*ptr - '0'))
			return (FALSE);
		res = res * 10 + (*ptr - '0');
		ptr++;
	}
	return (check_long(res, sign));
}

unsigned char	check_exit_arg(char *arg)
{
	char	*ptr;

	ptr = arg;
	if (*ptr == '-')
		ptr++;
	while (*ptr)
	{
		if (!ft_isdigit(*ptr))
		{
			error_general("exit", ptr, "numeric argument required");
			exit(EXIT_MAX);
		}
		ptr++;
	}
	if (valid_exit_code(arg) == FALSE)
	{
		error_general("exit", ptr, "numeric argument required");
		exit(EXIT_MAX);
	}
	return (ft_atoi(arg));
}

int	ft_exit(char **argv)
{
	unsigned char	exit_code;

	exit_code = EXIT_SUCCESS;
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (*(argv + 1))
	{
		exit_code = check_exit_arg(*(argv + 1));
		if (*(argv + 2))
			return (error_general("exit", NULL, "too many arguments"));
	}
	free_env();
	exit(exit_code);
	return (EXIT_FAILURE);
}

// int main(int ac, char **av)
// {
// 	(void)ac;
// 	ft_exit(av);
// }
