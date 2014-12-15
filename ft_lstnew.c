/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c										:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 09:55:56 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/16 09:55:56 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;
	void		*cpy;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		cpy = ft_memalloc(content_size);
		cpy = ft_memcpy(cpy, content, content_size);
		new->content = cpy;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
