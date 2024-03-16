/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klimrung <klimrung@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:53:53 by klimrung          #+#    #+#             */
/*   Updated: 2024/03/13 18:09:19 by klimrung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	if (!s)
		return (ft_putstr("(null)"));
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	treat_n_print(char format, va_list *args)
{
	if (format == '%')
		return (ft_putchar(format));
	else if (format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (format == 'i' || format == 'd')
		return (ft_putnbr(va_arg(*args, int)));
	else if (format == 'p')
		return (ft_putptr(va_arg(*args, void *), 1));
	else if (format == 'u')
		return (ft_putuint(va_arg(*args, unsigned int)));
	else if (format == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), 0));
	else if (format == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), 1));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	int			printed;
	int			i;
	va_list		args;

	if (!format)
		return (-1);
	i = 0;
	printed = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
				printed += treat_n_print(format[i], &args);
		}
		else
			printed += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (printed);
}
