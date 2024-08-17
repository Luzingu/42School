/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:07:16 by aluzingu          #+#    #+#             */
/*   Updated: 2024/05/20 09:07:18 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

void	ft_putchar_pf(char c, int *num_caract);
void	ft_putstr_pf(char *str, int *num_caract);
void	ft_put_ptr(void *ptr, int *num_caract);
void	ft_put_base(unsigned long long number, int *num_caract,
			char *base, unsigned int base_len);
void	ft_putnbr(int number, int *num_caract);
int		ft_printf(const char *str, ...);
#endif
