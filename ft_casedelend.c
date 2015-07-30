/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casedelend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 22:06:23 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/30 22:08:22 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_case		*ft_casedelend(t_case *cases)
{
	t_case	*jump;

	if (!cases)
		return (NULL);
	jump = cases;
	while (jump->next)
			jump = jump->next;
	return (ft_casedel(cases, jump));
}
