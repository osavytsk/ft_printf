/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:17:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 18:17:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <stdint.h>
# include "../libft/includes/libft.h"

typedef struct		s_flag
{
	int				precision;
	int				prec;
	int				width;
	int				plus;
	int				minus;
	int				sharp;
	int				zero;
	int				space;
	enum
	{
		none,
		h,
		hh,
		l,
		ll,
		j,
		z
	}				e_size;
}					t_flags;

/*
**	Spec functions
*/

int					ft_printf(const char *format, ...);
int					pars(char **format, t_flags *flag, va_list *arg);
int					take_specifier(char **format, t_flags *flag, va_list *arg);
int					low_s(va_list *arg, t_flags *flag);
int					up_s(va_list *arg, t_flags *flag);
int					low_i(va_list *arg, t_flags *flag);
int					low_d(va_list *arg, t_flags *flag);
int					up_d(va_list *arg, t_flags *flag);
int					low_p(va_list *arg, t_flags *flag);
int					low_o(va_list *arg, t_flags *flag);
int					up_o(va_list *arg, t_flags *flag);
int					low_u(va_list *arg, t_flags *flag);
int					up_u(va_list *arg, t_flags *flag);
int					low_x(va_list *arg, t_flags *flag);
int					up_x(va_list *arg, t_flags *flag);
int					low_c(va_list *arg, t_flags *flag);
int					up_c(va_list *arg, t_flags *flag);
int					percent(va_list *arg, t_flags *flag);
int					undef(char c, t_flags *flag);

/*
**	Tab and width
*/

void				take_options(char **str, t_flags *flag, va_list *arg);
void				take_flag(char **str, t_flags *flag, va_list *arg);
void				take_width(char **str, t_flags *flag, va_list *arg);
void				take_precision(char **str, t_flags *flag, va_list *arg);
void				take_length(char **str, t_flags *flag, va_list *arg);

/*
**	Utils functions
*/

uintmax_t			take_utype(va_list *arg, t_flags *flag);
intmax_t			take_type(va_list *arg, t_flags *flag);
void				null_flags_struct(t_flags *flag);
void				put_nstr(char *str, int n);
int					str_nlen(char *str, int n);
int					wchar_len(wchar_t c);
int					wstr_len(wchar_t *s);
int					wstr_nlen(wchar_t *s, int n);
void				put_wchar(wchar_t c);
void				put_nwstr(wchar_t *s, int n);
void				put_space(int width, int strlen);
void				put_zero(int width, int strlen);
void				take_int(intmax_t nb);
int					take_len(intmax_t nb);
int					take_flag_len(intmax_t nb, t_flags *flag);
void				take_ui(uintmax_t nb, char *str, int base);
int					take_ui_len(uintmax_t nb, int base);
int					take_ui_flag_len(uintmax_t nb, t_flags *flag, int base);
void				put_int_left_space(t_flags *flag, int len, intmax_t nb);
void				put_uint_left_space(t_flags *flag, int len,
					uintmax_t nb, int type);
void				put_str_left_space(t_flags *flag, int len);

#endif
