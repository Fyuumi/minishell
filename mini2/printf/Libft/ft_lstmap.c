/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:20:50 by opaulman          #+#    #+#             */
/*   Updated: 2025/07/03 21:13:10 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*tem(t_list *lst, void *(*f)(void *), void (*del)(void *),
		t_list *list)
{
	void	*content;

	content = f(lst->content);
	if (!content)
	{
		ft_lstclear(&list, del);
		return (NULL);
	}
	return (content);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*list;
	void	*temp;

	if (!lst || !del || !f)
		return (NULL);
	list = NULL;
	while (lst)
	{
		temp = tem(lst, f, del, list);
		if (!temp)
			return (NULL);
		new = ft_lstnew(temp);
		if (!new)
		{
			del(temp);
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, new);
		lst = lst->next;
	}
	return (list);
}
