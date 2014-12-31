/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfusiondel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 10:31:51 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/28 10:31:51 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_strfusiondel(char **dst, char **src)
{
	int		size;

	size = BUFF_SIZE + 2;
	if (!(*src))
		*src = ft_strdup("");;
	if (!(*dst))
		*dst = ft_strdup("");
	size += ft_strlen(*src);
	size += ft_strlen(*dst);
	*dst = ft_strralloc(dst, size);
	ft_putstr(*dst);
	ft_strcpy(*dst, *src);
	ft_strdel(src);
}
