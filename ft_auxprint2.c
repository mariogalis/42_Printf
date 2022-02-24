/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxprint2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:21:25 by magonzal          #+#    #+#             */
/*   Updated: 2022/02/21 13:21:46 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_pointer(unsigned long int num, int *count)
{
	put_str("0x", count);
	put_hex(num, count, 'x');
}

void	put_hex(unsigned long int num, int *count, char c)
{
	if (num >= 16)
	{
		put_hex(num / 16, count, c);
		put_hex(num % 16, count, c);
	}
	else
	{
		if (num <= 9)
			put_char((num + '0'), count);
		else
		{
			if (c == 'x')
				put_char((num - 10 + 'a'), count);
			else
				put_char((num - 10 + 'A'), count);
		}
	}
}
