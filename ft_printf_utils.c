/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:08:27 by zakdim            #+#    #+#             */
/*   Updated: 2020/01/19 16:49:22 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_puts(const char *frmt, t_var *var)
{
	while (*frmt && *frmt != '%')
	{
		ft_putchar_fd(*frmt, 1, var);
		frmt++;
	}
	return (frmt);
}

char		*ft_putarg(char *frmt, t_var *var)
{
	while (*frmt && var->precs--)
	{
		ft_putchar_fd(*frmt, 1, var);
		frmt++;
	}
	return (frmt);
}

void		ft_putnbr_fd(int n, int fd, t_var *var)
{
	int		div;
	long	l_n;

	l_n = (long)n;
	div = 1;
	if (l_n < 0)
		l_n *= -1;
	while (l_n / div > 9)
		div *= 10;
	while (div > 9)
	{
		ft_putchar_fd(l_n / div + 48, fd, var);
		l_n %= div;
		div /= 10;
	}
	ft_putchar_fd(l_n + 48, fd, var);
	var->tr_plus = 0;
}

void		ft_put_u_nbr_fd(unsigned int n, int fd, t_var *var)
{
	int		div;
	long	l_n;

	l_n = (long)n;
	div = 1;
	if (l_n < 0)
		l_n *= -1;
	while (l_n / div > 9)
		div *= 10;
	while (div > 9)
	{
		ft_putchar_fd(l_n / div + 48, fd, var);
		l_n %= div;
		div /= 10;
	}
	ft_putchar_fd(l_n + 48, fd, var);
	var->tr_plus = 0;
}

void		initial_to_zero(t_var *var)
{
	var->sp = 0;
	var->lenght_agv = 0;
	var->tr_minus = 0;
	var->tr_star = 0;
	var->tr_point = 0;
	var->width = 0;
	var->precs = 0;
	var->tr_null = 0;
	var->ival = 0;
	var->tr_zero = 0;
	var->tr_negatife = 0;
	var->tr_plus = 0;
	var->conversion = 0;
	var->hex = 0;
	var->hex_adr = 0;
	var->prec = 0;
	var->string = "";
	var->nbr_digits_flag = 0;
}
