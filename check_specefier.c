/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specefier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:50:16 by zakdim            #+#    #+#             */
/*   Updated: 2020/01/18 18:20:57 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*flag_percent(const char *frmt, t_var *var)
{
	if (*frmt == '%')
	{
		var->lenght_agv = 1;
		var->width = var->width - 1;
		if (var->tr_minus)
		{
			ft_putchar_fd('%', 1, var);
			while (var->width-- > 0)
				ft_putchar_fd(' ', 1, var);
		}
		else
		{
			if (var->tr_zero == 1)
				while (var->width-- > 0)
					ft_putchar_fd('0', 1, var);
			else
				while (var->width-- > 0)
					ft_putchar_fd(' ', 1, var);
			ft_putchar_fd('%', 1, var);
		}
		frmt++;
	}
	initial_to_zero(var);
	return (frmt);
}

const char	*ft_check_specefier(const char *frmt, t_var *var)
{
	if (*frmt == 's')
		frmt = specefier_s(frmt, var);
	else if (*frmt == 'c')
		frmt = specefier_c(frmt, var);
	else if (*frmt == 'd' || *frmt == 'i')
		frmt = specefier_d_i(frmt, var);
	else if (*(frmt) == 'x')
		frmt = specefier_hex_min_x(frmt, var);
	else if (*(frmt) == 'X')
		frmt = specefier_hex_maj_x(frmt, var);
	else if (*(frmt) == 'p')
		frmt = specefier_p(frmt, var);
	else if (*(frmt) == 'u')
		frmt = specefier_u(frmt, var);
	else if (*frmt == 'p')
		ft_take_adress(var->hex_adr, var);
	else if (*frmt == '.')
		frmt = ft_check_precision(frmt, var);
	else if (*frmt == '%')
		frmt = flag_percent(frmt, var);
	return (frmt);
}
