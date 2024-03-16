/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klimrung <klimrung@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:05:56 by klimrung          #+#    #+#             */
/*   Updated: 2024/03/13 13:02:52 by klimrung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int num)
{
	int		len;
	long	nb;

	len = 0;
	nb = num;
	if (num < 0)
	{
		ft_putchar('-');
		nb = -nb;
		len++;
	}
	if (nb >= 10)
		len += ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
	len++;
	return (len);
}

int	ft_putuint(unsigned int u)
{
	int	len;

	len = 0;
	if (u >= 10)
		len += ft_putuint(u / 10);
	ft_putchar(u % 10 + '0');
	len++;
	return (len);
}

int	ft_puthex(unsigned int hex, int is_upper)
{
	int		len;
	char	*base;

	len = 0;
	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (hex >= 16)
	{
		len += ft_puthex(hex / 16, is_upper);
		len += ft_puthex(hex % 16, is_upper);
	}
	else
		len += ft_putchar(base[hex % 16]);
	return (len);
}

int	ft_putptr(void *ptr, int first)
{
	unsigned long long	p;
	int					len;
	char				*base;

	if (!ptr && first)
		return (ft_putstr("(nil)"));
	p = (unsigned long long)ptr;
	len = 0;
	base = "0123456789abcdef";
	if (first)
		len += ft_putstr("0x");
	if (p >= 16)
	{
		len += ft_putptr((void *)(p / 16), 0);
		len += ft_putptr((void *)(p % 16), 0);
	}
	else
		len += ft_putchar(base[p % 16]);
	return (len);
}
