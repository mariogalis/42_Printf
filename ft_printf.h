/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:06:32 by mario             #+#    #+#             */
/*   Updated: 2022/02/21 13:34:54 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int		ft_printf(const char *s, ...);
int		printf_aux(const char *s, va_list ar, int count);
void	put_nbr(int num, int *count);
void	put_char(char c, int *count);
void	put_str(char *s, int *count);
void	put_uns(unsigned int num, int *count);
void	put_hex(unsigned long int p, int *count, char c);
void	put_pointer(unsigned long int p, int *count);

#endif