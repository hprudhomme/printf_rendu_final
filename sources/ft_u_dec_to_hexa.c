/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_dec_to_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:07:59 by hprudhom          #+#    #+#             */
/*   Updated: 2021/04/14 14:25:25 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*treat_base(unsigned long long dec_save, int base,
char *hexa, int count)
{
	while (dec_save != 0)
	{
		if ((dec_save % base) < 10)
			hexa[count - 1] = (dec_save % base) + 48;
		else
			hexa[count - 1] = (dec_save % base) + 55;
		dec_save /= base;
		count--;
	}
	return (hexa);
}

char	*ft_u_dec_to_hexa(unsigned long long dec, int base)
{
	char				*hexa;
	unsigned long long	dec_save;
	int					count;

	hexa = 0;
	count = 0;
	dec_save = dec;
	if (dec == 0)
		return (ft_strdup("0"));
	while (dec != 0)
	{
		dec /= base;
		count++;
	}
	hexa = malloc(sizeof(char) * (count + 1));
	if (!hexa)
		return (0);
	hexa[count] = '\0';
	hexa = treat_base(dec_save, base, hexa, count);
	return (hexa);
}
