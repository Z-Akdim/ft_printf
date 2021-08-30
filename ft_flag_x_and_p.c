/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_x_and_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:25:51 by zakdim            #+#    #+#             */
/*   Updated: 2020/01/18 18:21:20 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_specefier_p_sp_zr(t_var *var)
{
	char *adres;

	adres = "0x";
	if (var->tr_point == 1 && var->precs == 0)
		ft_puts(adres, var);
	if (var->width && !var->tr_zero && !var->tr_minus)
		while (var->width-- > 0)
			ft_putchar_fd(' ', 1, var);
	if (var->tr_zero && var->tr_minus == 0)
		while (var->width-- > 0)
			ft_putchar_fd('0', 1, var);
	if (!var->tr_zero && var->tr_minus == 0)
		while (var->precs-- > 0)
			ft_putchar_fd('0', 1, var);
	if (var->lenght_agv)
		ft_take_adress(var->hex_adr, var);
	if (var->tr_minus == 1)
		while (var->width-- > 0)
			ft_putchar_fd(' ', 1, var);
}

const char	*specefier_p(const char *frmt, t_var *var)
{
	if (*frmt == 'p')
	{
		var->hex_adr = (unsigned long)va_arg(var->list_arguments, void *);
		var->lenght_agv = lenght_hex((unsigned long)var->hex_adr) + 2;
		if (var->hex_adr == 0 && var->tr_point && var->precs == 0)
			var->lenght_agv = 0;
		var->precs = (var->precs > var->lenght_agv) ?
			var->precs - var->lenght_agv : 0;
		var->width = (var->width > var->precs + var->lenght_agv) ?
			var->width - var->precs - var->lenght_agv : 0;
		ft_specefier_p_sp_zr(var);
	}
	initial_to_zero(var);
	return (++frmt);
}

void		ft_specefier_min_x_print_sp_zr(t_var *var, char c)
{
	if ((var->width && !var->tr_zero && !var->tr_minus))
		while (var->width-- > 0)
			ft_putchar_fd(' ', 1, var);
	if (var->tr_negatife)
		ft_putchar_fd('-', 1, var);
	if (var->tr_zero && var->tr_minus == 0)
		while (var->width-- > 0)
			ft_putchar_fd('0', 1, var);
	if ((!var->tr_zero && var->tr_minus == 0) || (var->tr_minus == 1))
		while (var->precs-- > 0)
			ft_putchar_fd('0', 1, var);
	if (var->lenght_agv)
		ft_hex(var, c);
	if (var->tr_minus == 1)
		while (var->width-- > 0)
			ft_putchar_fd(' ', 1, var);
}

const char	*specefier_hex_min_x(const char *frmt, t_var *var)
{
	if ((var->precs >= 0 && var->tr_star == 1)
		|| (var->precs && var->tr_star == 0))
		var->tr_zero = 0;
	var->hex = va_arg(var->list_arguments, unsigned int);
	var->lenght_agv = lenght_hex((unsigned int)var->hex);
	if (var->hex == 0 && var->tr_point && var->precs == 0)
		var->lenght_agv = 0;
	var->precs = (var->precs > var->lenght_agv) ?
		var->precs - var->lenght_agv : 0;
	if (var->tr_negatife)
		var->lenght_agv++;
	var->width = (var->width > var->precs + var->lenght_agv) ? var->width
		- var->precs - var->lenght_agv : 0;
	ft_specefier_min_x_print_sp_zr(var, 'x');
	initial_to_zero(var);
	return (++frmt);
}

const char	*specefier_hex_maj_x(const char *frmt, t_var *var)
{
	if ((var->precs >= 0 && var->tr_star == 1)
			|| (var->precs && var->tr_star == 0))
		var->tr_zero = 0;
	var->hex = va_arg(var->list_arguments, unsigned int);
	var->lenght_agv = lenght_hex((unsigned int)var->hex);
	if (var->hex == 0 && var->tr_point && var->precs == 0)
		var->lenght_agv = 0;
	var->precs = (var->precs > var->lenght_agv) ?
		var->precs - var->lenght_agv : 0;
	if (var->tr_negatife)
		var->lenght_agv++;
	var->width = (var->width > var->precs + var->lenght_agv) ?
		var->width - var->precs - var->lenght_agv : 0;
	ft_specefier_min_x_print_sp_zr(var, 'X');
	initial_to_zero(var);
	return (++frmt);
}
