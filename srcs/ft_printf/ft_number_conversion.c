/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:00:19 by aledru            #+#    #+#             */
/*   Updated: 2018/03/10 13:55:02 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	int_conversion(t_env *e)
{
	e->offset -= e->precision > e->nb_digit ? e->precision : e->nb_digit;
	e->plus = e->str[e->i] == 'u' || e->str[e->i] == 'U' ? 0 : e->plus;
	e->offset -= e->plus && (intmax_t)e->nbr >= 0 ? 1 : 0;
	if ((intmax_t)e->nbr < 0 && e->zero)
		put_char_to_buf('-', e);
	e->offset -= (intmax_t)e->nbr < 0 ? 1 : 0;
	if (!e->minus && !e->zero)
		put_offset_to_buf(e);
	if (e->plus && (intmax_t)e->nbr >= 0)
		put_char_to_buf('+', e);
	if ((intmax_t)e->nbr < 0 && !e->zero && e->str[e->i] != 'u' &&
			e->str[e->i] != 'U')
		put_char_to_buf('-', e);
	if ((e->str[e->i] == 'd' || e->str[e->i] == 'i' || e->str[e->i] == 'D')
			&& (intmax_t)e->nbr >= 0 && e->space && !e->plus)
		put_char_to_buf(' ', e);
	if (e->zero)
		put_zero_to_buf(e);
	put_precision_to_buf(e, e->nb_digit);
	if (!(e->nbr == 0 && e->precision == 0 && e->is_precision_specified))
		put_str_to_buf(base_converter_d_u(e), e);
	if (e->minus)
		put_offset_to_buf(e);
}

void	octal_conversion(t_env *e)
{
	int	print_zero;

	e->zero = (e->str[e->i] == 'O' || e->str[e->i] == 'o') && e->precision == 0
		&& e->is_precision_specified == 1 ? 0 : e->zero;
	print_zero = e->sharp == 1 && e->precision == 0 &&
		e->is_precision_specified ? 1 : 0;
	e->sharp = e->sharp == 1 && e->nbr == 0 ? 0 : e->sharp;
	e->offset -= e->precision > e->nb_digit ? e->precision : e->nb_digit;
	e->offset -= e->precision > e->nb_digit ? 0 : e->sharp;
	if (e->sharp && e->precision <= e->nb_digit && e->nbr)
		e->precision += e->nb_digit - e->precision + 1;
	e->offset += e->nbr == 0 && e->precision == 0 &&
		e->is_precision_specified == 1 ? 1 : 0;
	if (!e->minus)
		put_offset_to_buf(e);
	put_precision_to_buf(e, e->nb_digit);
	if (!(!e->nbr && !e->precision && e->is_precision_specified && !print_zero))
		put_str_to_buf(base_converter_x_o(e), e);
	if (e->minus)
		put_offset_to_buf(e);
}

void	hexa_conversion(t_env *e)
{
	if (e->sharp && e->is_precision_specified && e->precision == 0)
		e->zero = 0;
	if (e->sharp && (e->nbr != 0 || e->str[e->i] == 'p'))
		e->offset -= 2;
	else
		e->sharp = 0;
	if (e->nbr == 0 && e->precision == 0 && e->is_precision_specified)
		e->offset++;
	e->offset -= e->precision > e->nb_digit ? e->precision : e->nb_digit;
	if (e->sharp && e->zero && e->caps)
		put_str_to_buf(ft_strdup("0X"), e);
	if (e->sharp && e->zero && !e->caps)
		put_str_to_buf(ft_strdup("0x"), e);
	if (!e->minus)
		put_offset_to_buf(e);
	if (e->sharp && e->caps && !e->zero && (e->nbr || e->str[e->i] == 'p'))
		put_str_to_buf(ft_strdup("0X"), e);
	if (e->sharp && !e->caps && !e->zero && (e->nbr || e->str[e->i] == 'p'))
		put_str_to_buf(ft_strdup("0x"), e);
	put_precision_to_buf(e, e->nb_digit);
	if (!(e->nbr == 0 && e->precision == 0 && e->is_precision_specified))
		put_str_to_buf(base_converter_x_o(e), e);
	if (e->minus)
		put_offset_to_buf(e);
}
