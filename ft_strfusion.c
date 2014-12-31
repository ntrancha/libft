/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfusion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 10:31:51 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/28 10:31:51 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_strfusion(char **dst, char **src)
{
	char	*tmp;

	tmp = ft_strjoin(*dst, *src);
	ft_strdel(dst);
	*dst = tmp;
}
