/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:08:57 by hprudhom          #+#    #+#             */
/*   Updated: 2021/04/14 14:22:12 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_put_arg(char *hexa, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.dot >= 0)
		char_count += ft_treat_width(flags.dot - 1, ft_strlen(hexa) - 1, 1);
	char_count += ft_putstr(hexa, ft_strlen(hexa));
	return (char_count);
}

static int	ft_bonus_part(t_flags *flags)
{	
	int	char_count;

	char_count = 0;
	if (flags->type == 'x')
		char_count += ft_putstr("0x", 2);
	if (flags->type == 'X')
		char_count += ft_putstr("0X", 2);
	flags->width -= 2;
	return (char_count);
}

static int	ft_put_first_part(char *hexa, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.hashtag == 1 && hexa[0] != '0')
		char_count += ft_bonus_part(&flags);
	if (flags.minus == 1)
		char_count += ft_put_arg(hexa, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hexa))
		flags.dot = ft_strlen(hexa);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_treat_width(flags.width, 0, 0);
	}
	else
		char_count += ft_treat_width(flags.width, ft_strlen(hexa), flags.zero);
	if (flags.minus == 0)
		char_count += ft_put_arg(hexa, flags);
	return (char_count);
}

int	ft_treat_hexa(unsigned int ui, int lower, t_flags flags)
{
	char	*hexa;
	int		char_count;

	char_count = 0;
	ui = (unsigned int)(4294967295 + 1
			+ ui);
	if (flags.dot == 0 && ui == 0)
	{
		char_count += ft_treat_width(flags.width, 0, 0);
		return (char_count);
	}
	hexa = ft_u_dec_to_hexa((unsigned long long)ui, 16);
	if (lower == 1)
		hexa = ft_str_tolower(hexa);
	char_count += ft_put_first_part(hexa, flags);
	free(hexa);
	return (char_count);
}
