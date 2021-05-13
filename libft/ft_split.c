/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:05:59 by hprudhom          #+#    #+#             */
/*   Updated: 2020/12/18 16:22:33 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static char	**ft_second_malloc(char **tab, char const *s, char c)
{
	int	i;
	int	x;
	int	count;

	x = 0;
	i = 0;
	count = 0;
	while (s[x])
	{
		while (s[x] == c)
			x++;
		count = 0;
		while (s[x++] != c && s[x])
			count++;
		if (count != 0)
		{
			tab[i] = malloc(sizeof(char) * (count + 1));
			if (!tab[i])
				return (NULL);
			i++;
		}
	}
	return (tab);
}

static char	**ft_first_malloc(char **tab, char const *s, char c)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	while (s[x])
	{
		while (s[x] == c)
			x++;
		while (s[x] != c && s[x])
		{
			if (s[x - 1] == c || x == 0)
				count++;
			x++;
		}
	}
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	return (tab);
}

static char	**ft_spliting(char **tab, char const *s, char c)
{
	int		x;
	int		ligne;
	int		col;

	ligne = 0;
	col = 0;
	x = 0;
	while (s[x])
	{
		while (s[x] == c)
			x++;
		col = 0;
		while (s[x] != c && s[x])
		{
			tab[ligne][col++] = s[x++];
			if (s[x] == c || !(s[x]))
			{
				tab[ligne][col] = '\0';
				ligne++;
			}
		}
	}
	tab[ligne] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (0);
	tab = NULL;
	tab = ft_first_malloc(tab, s, c);
	if (!tab)
		return (NULL);
	tab = ft_second_malloc(tab, s, c);
	if (!tab)
		return (NULL);
	tab = ft_spliting(tab, s, c);
	return (tab);
}
