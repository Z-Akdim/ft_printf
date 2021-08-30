/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:08:27 by zakdim            #+#    #+#             */
/*   Updated: 2020/01/18 18:21:28 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_char(long n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	count++;
	return (count);
}

int		lenght(long nbr)
{
	int i;

	i = 1;
	if (nbr < 0)
		nbr = -(nbr);
	while ((nbr = (nbr / 10)) > 0)
		i++;
	return (i);
}

size_t	ft_lenght_string(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_atoi(const char *str)
{
	int		i;
	long	ret;

	i = 0;
	ret = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = (ret * 10) + str[i] - '0';
		i++;
	}
	return (ret);
}

void	ft_putchar_fd(const char c, int fd, t_var *var)
{
	write(fd, &c, 1);
	var->nbr_return++;
}
