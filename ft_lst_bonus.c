/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:10:08 by jlorber           #+#    #+#             */
/*   Updated: 2022/03/15 12:18:04 by jlorber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(new));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			temp = ft_lstlast(*lst);
			temp->next = new;
		}
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next;

	if (lst && *lst)
	{
		temp = *lst;
		while (temp)
		{
			next = temp->next;
			ft_lstdelone(temp, del);
			temp = next;
		}
	}
	*lst = NULL;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;

	new = NULL;
	if (lst && f)
	{
		while (lst)
		{
			ft_lstadd_back(&new, ft_lstnew(f(lst->content)));
			if (!new)
				ft_lstclear(&new, del);
			lst = lst->next;
		}
	}
	return (new);
}
