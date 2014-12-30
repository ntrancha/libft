/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 07:15:30 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/29 07:15:30 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstiter(t_lst *lst, void (*f)(t_lst *elem))
{
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
