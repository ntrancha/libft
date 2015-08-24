/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 07:04:43 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:37:36 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"

void		ft_lstadd(t_lst **alst, t_lst *new)
{
	t_lst	*list;

	list = *alst;
	*alst = new;
	new->next = list;
}
