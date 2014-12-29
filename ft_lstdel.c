/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 07:07:53 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/29 07:07:53 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next_elem;

	while (*alst)
	{
		next_elem = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = next_elem;
	}
	*alst = NULL;
}
