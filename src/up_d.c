/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:56:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 18:56:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			upper_d(va_list *arg, t_flag *flag)
{
	long		nb;
	int			len;

	nb = va_arg(*arg, long);
	if (flag->prec)
		flag->zero = 0;
	len = get_flag_len(nb, flag);
	put_int_left_space(flag, len, nb);
	if (!(flag->prec && flag->precision == 0 && nb == 0))
		get_int(nb);
	if (flag->minus && flag->width)
		put_space(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
