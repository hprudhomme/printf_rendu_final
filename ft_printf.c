/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:52:36 by hprudhom          #+#    #+#             */
/*   Updated: 2021/04/26 13:13:29 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	flags.hashtag = 0;
	return (flags);
}

int	ft_flag_parse(const char *save, int i, t_flags *flags, va_list args)
{
	while (save[i])
	{	
		if (!ft_isdigit(save[i]) && !ft_type(save[i]) && !ft_flag(save[i]))
			break ;
		if (save[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (save[i] == '.')
			i = ft_flag_dot(save, i, flags, args);
		if (save[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (save[i] == '*')
			*flags = ft_flag_width(args, *flags);
		if (save[i] == '#')
			flags->hashtag = 1;
		if (ft_isdigit(save[i]))
			*flags = ft_flag_digit(save[i], *flags);
		if (ft_type(save[i]))
		{
			flags->type = save[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	ft_parse_input(const char *save, va_list args)
{	
	int		char_count;
	int		i;
	t_flags	flags;

	i = 0;
	char_count = 0;
	while (1)
	{
		flags = ft_init_flags();
		if (!save[i])
			break ;
		else if (save[i] == '%' && save[i + 1])
		{
			i = ft_flag_parse(save, ++i, &flags, args);
			if (ft_type(save[i]))
				char_count += ft_treatment((char)flags.type, flags, args);
			else if (save[i])
				char_count += ft_putchar(save[i]);
		}
		else if (save[i] != '%')
			char_count += ft_putchar(save[i]);
		i++;
	}
	return (char_count);
}

int	ft_printf(const char *input, ...)
{
	const char		*save;
	va_list			args;
	int				char_count;

	char_count = 0;
	save = ft_strdup(input);
	va_start(args, input);
	char_count += ft_parse_input(save, args);
	va_end(args);
	free((char *)save);
	return (char_count);
}
