/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:07:04 by aluzingu          #+#    #+#             */
/*   Updated: 2024/05/20 09:07:06 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_other(va_list args, const char *str, int *num_caract)
{
	if (*str == 'c')
		ft_putchar_pf(va_arg(args, int), num_caract);
	else if (*str == 's')
		ft_putstr_pf(va_arg(args, char *), num_caract);
	else if (*str == 'p')
		ft_put_ptr(va_arg(args, void *), num_caract);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(args, int), num_caract);
	else if (*str == 'u')
		ft_put_base(va_arg(args, unsigned int), num_caract, "0123456789", 10);
	else if (*str == 'x')
	{
		ft_put_base(va_arg(args, unsigned int),
			num_caract, "0123456789abcdef", 16);
	}
	else if (*str == 'X')
	{
		ft_put_base(va_arg(args, unsigned int),
			num_caract, "0123456789ABCDEF", 16);
	}
	else if (*str == '%')
		ft_putchar_pf(*str, num_caract);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			num_caract;

	num_caract = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_print_other(args, str, &num_caract);
		}
		else
			ft_putchar_pf(*str, &num_caract);
		str++;
	}
	va_end(args);
	return (num_caract);
}
