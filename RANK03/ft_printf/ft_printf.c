/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:33:34 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/21 17:13:22 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void    ft_putchar(char c, int *count)
{
    write(1, &c, 1);
    (*count)++;
}

void    ft_putstr(char *s, int *count)
{
    if (!s)
        s = "(null)";
    while (*s)
        ft_putchar(*s++, count);
}

void    ft_putnbr(long nbr, int *count)
{
    if (nbr < 0)
    {
        ft_putchar('-', count);
        nbr = -nbr;
        ft_putnbr(nbr, count);
    }
    else if (nbr > 9)
    {
        ft_putnbr(nbr / 10, count);
        ft_putnbr(nbr % 10, count);
    }
    else
        ft_putchar(nbr + 48, count);
}

void    ft_print_hexa(long nbr, int *count)
{
    char    *base;

    base = "0123456789abcdef";
    if (nbr > 15)
        ft_print_hexa(nbr / 16, count);
    ft_putchar(base[nbr % 16], count);
}

int     ft_printf(char *format, ...)
{
    va_list     args;
    int         count;

    va_start(args, format);
    count = 0;
    while (*format)
    {
        if ((*format == '%') && ((*(format + 1) == 'd') 
                || (*(format + 1) == 's') || (*(format + 1) == 'x')))
        {
            format++;
            if (*format == 's')
                ft_putstr(va_arg(args, char *), &count);
            else if (*format == 'd')
                ft_putnbr((long)va_arg(args, int), &count);
            else if (*format == 'x')
                ft_print_hexa((long)va_arg(args, unsigned int), &count);
        }
        else
            ft_putchar(*format, &count);
        format++;
    }
    va_end(args);
    return (count);
}

/*int     main()
{
    int j = printf("%s\n", NULL);
    int i = ft_printf("%s\n", NULL);
    ft_printf("%d | %d\n", i , j);
    return 0;
}*/