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
	ft_strfusion(dst, src);
	ft_strdel(src);
}
