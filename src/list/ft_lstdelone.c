/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 07:09:50 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:38:02 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"
#include "../../includes/mem.h"

void		ft_lstdelone(t_lst **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	(*alst)->content = NULL;
	ft_memdel((void**)alst);
}
