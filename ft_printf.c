/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:06:24 by mario             #+#    #+#             */
/*   Updated: 2022/02/21 13:35:18 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	ar;

	count = 0;
	va_start(ar, s);
	if (!s)
		return (0);
	count = printf_aux(s, ar, count);
	va_end(ar);
	return (count);
}

int	printf_aux(const char *s, va_list ar, int count)
{
	while (*s)
	{
		while (*s != '%' && *s)
			put_char(*s++, &count);
		if (!*s)
			return (count);
		if (*(s + 1) == '%')
			put_char('%', &count);
		else if (*(s + 1) == 'd' || *(s + 1) == 'i')
			put_nbr(va_arg(ar, int), &count);
		else if (*(s + 1) == 'c')
			put_char(va_arg(ar, int), &count);
		else if (*(s + 1) == 's')
			put_str(va_arg(ar, char *), &count);
		else if (*(s + 1) == 'p')
			put_pointer(va_arg(ar, unsigned long int), &count);
		else if (*(s + 1) == 'u')
			put_uns(va_arg(ar, unsigned int), &count);
		else if (*(s + 1) == 'x' || *(s + 1) == 'X')
			put_hex(va_arg(ar, unsigned int), &count, *(s + 1));
		s = s + 2;
	}
	return (count);
}
