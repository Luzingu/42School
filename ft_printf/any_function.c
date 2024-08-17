/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:47:31 by aluzingu          #+#    #+#             */
/*   Updated: 2024/05/20 09:47:32 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_pf(char c, int *num_caract)
{
	write(1, &c, 1);
	(*num_caract)++;
}

void	ft_putstr_pf(char *str, int *num_caract)
{
	if (str == NULL)
		ft_putstr_pf("(null)", num_caract);
	else
	{
		while (*str)
		{
			ft_putchar_pf(*str, num_caract);
			str++;
		}
	}
}

void	ft_put_ptr(void *ptr, int *num_caract)
{
	unsigned long	ponteiro;

	ponteiro = (unsigned long)ptr;
	if (ptr == NULL)
		ft_putstr_pf("(nil)", num_caract);
	else
	{
		ft_putstr_pf("0x", num_caract);
		ft_put_base(ponteiro, num_caract, "0123456789abcdef", 16);
	}
}

void	ft_put_base(unsigned long long number, int *num_caract,
		char *base, unsigned int base_len)
{
	if (number >= base_len)
		ft_put_base(number / base_len, num_caract, base, base_len);
	ft_putchar_pf(base[number % base_len], num_caract);
}

void	ft_putnbr(int number, int *num_caract)
{
	if (number == -2147483648)
		ft_putstr_pf("-2147483648", num_caract);
	else if (number < 0)
	{
		ft_putchar_pf('-', num_caract);
		number = -number;
		ft_putnbr(number, num_caract);
	}
	else if (number > 9)
	{
		ft_putnbr((number / 10), num_caract);
		ft_putchar_pf((number % 10) + 48, num_caract);
	}
	else
		ft_putchar_pf(number + 48, num_caract);
}
