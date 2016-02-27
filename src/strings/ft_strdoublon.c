/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdoublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 10:38:49 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/28 00:56:47 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

void		ft_strdoublon(char **str, char del)
{
	char	*swap;
	char	*remplace;

	if (*str)
	{
		swap = ft_strnew(3);
		remplace = ft_strnew(3);
		swap[0] = del;
		remplace[0] = del;
		swap[1] = del;
		remplace[1] = '\0';
		swap[2] = '\0';
		ft_strreplace(str, swap, remplace, -1);
		ft_strdel(&swap);
		ft_strdel(&remplace);
	}
}
