/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfusion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 10:31:51 by ntrancha          #+#    #+#             */
/*   Updated: 2015/10/05 18:20:25 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

void		ft_strfusion(char **dst, char **src)
{
	char	*tmp;

	tmp = ft_strjoin(*dst, *src);
	ft_strdel(dst);
	*dst = tmp;
}
