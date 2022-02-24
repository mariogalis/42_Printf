/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:06:39 by mario             #+#    #+#             */
/*   Updated: 2022/02/21 13:21:49 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char(const char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	put_uns(unsigned int num, int *count)
{
	if (num >= 10)
	{
		put_nbr(num / 10, count);
		put_nbr(num % 10, count);
	}
	if (num < 10)
		put_char(num + 48, count);
}

void	put_nbr(int num, int *count)
{	
	if (num < 0)
	{
		if (num == INT_MIN)
		{
			put_str("-2147483648", count);
			return ;
		}
		put_char('-', count);
		num = num * -1;
	}
	if (num >= 10)
	{
		put_nbr(num / 10, count);
		put_nbr(num % 10, count);
	}
	if (num < 10)
		put_char(num + 48, count);
}

void	put_str(char *s, int *count)
{
	if (!s)
	{
		put_str("(null)", count);
		return ;
	}
	while (*s)
		put_char(*s++, count);
}
