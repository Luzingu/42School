/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:14:05 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/11 09:14:07 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_extension(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	len -= 4;
	i = 0;
	while (str[len] && ".fdf"[i] == str[len])
	{
		len++;
		i++;
	}
	if (str[len] == '\0')
		return (1);
	return (0);
}

int	get_digit(char c, int base)
{
	int	i;

	i = 0;
	while (i < base)
	{
		if ("0123456789abcdef"[i] == c || "0123456789ABCDEF"[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	ft_atoi_base(char *str, int base)
{
	int	number;
	int	i;
	int	sinal;

	number = 0;
	i = 0;
	sinal = 1;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sinal = -1;
		i++;
	}
	if (base == 16)
		i += 2;
	while (str[i] && get_digit(str[i], base) != -1)
	{
		number = number * base + get_digit(str[i], base);
		i++;
	}
	return (number * sinal);
}

int	ft_isnumber(char *str, int base)
{
	int	i;

	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (base == 16)
	{
		if (str[i] != '0' || str[i + 1] != 'x')
			return (0);
		i += 2;
	}
	if (base == 10 && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i])
	{
		if (get_digit(str[i], base) == -1)
			return (0);
		i++;
	}
	return (1);
}
