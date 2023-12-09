/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakala <ttakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:18:34 by ttakala           #+#    #+#             */
/*   Updated: 2023/12/09 13:47:32 by ttakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list
	*create_new_node(void *(*f)(void *), void *content, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	head = create_new_node(f, lst->content, del);
	if (head == NULL)
		return (NULL);
	tail = head;
	lst = lst->next;
	while (lst)
	{
		tail->next = create_new_node(f, lst->content, del);
		if (tail->next == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		tail = tail->next;
		lst = lst->next;
	}
	return (head);
}

static t_list
	*create_new_node(void *(*f)(void *), void *content, void (*del)(void *))
{
	t_list	*new_node;
	void	*new_content;

	new_content = f(content);
	new_node = ft_lstnew(new_content);
	if (new_node == NULL)
		del(new_content);
	return (new_node);
}
