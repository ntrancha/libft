/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 14:13:14 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/16 00:27:57 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"
#include "../../includes/mem.h"

void		ft_tabstrdel(char ***str)
{
	int		index;

	index = 0;
	while (*str[index])
	{
		ft_strdel(&((*str)[index]));
		index++;
	}
	ft_memdel((void**)str);
}
