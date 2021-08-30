/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_s_and_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:25:51 by zakdim            #+#    #+#             */
/*   Updated: 2020/01/19 11:15:21 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		specefier_s_printf_sp_zr(t_var *var)
{
	if (var->width && !var->tr_zero && !var->tr_minus)
		while (var->space-- > 0)
			ft_putchar_fd(' ', 1, var);
	if (var->tr_zero && var->tr_minus == 0)
		while (var->space-- > 0)
			ft_putchar_fd('0', 1, var);
	if (var->lenght_agv)
		ft_putarg(var->string, var);
	if (var->tr_minus == 1)
		while (var->space-- > 0)
			ft_putchar_fd(' ', 1, var);
}

const char	*specefier_s(const char *frmt, t_var *var)
{
	if (*frmt == 's')
	{
		var->string = va_arg(var->list_arguments, char *);
		if (var->string == NULL)
			var->string = "(null)";
		var->lenght_agv = ft_lenght_string(var->string);
		if (var->tr_point == 1)
			var->precs = (var->precs > var->lenght_agv ||
				var->precs < 0) ? var->lenght_agv : var->precs;
		else
			var->precs = var->lenght_agv;
		var->space = (var->width > var->precs) ? var->width - var->precs : 0;
		specefier_s_printf_sp_zr(var);
	}
	initial_to_zero(var);
	return (++frmt);
}

const char	*specefier_c(const char *frmt, t_var *var)
{
	char c;

	c = va_arg(var->list_arguments, int);
	var->lenght_agv = 1;
	var->precs = var->lenght_agv;
	if (var->tr_point == 1)
		var->precs = (var->precs > var->lenght_agv ||
			var->precs < 0) ? var->lenght_agv : var->precs;
	else
		var->precs = var->lenght_agv;
	var->space = (var->width > var->precs) ? var->width - var->precs : 0;
	if (var->width && !var->tr_zero && !var->tr_minus)
		while (var->space-- > 0)
			ft_putchar_fd(' ', 1, var);
	if (var->tr_zero && var->tr_minus == 0)
		while (var->space-- > 0)
			ft_putchar_fd('0', 1, var);
	if (var->lenght_agv)
		ft_putchar_fd(c, 1, var);
	if (var->tr_minus == 1)
		while (var->space-- > 0)
			ft_putchar_fd(' ', 1, var);
	initial_to_zero(var);
	return (++frmt);
}
