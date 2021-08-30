/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:24:07 by zakdim            #+#    #+#             */
/*   Updated: 2020/01/18 18:21:23 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	lenght_hex(unsigned long int nbr)
{
	unsigned long long	base;
	unsigned long int	cpt;
	int					lenght;

	lenght = 0;
	base = 1;
	if (nbr == 0)
		lenght++;
	while ((nbr / base) > 0)
	{
		base *= 16;
		if ((base * 16) == 0)
			break ;
	}
	if ((base * 16) != 0)
		base /= 16;
	while (base > 0)
	{
		cpt = nbr / base;
		lenght++;
		nbr = nbr - (base * cpt);
		base /= 16;
	}
	return (lenght);
}

void	hex_minx(unsigned long long base, unsigned long long nbr, t_var *var)
{
	int		cpt;
	char	p;

	if ((base * 16) != 0)
		base /= 16;
	while (base > 0)
	{
		cpt = nbr / base;
		if (cpt >= 10)
			p = cpt + 87;
		else
			p = cpt + 48;
		ft_putchar_fd(p, 1, var);
		nbr = nbr - (base * cpt);
		base /= 16;
	}
}

void	hex_majx(unsigned long long base, unsigned long long nbr, t_var *var)
{
	int		cpt;
	char	p;

	if ((base * 16) != 0)
		base /= 16;
	while (base > 0)
	{
		cpt = nbr / base;
		if (cpt >= 10)
			p = cpt + 55;
		else
			p = cpt + 48;
		ft_putchar_fd(p, 1, var);
		nbr = nbr - (base * cpt);
		base /= 16;
	}
}

void	ft_hex(t_var *var, char c)
{
	unsigned long int nbr;
	unsigned long int base;

	nbr = (unsigned int)var->hex;
	if (c == 'p')
		nbr = (unsigned long)var->hex_adr;
	base = 1;
	if (nbr == 0)
		ft_putchar_fd('0', 1, var);
	while ((nbr / base) > 0)
	{
		base *= 16;
		if ((base * 16) == 0)
			break ;
	}
	if (c == 'X')
		hex_majx(base, nbr, var);
	else
		hex_minx(base, nbr, var);
}

void	ft_take_adress(unsigned long p, t_var *var)
{
	var->hex = (unsigned long)p;
	ft_puts("0x", var);
	ft_hex(var, 'p');
}
