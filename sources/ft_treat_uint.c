/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:07:06 by hprudhom          #+#    #+#             */
/*   Updated: 2021/04/14 13:44:11 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_put_arg(char *str_u_int, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.dot >= 0)
		char_count += ft_treat_width(flags.dot - 1,
				ft_strlen(str_u_int) - 1, 1);
	char_count += ft_putstr(str_u_int, ft_strlen(str_u_int));
	return (char_count);
}

static int	ft_first_part(char *str_u_int, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_put_arg(str_u_int, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str_u_int))
		flags.dot = ft_strlen(str_u_int);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_treat_width(flags.width, 0, 0);
	}
	else
		char_count += ft_treat_width(flags.width,
				ft_strlen(str_u_int), flags.zero);
	if (flags.minus == 0)
		char_count += ft_put_arg(str_u_int, flags);
	return (char_count);
}

int	ft_treat_uint(unsigned int unsi, t_flags flags)
{
	char	*str_u_int;
	int		char_count;

	char_count = 0;
	unsi = (unsigned int)(4294967295 + 1
			+ unsi);
	if (flags.dot == 0 && unsi == 0)
	{
		char_count += ft_treat_width(flags.width, 0, 0);
		return (char_count);
	}
	str_u_int = ft_u_itoa(unsi);
	char_count += ft_first_part(str_u_int, flags);
	free(str_u_int);
	return (char_count);
}
