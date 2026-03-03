/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:27:52 by opaulman          #+#    #+#             */
/*   Updated: 2025/07/03 20:50:07 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new || !*lst)
	{
		if (!*lst)
			*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	if (!last)
		return ;
	last->next = new;
}
