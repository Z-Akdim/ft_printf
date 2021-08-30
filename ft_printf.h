/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:01:08 by zakdim            #+#    #+#             */
/*   Updated: 2020/01/19 11:15:43 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
#	define FT_PRINTF_H
#	include "stdarg.h"
#	include "unistd.h"
#	include "stdio.h"

typedef	struct			s_var
{
	int					nbr_digits_flag;
	int					tr_minus;
	int					tr_zero;
	int					tr_star;
	int					tr_point;
	int					tr_null;
	int					tr_plus;
	int					tr_negatife;
	int					sp;
	int					space;
	int					prec;
	char				conversion;
	int					precs;
	int					width;
	char				*string;
	int					lenght_agv;
	int					ival;
	unsigned int		u_nbr;
	unsigned int		hex;
	unsigned long		hex_adr;
	va_list				list_arguments;
	long				nbr_return;
}						t_var;
int						count_char(long n);
char					*resume(long l_n, char *char_int);
int						ft_atoi(const char *str);
int						lenght(long nbr);
size_t					ft_lenght_string(char *str);
const char				*ft_check_specefier(const char *frmt, t_var *var);
const char				*specefier_p(const char *frmt, t_var *var);
const char				*specefier_hex_min_x(const char *frmt, t_var *var);
const char				*specefier_hex_maj_x(const char *frmt, t_var *var);
const char				*specefier_s(const char *frmt, t_var *var);
const char				*specefier_c(const char *frmt, t_var *var);
const char				*specefier_d_i(const char *frmt, t_var *var);
const char				*specefier_u(const char *frmt, t_var *var);
void					ft_putnbr_fd(int n, int fd, t_var *var);
void					ft_put_u_nbr_fd(unsigned int n, int fd, t_var *var);
void					ft_putchar_fd(const char c, int fd, t_var *var);
const char				*flag_point_print(const char *frmt, t_var *var);
const char				*ft_check_precision(const char *frmt, t_var *var);
const char				*ft_check_width(const char *frmt,
						t_var *var, int *width);
const char				*ft_puts(const char *frmt, t_var *var);
void					ft_take_adress(unsigned long int p, t_var *var);
const char				*format_check(const char *frmt, t_var *var);
size_t					lenght_hex(unsigned long int nbr);
void					hex_print(unsigned long long base,
						unsigned long long nbr);
void					ft_hex(t_var *var, char c);
char					*ft_putarg(char *frmt, t_var *var);
void					initial_to_zero(t_var *var);
int						ft_printf(const char *frmt, ...);

#	endif
