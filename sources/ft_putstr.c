/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:04:32 by hprudhom          #+#    #+#             */
/*   Updated: 2021/04/14 13:19:31 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr(char *str, int length)
{
	int	char_count;

	char_count = 0;
	while (str[char_count] && char_count < length)
		ft_putchar(str[char_count++]);
	return (char_count);
}
