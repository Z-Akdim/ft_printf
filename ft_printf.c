/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:36:56 by zakdim            #+#    #+#             */
/*   Updated: 2020/01/18 18:21:30 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const	char	*check_flag(const char *frmt, t_var *var)
{
	if (*frmt == '-' || *frmt == '*' || *frmt == '0' ||
			(*frmt >= '0' && *frmt <= '9') || *frmt == '%')
	{
		while (*frmt == '0' || *frmt == '-' || *frmt == '*')
		{
			var->tr_zero = (*frmt == '0') ? 1 && frmt++ : var->tr_zero;
			var->tr_minus = (*frmt == '-') ? 1 && frmt++ : var->tr_minus;
			var->tr_star = (*frmt == '*') ? 1 && frmt++ : var->tr_star;
		}
		frmt = ft_check_width(frmt, var, &var->width);
	}
	else
		frmt = ft_check_specefier(frmt, var);
	return (frmt);
}

const	char	*format_check(const char *frmt, t_var *var)
{
	while (*frmt)
	{
		frmt = ft_puts(frmt, var);
		if (*frmt == '%')
		{
			frmt++;
			frmt = check_flag(frmt, var);
		}
	}
	return (frmt);
}

int				ft_printf(const char *frmt, ...)
{
	t_var		var;

	initial_to_zero(&var);
	var.nbr_return = 0;
	va_start(var.list_arguments, frmt);
	frmt = format_check(frmt, &var);
	va_end(var.list_arguments);
	return (var.nbr_return);
}
