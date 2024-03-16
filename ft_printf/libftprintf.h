/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klimrung <klimrung@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:00:19 by klimrung          #+#    #+#             */
/*   Updated: 2024/03/13 17:00:54 by klimrung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	treat_n_print(char format, va_list *args);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(int num);
int	ft_putuint(unsigned int u);
int	ft_puthex(unsigned int hex, int is_upper);
int	ft_putptr(void *ptr, int first);

#endif
