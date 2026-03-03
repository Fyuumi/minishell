/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:26:39 by opaulman          #+#    #+#             */
/*   Updated: 2025/07/03 17:41:29 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;
	int		i;

	if (!lst)
		return (NULL);
	i = ft_lstsize(lst);
	last = lst;
	while (i > 1)
	{
		last = last->next;
		i--;
	}
	return (last);
}
