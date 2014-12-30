/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listcreate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 05:42:03 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/30 05:42:03 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_listcreate(void)
{
	t_list	*list;

	list = ft_memalloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->size = 0;
	list->start = NULL;
	list->end = NULL;
	return (list);
}
