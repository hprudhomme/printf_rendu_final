/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:01:59 by hprudhom          #+#    #+#             */
/*   Updated: 2021/04/20 16:44:23 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_in_put_part_int(char *i_to_str, int save_i, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if ((save_i < 0 && flags.dot >= 0 ) || (save_i == -2147483648
			&& flags.zero == 0))
		ft_putchar('-');
	if (flags.dot >= 0)
		char_count += ft_treat_width(flags.dot - 1, ft_strlen(i_to_str) - 1, 1);
	char_count += ft_putstr(i_to_str, ft_strlen(i_to_str));
	return (char_count);
}

static int	ft_put_part_int(char *i_to_str, int save_i, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (save_i == -2147483648 && flags.dot <= -1 && flags.zero == 0)
	{
		char_count++;
		flags.width--;
	}
	if (flags.minus == 1)
		char_count += ft_in_put_part_int(i_to_str, save_i, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(i_to_str))
		flags.dot = ft_strlen(i_to_str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_treat_width(flags.width, 0, 0);
	}
	else
		char_count += ft_treat_width(flags.width,
				ft_strlen(i_to_str), flags.zero);
	if (flags.minus == 0)
		char_count += ft_in_put_part_int(i_to_str, save_i, flags);
	return (char_count);
}

int	ft_treat_int(int i, t_flags flags)
{	
	char	*i_to_str;
	int		save_i;
	int		char_count;

	save_i = i;
	char_count = 0;
	if (flags.dot == 0 && i == 0)
	{	
		char_count += ft_treat_width(flags.width, 0, 0);
		return (char_count);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot <= -1)
			ft_putstr("-", 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		char_count++;
	}
	i_to_str = ft_itoa(i);
	char_count += ft_put_part_int(i_to_str, save_i, flags);
	free(i_to_str);
	return (char_count);
}
