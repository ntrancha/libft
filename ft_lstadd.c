/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c									:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 10:14:13 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/16 10:14:13 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*prev;
	
	prev = *alst;
	prev->next = *alst;
	*alst = new;
}
