/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 07:16:34 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/29 07:16:34 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	free_list(void *data, size_t data_size)
{
	(void)data_size;
	ft_memdel((void**)&data);
}

t_lst		*ft_lstmap(t_lst *lst, t_lst *(*f)(t_lst *elem))
{
	t_lst *new_elem;
	t_lst *new_lst;

	new_elem = NULL;
	if (!(new_lst = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	while (lst)
	{
		new_elem = f(lst);
		if (!new_elem)
		{
			ft_lstdel(&new_lst, free_list);
			return (NULL);
		}
		else
		{
			ft_lstadd(&new_elem, new_lst);
			lst = lst->next;
		}
	}
	return (new_lst);
}
