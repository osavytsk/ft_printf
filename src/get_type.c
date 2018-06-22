/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:34:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 18:34:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

uintmax_t		get_utype(va_list *arg, t_flag *flag)
{
	uintmax_t		res;

	res = va_arg(*arg, uintmax_t);
	if (flag->e_length == hh)
		return (unsigned char)res;
	if (flag->e_length == h)
		return (unsigned short)res;
	if (flag->e_length == l)
		return (unsigned long)res;
	if (flag->e_length == ll)
		return (unsigned long long)res;
	if (flag->e_length == j)
		return (res);
	if (flag->e_length == z)
		return (size_t)res;
	return (unsigned int)res;
}

intmax_t		get_type(va_list *arg, t_flag *flag)
{
	intmax_t		res;

	res = va_arg(*arg, intmax_t);
	if (flag->e_length == hh)
		return (signed char)res;
	if (flag->e_length == h)
		return (short)res;
	if (flag->e_length == l)
		return (long)res;
	if (flag->e_length == ll)
		return (long long)res;
	if (flag->e_length == j)
		return (res);
	if (flag->e_length == z)
		return (size_t)res;
	return (int)res;
}
