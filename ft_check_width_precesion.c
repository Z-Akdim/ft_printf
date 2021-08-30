/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width_precesion.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:22:26 by zakdim            #+#    #+#             */
/*   Updated: 2020/01/18 18:21:11 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_check_precision(const char *frmt, t_var *var)
{
	if (*frmt == '.')
	{
		var->tr_point = 1;
		frmt++;
	}
	if (*frmt == '*')
	{
		var->tr_star = 1;
		var->precs = va_arg(var->list_arguments, int);
		frmt++;
	}
	else
	{
		var->precs = ft_atoi(frmt);
		while (*(frmt) >= '0' && *(frmt) <= '9')
			frmt++;
	}
	frmt = ft_check_specefier(frmt, var);
	return (frmt);
}

const char	*ft_check_width(const char *frmt, t_var *var, int *width)
{
	if (var->tr_star == 1)
	{
		var->width = va_arg(var->list_arguments, int);
		if (var->width < 0)
		{
			var->width *= -1;
			var->tr_minus = 1;
		}
		var->tr_star = 0;
	}
	else
	{
		var->width = ft_atoi(frmt);
		if (*frmt >= '0' && *frmt <= '9')
			var->nbr_digits_flag = lenght(*width);
		if (var->width == 0 && *frmt == '%')
			var->nbr_digits_flag = 0;
	}
	if ((*(frmt += var->nbr_digits_flag)) == '.')
		frmt = ft_check_precision(frmt, var);
	else
		frmt = ft_check_specefier(frmt, var);
	return (frmt);
}
