/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 07:04:43 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/29 07:04:43 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*list;

	list = *alst;
	*alst = new;
	new->next = list;
}
