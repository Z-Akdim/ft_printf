/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_d_and_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:19:11 by zakdim            #+#    #+#             */
/*   Updated: 2020/01/18 18:21:05 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		specefier_d_print_sp_zr(t_var *var)
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
		ft_putnbr_fd(var->ival, 1, var);
	if (var->tr_minus == 1)
		while (var->width-- > 0)
			ft_putchar_fd(' ', 1, var);
}

const char	*specefier_d_i(const char *frmt, t_var *var)
{
	if (*frmt == 'd' || *frmt == 'i')
	{
		var->ival = va_arg(var->list_arguments, int);
		if (var->ival < 0)
		{
			var->tr_negatife = 1;
			var->ival = -var->ival;
		}
		if ((var->precs >= 0 && var->tr_star == 1) ||
								(var->precs && var->tr_star == 0))
			var->tr_zero = 0;
		var->lenght_agv = lenght((long)var->ival);
		if (var->ival == 0 && var->tr_point && var->precs == 0)
			var->lenght_agv = 0;
		var->precs = (var->precs > var->lenght_agv) ? var->precs -
			var->lenght_agv : 0;
		if (var->tr_negatife)
			var->lenght_agv++;
		var->width = (var->width > var->precs + var->lenght_agv) ? var->width
			- var->precs - var->lenght_agv : 0;
		specefier_d_print_sp_zr(var);
	}
	initial_to_zero(var);
	return (++frmt);
}

void		specefier_u_print_sp_zr(t_var *var)
{
	if (var->width && !var->tr_zero && !var->tr_minus)
		while (var->width-- > 0)
			ft_putchar_fd(' ', 1, var);
	if (var->tr_zero && var->tr_minus == 0)
		while (var->width-- > 0)
			ft_putchar_fd('0', 1, var);
	if ((!var->tr_zero && var->tr_minus == 0) || (var->tr_minus == 1))
		while (var->precs-- > 0)
			ft_putchar_fd('0', 1, var);
	if (var->lenght_agv)
		ft_put_u_nbr_fd(var->u_nbr, 1, var);
	if (var->tr_minus == 1)
		while (var->width-- > 0)
			ft_putchar_fd(' ', 1, var);
}

const char	*specefier_u(const char *frmt, t_var *var)
{
	if (*frmt == 'u')
	{
		var->u_nbr = va_arg(var->list_arguments, int);
		if ((var->precs >= 0 && var->tr_star == 1)
							|| (var->precs && var->tr_star == 0))
			var->tr_zero = 0;
		var->lenght_agv = lenght((long)var->u_nbr);
		if (var->u_nbr == 0 && var->tr_point && var->precs == 0)
			var->lenght_agv = 0;
		var->precs = (var->precs > var->lenght_agv) ? var->precs
			- var->lenght_agv : 0;
		var->width = (var->width > var->precs + var->lenght_agv) ? var->width
			- var->precs - var->lenght_agv : 0;
		specefier_u_print_sp_zr(var);
	}
	initial_to_zero(var);
	return (++frmt);
}
