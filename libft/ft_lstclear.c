/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:30:21 by hprudhom          #+#    #+#             */
/*   Updated: 2021/04/15 10:06:25 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;

	current = *lst;
	temp = 0;
	while (current)
	{
		if (current->next)
			temp = current->next;
		else
			temp = 0;
		del(current->content);
		free(current);
		current = temp;
	}
	*lst = 0;
}
